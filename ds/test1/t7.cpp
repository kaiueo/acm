#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m%(n+1)){
            printf("WIN\n");
        }
        else{
            printf("LOSE\n");
        }
    }
}
