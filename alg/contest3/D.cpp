#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long int inf = 9111111111111111111;
long long int M[1005];
long long int S[1005][1005];

long long int dp_min[1005][1005];

void prin(int i, int j)
{
    if(i==j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        prin(i, S[i][j]);
        prin(S[i][j]+1, j);
        printf(")");
    }
}
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 1; i<=n+1; i++)
        {
            scanf("%lld", &M[i]);
        }
        memset(dp_min, 0, sizeof(dp_min));
        memset(S, 0, sizeof(S));



        for(int l = 1; l<=n-1; l++)
        {
            for(int i = 1; i+l<=n; i++)
            {
                int j = i+l;
                dp_min[i][j] = inf;
                for(int k = i; k<j; k++)
                {
                    int q = dp_min[i][k]+dp_min[k+1][j]+M[k+1]*M[i]*M[j+1];
                    if(q<=dp_min[i][j])
                    {
                        dp_min[i][j]=q;

                            S[i][j] = k;


                    }

                }
            }
        }
        prin(1, n);
        printf("\n");
    }
    return 0;
}
