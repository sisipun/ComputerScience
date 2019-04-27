#include "selection.h"
#include "../utlis/swap.h"

void selection_sort(void *base, const size_t num, const size_t size, int(comparator)(const void *, const void *))
{
    for (int i = 0; i < num * size; i += size)
    {
        int min = i;
        for (int j = i + size; j < num * size; j += size)
        {
            if (comparator(base + j, base + min) < 0)
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap((char *)(base + min), (char *)(base + i));
        }
    }
}