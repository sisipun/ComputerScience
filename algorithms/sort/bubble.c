#include "bubble.h"
#include "../utlis/swap.h"

void bubble_sort(void *base, const size_t num, const size_t size, int(comparator)(const void *, const void *))
{
    for (int i = num; i > 0; i--)
    {
        for (int j = size; j < i * size; j += size)
        {
            if (comparator(base + (j - size), base + j) > 0)
            {
                for (int k = 0; k < size; k++)
                {
                    swap((char *)(base + (j - size) + k), (char *)(base + j + k));
                }
            }
        }
    }
}