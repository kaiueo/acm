#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
int data[11][30];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        memset(data, 0, sizeof(data));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                scanf("%d", &data[i][j]);
            }
        }
        int t;
        scanf("%d", &t);

        while(t--){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
            int mx=data[x1][y1];
            int mn=data[x1][y1];
            for(int i = x1;i<=x2;i++){
                for(int j = y1;j<=y2;j++){
                    if(data[i][j]>mx){
                        mx = data[i][j];
                    }
                    if(data[i][j]<mn){
                        mn = data[i][j];
                    }
                }
            }
            printf("%d %d\n", mn, mx);
        }
    }
    return 0;
}

