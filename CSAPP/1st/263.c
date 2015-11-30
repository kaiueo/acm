#include "stdio.h"
int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) << 3;
    unsigned z = 1 << (w-k-1);
    unsigned mask = z - 1;
    unsigned right = mask & xsrl;
    unsigned left = ~mask & (~(z&xsrl) + z);
    return left | right;
}
unsigned srl(unsigned x, int k)
{
    int xsra = (int) x >> k;
    int w = sizeof(int)*8;
    unsigned z = 2 << (w-k-1);
    return (z - 1) & xsra;
}

int main(){
    int x1 = -2048;
    unsigned x2 = 2048;
    int x = sra(x1, 10);
    unsigned y = srl(x2, 10);
    printf("%d\n", x);
    printf("%u\n", y);
}
