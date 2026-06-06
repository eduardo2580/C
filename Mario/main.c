#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int altura;
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 1);

    for (int linha = 0; linha < altura; linha++)
    {
        // Imprimir espaços para alinhamento à direita
        for (int espaco = 0; espaco < altura - linha - 1; espaco++)
        {
            printf(" ");
        }

        // Imprimir as cerquilhas da pirâmide
        for (int cerquilha = 0; cerquilha < linha + 1; cerquilha++)
        {
            printf("#");
        }
        printf("\n");
    }
}
