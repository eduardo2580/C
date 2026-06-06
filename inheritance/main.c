// Simula a herança genética do tipo sanguíneo

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cada pessoa tem dois pais e dois alelos
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Cria uma nova família com três gerações
    person *p = create_family(GENERATIONS);

    // Imprime a árvore genealógica
    print_family(p, 0);

    // Libera a memória alocada
    free_family(p);
}

// Cria um novo indivíduo com um número específico de gerações
person *create_family(int generations)
{
    // Aloca memória para uma nova pessoa
    person *nova_pessoa = malloc(sizeof(person));
    if (nova_pessoa == NULL)
    {
        return NULL;
    }

    // Se ainda há gerações para criar
    if (generations > 1)
    {
        // Cria pais recursivamente
        person *pai0 = create_family(generations - 1);
        person *pai1 = create_family(generations - 1);

        // Define os pais da nova pessoa
        nova_pessoa->parents[0] = pai0;
        nova_pessoa->parents[1] = pai1;

        // Herda alelos dos pais aleatoriamente
        nova_pessoa->alleles[0] = pai0->alleles[rand() % 2];
        nova_pessoa->alleles[1] = pai1->alleles[rand() % 2];
    }
    else // Geração mais antiga (sem pais)
    {
        nova_pessoa->parents[0] = NULL;
        nova_pessoa->parents[1] = NULL;

        // Gera alelos aleatórios
        nova_pessoa->alleles[0] = random_allele();
        nova_pessoa->alleles[1] = random_allele();
    }

    return nova_pessoa;
}

// Libera a memória da família recursivamente
void free_family(person *p)
{
    // Caso base: pessoa não existe
    if (p == NULL)
    {
        return;
    }

    // Libera os pais primeiro
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Libera a pessoa atual
    free(p);
}

// Imprime a árvore genealógica
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Imprime indentação
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Imprime informações da pessoa
    if (generation == 0)
    {
        printf("Filho (Geração %d): tipo %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Pai (Geração %d): tipo %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Bis-");
        }
        printf("Avô (Geração %d): tipo %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Imprime os pais recursivamente
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Gera um alelo aleatório (A, B ou O)
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
