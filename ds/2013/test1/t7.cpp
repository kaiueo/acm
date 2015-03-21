#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int data[100005];
int main(){
    long long int n;
    while(scanf("%lld", &n)!=EOF){
        memset(data, 0, sizeof(data));
        for(int i = 0;i<n;i++){
            scanf(" %d", &data[i]);
        }
        sort(data, data+n);
        long long equal=0;
        for(int i = 1;i<n-1;i++){
            long long cnt = 1;
            while(data[i]==data[i-1]){
                ++i;
                ++cnt;
            }
            equal+=cnt*(cnt-1)/2;
        }
        printf("%lld\n", n*(n-1)/2-equal);
    }
}


