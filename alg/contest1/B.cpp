#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int fun(int n){
    if(n==1){
        return 2;
    }
    else if(n==2){
        return 3;
    }
    else{
        int q= 2;
        int h = 3;
        int sum = 0;
        for(int i = 3;i<=n;i++){
            sum = q+h;
            q =h;
            h = sum;
            sum%=100007;
            q %=100007;
            h%=100007;

        }
        return sum;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        int ans = fun(n);
        printf("%d\n",ans);
    }

    return 0;
}
