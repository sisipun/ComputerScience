#include "swap.h"

void swap(char *xp, char *yp)
{
    char tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}