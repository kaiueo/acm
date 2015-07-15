#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 500;
int g[MAXN][MAXN];
void floyd(int n){
    for(int k = 1;k<=n;k++){
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        memset(g, 0x3f, sizeof(g));
        for(int i = 1;i<=n;i++){
            g[i][i] = 0;
        }
        for(int i = 1;i<=n;i++){
            int m;
            scanf("%d", &m);
            for(int j =  1;j<=m;j++){
                int a, b;
                scanf("%d%d", &a, &b);
                g[i][a] = min(g[i][a], b);
            }
        }
        floyd(n);
        int idx = 0;
        int ans = 0x3f3f3f3f;
        for(int i = 1;i<=n;i++){
            int tmp = 0;
            for(int j = 1;j<=n;j++)
                tmp = max(tmp, g[i][j]);
            if(tmp<ans){
                ans = tmp;
                idx = i;
            }
        }
        if(idx==0){
            puts("disjoint");
        }
        else{
            printf("%d %d\n", idx, ans);
        }

    }
}
