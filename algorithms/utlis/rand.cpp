#include "rand.h"

unsigned long int seed = 1;

unsigned int rand() {
    int a = 16807;
    unsigned int m = 0x7fffffff;

    seed = seed * a % m; 
    return seed;
}

void set_seed(unsigned long int new_seed) {
    seed = new_seed;
}