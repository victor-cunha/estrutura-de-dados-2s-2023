#include <stdio.h>
#include <stdio.h>
#include "bubble_sort.h"

void bubble_sort(int aar[], int n)
{
    int tmp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (aar[j] > aar[j + 1])
            {
                tmp = aar[j];
                aar[j] = aar[j + 1];
                aar[j + 1] = tmp;
            }
        }
    }
}