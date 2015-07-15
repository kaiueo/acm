#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 205;
int g[MAXN][MAXN];
int n, m;
void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        memset(g, 0x3f, sizeof(g));
        for(int i = 1;i<=n;i++){
            g[i][i] = 0;
        }
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(c<g[a][b]){
                g[a][b] = g[b][a] = c;
            }
        }
        floyd();
        double ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                ans += g[i][j];
            }
        }
        ans = ans/(n*(n-1));
        printf("%.2f\n",ans);
    }
}
