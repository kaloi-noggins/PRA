#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *v;
    scanf("%d", &n);
    v = malloc(sizeof(int) * n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", v[i]);
    }

    
}