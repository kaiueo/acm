#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 100005;

struct edge{
    int u, v, w;
    edge(int _u=0, int _v=0, int _w=0):u(_u), v(_v), w(_w){}
    bool operator<(const edge &other) const{
        return w<other.w;
    }
}e[MAXM];
int n, m;
int u[MAXN];
void init(){
    for(int i= 1;i<=n;i++){
        u[i] = i;
    }
}

int find(int x){
    if(x!=u[x]){
        u[x] = find(u[x]);
    }
    return u[x];
}

void merge(int x, int y){
    u[find(x)] = find(y);
}

int kruskal(){
    sort(e, e+m);
    init();
    int ans = 0;
    int cnt = 0;
    for(int i = 0;cnt<n-1&&i<m;i++){
        if(find(e[i].u)!=find(e[i].v)){
            merge(e[i].u, e[i].v);
            ans+=e[i].w;
            cnt++;
        }
    }
    return ans;
}

int main(){
    while(scanf("%d%d", &n,&m)!=EOF){
        for(int i = 0;i<m;i++){
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }

        int ans = kruskal();
        printf("%d\n", ans);
    }
}
