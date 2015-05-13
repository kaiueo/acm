#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
char str[100005];
int next[100005];
int getNext(int n)
{
    int i = 0,j = -1;
    next[0] = -1;
    while(i<n){
        if(j == -1||str[i] == str[j]){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
}
int main()
{
    while(scanf("%s", str)!=EOF){
        int k = strlen(str);
        getNext(k);
        int num = k-next[k];
        if(num!=0&&k%num==0){
            printf("%d\n", k/num);
        }
        else{
            printf("1\n");
        }
    }
}

