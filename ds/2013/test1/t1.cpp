#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n, p, k;
    while(scanf("%d%d%d",&n,&p,&k)!=EOF){
        int low = p - k;
        int high = p + k;
        if(low<1&&high>n){
            low = 1;
            high = n;
            for(int i = low;i<=n;i++){
                i == p?printf("(%d) ",i):printf("%d ",i);
            }
            printf("\n");
        }
        else if(low<1&&high<=n){
            low = 1;
            for(int i = low;i<=high;i++){
                i == p?printf("(%d) ",i):printf("%d ",i);
            }
            if(high != n){
                printf(">>");
            }

            printf("\n");
        }
        else if(low>=1&&high>n){
            high = n;
            if(low!=1){
                printf("<< ");
            }
            for(int i = low;i<=high;i++){
                i == p?printf("(%d) ",i):printf("%d ",i);
            }
            printf("\n");
        }
        else if(low > 1&&high<=n){
            printf("<< ");
            for(int i = low;i<=high;i++){
                i == p?printf("(%d) ",i):printf("%d ",i);
            }
            if(high != n){
                printf(">>");
            }
            printf("\n");
        }
    }
}
