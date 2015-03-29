#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    long long int x, y;
    while(scanf("%lld%lld",&x, &y)!=EOF){
        while(x!=y){
            long long int mx = max(x, y);
            long long int mn = min(x, y);
            mx /= 2;
            x = mx;
            y = mn;
        }
        printf("%lld\n",x);
    }
}

