#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Verificar número correto de argumentos
    if (argc != 2)
    {
        printf("Uso: ./recover arquivo\n");
        return 1;
    }

    // Abrir arquivo de entrada
    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // Buffer para armazenar blocos de 512 bytes
    uint8_t buffer[512];

    // Contador de imagens encontradas
    int contador = 0;

    // Ponteiro para o arquivo de saída
    FILE *saida = NULL;

    // Nome do arquivo (8 caracteres incluem NUL)
    char nome_arquivo[8];

    // Ler blocos de 512 bytes do arquivo
    while (fread(buffer, 1, 512, entrada) == 512)
    {
        // Verificar assinatura de início de JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Fechar arquivo anterior se existir
            if (saida != NULL)
            {
                fclose(saida);
            }

            // Criar novo nome de arquivo
            sprintf(nome_arquivo, "%03i.jpg", contador);

            // Abrir novo arquivo para escrita
            saida = fopen(nome_arquivo, "w");
            contador++;
        }

        // Escrever dados no arquivo se estiver aberto
        if (saida != NULL)
        {
            fwrite(buffer, 1, 512, saida);
        }
    }

    // Fechar últimos arquivos abertos
    if (saida != NULL)
    {
        fclose(saida);
    }
    fclose(entrada);

    return 0;
}
