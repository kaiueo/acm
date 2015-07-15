#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int cnt;
int f(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        cnt++;
        return f(n-1) + f(n-2);
    }
}
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){

        cnt = 0;
        f(n);
        printf("%d\n", cnt);
    }
}
