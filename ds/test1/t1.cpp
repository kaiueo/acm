#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){

    int k;
    while(scanf("%d",&k)!=EOF){
        for(int i = 1;i<=k;i++){
            for(int j = 1;j<=k;j++){
                int a = min(abs(i),min(abs(k-i+1),min(abs(j),abs(k-j+1))));
                if(a%2==0){
                    printf("#");
                }
                else{
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
