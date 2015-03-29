#include<cstdio>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0,tmp;
        while(n--)
        {
            scanf("%d",&tmp);
            ans^=tmp;
        }
        printf("%d\n",ans);
    }
}

