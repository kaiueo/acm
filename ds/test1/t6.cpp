#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        long long int n1 = 0;
        long long int n2 = 1;
        long long int sum = 0;
        if(n==2){
            printf("1\n");
        }
        else{
            for(int i = 3;i<=n;i++){
                sum = (i-1) * (n1 + n2);
                n1 = n2;
                n2 = sum;
            }
            printf("%lld\n",sum);
        }
    }
}
