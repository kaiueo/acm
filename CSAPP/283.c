#include "stdio.h"
unsigned f2u(float f){
    return (unsigned)f;
}
int float_ge(float x, float y){
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (ux<<1 == 0 && uy<<1 == 0) ||
        (!sx && sy) ||
        (!sx && !sy && ux >= uy) ||
        (sx && sy && ux <= uy);
}

int main(){
    float x = 10.0;
    float y = 2.0;
    int ans = float_ge(x, y);
    printf("%d\n", ans); 
}
