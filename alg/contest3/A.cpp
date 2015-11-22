#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
long long int data[10005];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &data[i]);
        }
        sort(data,data+n);
        long long int ans=0;
        long long int a = 0;
        for(int i=1; i<n; i++){
            a += data[i-1];
            ans+=a;
        }

        printf("%lld\n", ans);

    }

}
