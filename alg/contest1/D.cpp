#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int data[1000005];
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){

        int x;
        scanf("%d", &x);
        for(int i = 0;i<=n;i++){
            scanf("%d", &data[i]);
        }
        int t;
        long long int sum = 0;
        for(int i = n;i>=0;i--){
            sum = (sum * x)%1000007;
            sum = (sum + data[i])%1000007;

        }

        printf("%lld\n", sum);

    }

    return 0;
}
