#include <bits/stdc++.h>
using namespace std;
int f[20005];
int w[305];
int v[305];
int main()
{
    int v0;
    while(scanf("%d", &v0)!=EOF)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++)
        {
            int a, b;
            scanf("%d%d", &v[i], &w[i]);
        }
        memset(f,0,sizeof(f));

        for(int i = 1; i<=n; i++)
        {
            for(int j = w[i]; j<=v0; j++)
            {

                if(f[j]< f[j-w[i]]+v[i])
                {
                    f[j] =  f[j-w[i]]+v[i];
                }

            }
        }
        printf("%d\n", f[v0]);
    }

}
