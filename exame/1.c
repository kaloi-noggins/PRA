#include <stdio.h>
#include <stdlib.h>

struct cliente
{
    char nome;
    int cpf;
    char ciadade[50];
    int celular;
} Cliente;

int pesquisa_sequencial(int key, int *vec, int tamanho);
int pesquisa_sentinela(int key, int *vec, int tamanho);

int main()
{
    int tamanho;
    printf("tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vec;
    vec = malloc(sizeof(int) * tamanho);

    for (size_t i = 0; i < tamanho; i++)
    {
        scanf("%d", &vec[i]);
    }

    int key;
    printf("chave: ");
    scanf("%d", &key);

    int resultado;
    resultado = pesquisa_sequencial(key, vec, tamanho);

    printf("pesquisa squencial\n");
    printf("posição da chave no vetor\n(-1 -> não encontrado)\n %d\n", resultado);

    resultado = pesquisa_sentinela(key, vec, tamanho);

    printf("pesquisa sentinela\n");
    printf("posição da chave no vetor\n(-1 -> não encontrado)\n %d\n", resultado);
    return 0;
}

int pesquisa_sequencial(int key, int *vec, int tamanho)
{
    for (size_t i = 0; i < tamanho; i++)
    {
        if (vec[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int pesquisa_sentinela(int key, int *vec, int tamanho)
{
    int i = 0;
    vec[tamanho] = key;

    while (vec[i] != key)
    {
        i++;
    }

    if (i < tamanho)
    {
        return i;
    }

    return -1;
}