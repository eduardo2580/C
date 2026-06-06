#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Pontuações correspondentes a cada letra do alfabeto
int PONTUACOES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Protótipo da função para calcular a pontuação
int calcular_pontuacao(string palavra);

int main(void)
{
    // Solicitar as palavras dos jogadores
    string palavra1 = get_string("Player 1: ");
    string palavra2 = get_string("Player 2: ");

    // Calcular as pontuações de cada palavra
    int pontuacao1 = calcular_pontuacao(palavra1);
    int pontuacao2 = calcular_pontuacao(palavra2);



    // Determinar e exibir o resultado
    if (pontuacao1 > pontuacao2)
    {
        printf("Player 1 wins!\n");
    }
    else if (pontuacao1 < pontuacao2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Função para calcular a pontuação de uma palavra
int calcular_pontuacao(string palavra)
{
    int total = 0;
    int comprimento = strlen(palavra);

    for (int i = 0; i < comprimento; i++)
    {
        char letra = palavra[i];
        if (isupper(letra))
        {
            // Adicionar pontos para letra maiúscula
            total += PONTUACOES[letra - 'A'];
        }
        else if (islower(letra))
        {
            // Adicionar pontos para letra minúscula
            total += PONTUACOES[letra - 'a'];
        }
        // Caracteres não alfabéticos são ignorados
    }
    return total;
}
