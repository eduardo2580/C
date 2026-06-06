#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verifica se há exatamente um argumento de linha de comando
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Valida se a chave contém apenas dígitos
    string chave_str = argv[1];
    for (int i = 0; i < strlen(chave_str); i++)
    {
        if (!isdigit(chave_str[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converte a chave para inteiro e ajusta para o intervalo 0-25
    int chave = atoi(chave_str) % 26;

    // Solicita o texto plano ao usuário
    string texto_plano = get_string("plaintext:  ");

    // Processa cada caractere e imprime o texto cifrado
    printf("ciphertext: ");
    for (int i = 0; texto_plano[i] != '\0'; i++)
    {
        char caractere = texto_plano[i];
        if (isalpha(caractere))
        {
            char base = isupper(caractere) ? 'A' : 'a';
            caractere = (caractere - base + chave) % 26 + base;
        }
        printf("%c", caractere);
    }
    printf("\n");

    return 0;
}
