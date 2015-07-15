#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int data[100005];
int top = -1;
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        memset(data, 0, sizeof(data));
        top = -1;
        for(int i = 0;i<n;i++){
            int a;
            scanf("%d", &a);
            data[++top] = a;
        }
        while(top!=-1){
            printf("%d ", data[top--]);
        }
        printf("\n");
    }
}
