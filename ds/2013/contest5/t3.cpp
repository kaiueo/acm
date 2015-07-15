#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 505;
int g[MAXN][MAXN], n, vis[MAXN], m;
int dist[MAXN];
void dijkstra(int s){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    while(1){
        int k = -1;
        for(int i = 1;i<=n;i++){
            if(!vis[i]&&(k==-1||dist[i]<dist[k])){
                k = i;
            }
        }
        if(k==-1){
            break;
        }
        vis[k] = true;
        for(int i = 1;i<=n;i++){
            dist[i] = min(dist[i], dist[k]+g[k][i]);
        }
    }
}
int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        memset(g, 0x3f,sizeof(g));
        for(int i = 1;i<=n;i++){
            g[i][i] = 0;
        }
        for(int i = 1;i<=m;i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a][b] = min(g[a][b], c);
        }
        dijkstra(1);
        double ans = 0;
        for(int i = 1;i<=n;i++){
            ans += dist[i];
        }
        ans = ans/(n-1);
        printf("%.2f\n", ans);
    }

}
