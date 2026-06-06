#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int contar_letras(string texto);
int contar_palavras(string texto);
int contar_frases(string texto);

int main(void)
{
    string texto = get_string("Text: ");
    int letras = contar_letras(texto);
    int palavras = contar_palavras(texto);
    int frases = contar_frases(texto);

    float L = (letras / (float) palavras) * 100;
    float S = (frases / (float) palavras) * 100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int nivel = round(indice);

    if (nivel >= 16)
        printf("Grade 16+\n");
    else if (nivel < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", nivel);
}

int contar_letras(string texto)
{
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++)
        if (isalpha(texto[i]))
            count++;
    return count;
}

int contar_palavras(string texto)
{
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++)
        if (texto[i] == ' ')
            count++;
    return count + 1;
}

int contar_frases(string texto)
{
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++)
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
            count++;
    return count;
}
