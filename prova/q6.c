//Q6 - Distância de edição é uma medida para indicar o quão próximas são duas strings.
//Esta medida é calculada a partir do número mínimo de operações necessárias para transformar uma string na outra.
//As operações válidas são: inserção, deleção ou substituição de um caractere.
//Faça um programa que leia duas cadeias de caracteres e, em seguida,
//o programa deve retornar o número de operações necessárias para transformar a primeira cadeia na segunda.
//A solução proposta deve implementar o algoritmo de Levenshtein. (3,0 pontos) *
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int levenshtein(char *, char *);
char *getStrings();

int main()
{
    char *s1;
    char *s2;

    s1 = getStrings();
    s2 = getStrings();

    int dist = levenshtein(s1, s2);

    printf("Strings:\n");
    puts(s1);
    puts(s2);
    printf("Distancia de edição: %d\n", dist);

    free(s1);
    free(s2);
}

char *getStrings()
{
    char *str = NULL;
    int ch;

    size_t size = 0, len = 0;

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (len + 1 >= size)
        {
            size = size * 2 + 1;
            str = realloc(str, sizeof(char) * size);
        }
        str[len++] = ch;
    }
    str[len] = '\0';
    return str;
}

int levenshtein(char *s1, char *s2)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int mat[len_s1][len_s2];

    for (size_t i = 0; i < len_s1; i++)
    {
        mat[i][0] = i;
    }

    for (size_t i = 0; i < len_s2; i++)
    {
        mat[0][i] = i;
    }

    for (size_t i = 1; i < len_s1; i++)
    {
        for (size_t j = 1; j < len_s2; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1];
            }
            else
            {
                int minimum;

                int delete = mat[i - 1][j] + 1;
                int insert = mat[i][j - 1] + 1;
                int substitute = mat[i - 1][j - 1] + 1;

                minimum = delete;

                if (insert < minimum)
                {
                    minimum = insert;
                }
                if (substitute < minimum)
                {
                    minimum = substitute;
                }

                mat[i][j] = minimum;
            }
    }
    return mat[len_s1 - 1][len_s2 - 1];
}
