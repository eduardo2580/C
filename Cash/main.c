#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int centavos;
    do
    {
        centavos = get_int("Troco devido: ");
    }
    while (centavos < 0);

    int moedas_25 = centavos / 25;
    centavos %= 25;

    int moedas_10 = centavos / 10;
    centavos %= 10;

    int moedas_5 = centavos / 5;
    centavos %= 5;

    int moedas_1 = centavos;

    int total = moedas_25 + moedas_10 + moedas_5 + moedas_1;
    printf("%d\n", total);
}
