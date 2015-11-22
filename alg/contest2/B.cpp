#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int f[200001];
int w[301];
int v[301];

int main()
{
    int m, T;
    while(scanf("%d%d", &T, &m)!=EOF)
    {
        for(int i = 1; i<=m; i++)
        {
            scanf("%d%d", &v[i], &w[i]);
        }


            memset(f,0,sizeof(f));

            for (int i = 1; i <= m; i++)
            {
                for (int j = T; j >= w[i]; j--)
                {
                    f[j] = max(f[j],f[j - w[i]] + v[i]);
                }
            }

        printf("%d\n", f[T]);
    }

    return 0;
}
