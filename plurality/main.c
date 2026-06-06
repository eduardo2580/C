#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos permitidos
#define MAX 9

// Estrutura para representar um candidato
typedef struct
{
    string name;
    int votes;
} candidate;

// Array de candidatos
candidate candidates[MAX];
int candidate_count;

// Protótipos das funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verificação de uso correto do programa
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    // Registro inicial dos candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Configuração inicial dos candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Obtenção do número de eleitores
    int voter_count = get_int("Number of voters: ");

    // Processamento de cada voto
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifica se o voto é válido e registra
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Exibe o vencedor
    print_winner();
}

// Função para registrar um voto válido
bool vote(string name)
{
    // Percorre a lista de candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Compara nomes
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Função para determinar e exibir o vencedor
void print_winner(void)
{
    int max_votes = 0;

    // Encontra o número máximo de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprime todos os candidatos com votos máximos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
