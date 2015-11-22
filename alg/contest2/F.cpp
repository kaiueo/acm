#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int p[1005][1005];
int t[1005][1005];
int f[1005][1005];

int minF(int x, int j, int N)
{
    int minn = 9999999;
    for(int i = 1; i<=N; i++)
    {
        if(f[i][j-1]+t[i][x]+p[x][j]<minn)
        {
            minn = f[i][j-1] + p[x][j] + t[i][x];
        }
    }

    return minn;

}
int ALS(int N, int M)
{
    for(int i = 1; i<=N; i++)
    {
        f[i][1] = p[i][1];
    }

    for(int j = 2; j<=M; j++)
    {
        for(int i = 1; i<=N; i++)
        {
            f[i][j] = minF(i, j, N);
        }
    }

    int minn = 9999999;
    for(int i = 1; i<=N; i++)
    {
        if(minn>f[i][M])
        {
            minn = f[i][M];
        }
    }
    return minn;

}

int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M)!=EOF)
    {
        for(int i = 1; i<=N; i++)
        {
            for(int j = 1; j<=M; j++)
            {
                scanf("%d", &p[i][j]);
            }
        }

        for(int i = 1; i<=N; i++)
        {
            for(int j = 1; j<=N; j++)
            {
                scanf("%d", &t[i][j]);
            }
        }

        int ans = ALS(N, M);
        printf("%d\n", ans);


    }
    return 0;
}
