#include <iostream>
#include <cstdio>
using namespace std;
int data[1005][1005];
int main(){
    int m, n, k;
    while(scanf("%d%d%d", &m, &n, &k)!=EOF){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                scanf(" %d", &data[i][j]);
            }
        }
        for(int i = 1;i<=k;i++){
            int c1, c2, r1, r2;
            scanf(" %d%d%d%d", &c1, &c2, &r1, &r2);
            long long int sum = 0;
            for(int i = r1-1;i<r2;i++){
                for(int j = c1-1;j<c2;j++){
                    sum += data[i][j];
                }
            }
            printf("%lld\n", sum);
        }
    }

}
