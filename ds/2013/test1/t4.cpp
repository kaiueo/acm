#include <cstdio>
#include <iostream>
using namespace std;
int* a[1005];
int data[1005];
int main(){
    int n, m, k;
    while(scanf("%d%d%d", &n, &m, &k)!=EOF){
        for(int i = 0;i<=m;i++){
            data[i] = i;
        }
        for(int i = 0;i<=n;i++){
            a[i] = new int[m];
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(int i = 1;i<=k;i++){
            char s;
            int a1,a2;
            cin>>s>>a1>>a2;
            if(s=='C'){
                swap(data[a1-1], data[a2-1]);
            }
            else{
                swap(a[a1-1], a[a2-1]);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                printf("%d ",a[i][data[j]]);
            }
            printf("\n");
        }
        for(int i = 0;i<=n;i++){
            a[i] = new int[m];
            delete[] a[i];
        }
    }
}
