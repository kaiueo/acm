#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long int wp(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        long long int q = 0;
        long long int h = 1;
        long long int ans = 0;
        long long int s = 3;
        for(int i = 1;i<=n-2;i++){
            ans = (s-1) * (q+h);
            q = h;
            h = ans;
            s++;
        }
        return ans;
    }
}

int main()
{

    int n;
    while(scanf("%d", &n)!=EOF){
        long long int ans = wp(n);
        printf("%lld\n", ans);
    }

    return 0;
}
