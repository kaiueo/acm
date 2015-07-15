#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int f(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 1;
    }
    else{
        return f(n-1)+f(n-2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        printf("Case %d:", i);
        int tmp;
        scanf("%d", &tmp);

        int a = f(tmp);
        printf("%d\n", a);

    }
}
