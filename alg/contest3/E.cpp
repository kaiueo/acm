#include <bits/stdc++.h>

using namespace std;
double p[100];
double q[100];
double e[200][100];
double w[200][200];

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 1;i<=n; i++)
        {
            scanf("%lf", &p[i]);
        }
        for(int i = 0; i<=n; i++)
        {
            scanf("%lf", &q[i]);
        }

        for(int i = 1; i<=n+1; i++)
        {
            e[i][i-1] = q[i-1];
            w[i][i-1] = q[i-1];
        }
        for(int l = 1;l<=n;l++){
            for(int i = 1;i<=n-l+1;i++){
                int j = i+l-1;
                e[i][j] = 999999;
                w[i][j] = w[i][j-1]+p[j]+q[j];
                for(int r = i;r<=j;r++){
                    double t = e[i][r-1]+e[r+1][j]+w[i][j];
                    if(t<e[i][j]){
                        e[i][j] = t;
                    }
                }
            }
        }

        printf("%.3f\n", e[1][n]);
    }
    return 0;
}
