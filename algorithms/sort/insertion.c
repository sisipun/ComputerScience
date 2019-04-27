#include "insertion.h"
#include "../utlis/swap.h"

void insertion_sort(void *base, const size_t num, const size_t size, int(comparator)(const void *, const void *))
{
    for (int i = size; i < num * size; i += size)
    {
        int j = i;
        while (comparator(base + j, base + (j - size)) < 0 && j > 0)
        {
            for (int k = 0; k < size; k++)
            {
                swap((char *)(base + (j - size) + k), (char *)(base + j + k));
            }
            j -= size;
        }
    }
}