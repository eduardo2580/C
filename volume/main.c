#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int TAMANHO_CABECALHO = 44;

int main(int argc, char *argv[])
{
    // Verifica os argumentos da linha de comando
    if (argc != 4)
    {
        printf("Uso: ./volume entrada.wav saida.wav fator\n");
        return 1;
    }

    // Abre os arquivos e determina o fator de escala
    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    FILE *saida = fopen(argv[2], "w");
    if (saida == NULL)
    {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }

    float fator = atof(argv[3]);

    // Copia o cabeçalho do arquivo de entrada para o de saída
    uint8_t cabecalho[TAMANHO_CABECALHO];
    fread(cabecalho, TAMANHO_CABECALHO, 1, entrada);
    fwrite(cabecalho, TAMANHO_CABECALHO, 1, saida);

    // Processa as amostras de áudio
    int16_t amostra;
    while (fread(&amostra, sizeof(int16_t), 1, entrada))
    {
        // Ajusta o volume da amostra
        amostra *= fator;

        // Escreve a amostra ajustada no arquivo de saída
        fwrite(&amostra, sizeof(int16_t), 1, saida);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}
