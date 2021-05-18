//Q5 - Dado um conjunto de N números inteiros representando o tamanho de luvas, 
//faça um programa para contar o máximo possível de pares de luvas existentes no conjunto. 
//Note que uma luva só pode ser par de outra luva do mesmo tamanho e só pode fazer parte de um único par. 
//Exemplo: entrada = {6, 5, 2, 3, 5, 2, 2, 1}, saída = 2 pares (tamanho 5 e tamanho 2). (3,0 pontos) *
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);
    int *vet = malloc(sizeof(int) * size);
    int pares = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d",vet+i);
    }

    for (size_t i = 0; i < size; i++)
    {
        if (vet[i] != -1)
        {
            int atual = vet[i];
            for (size_t j = i; j < size; j++)
            {
                if (j++ <= size)
                {
                    if (vet[j++] == atual && vet[j++] != -1)
                    {
                        pares++;
                        vet[i] = -1;
                        vet[j] = -1;
                        break;
                    }
                }
            }
        }
    }
    printf("Pares: %d\n", pares);
}