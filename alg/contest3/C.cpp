#include <bits/stdc++.h>
using namespace std;
int f[20005];
int w[305];
int v[305];
const int finf = -9999999;
int main()
{
    int v0;
    while(scanf("%d", &v0)!=EOF)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++)
        {
            int a, b;
            scanf("%d%d", &v[i], &w[i]);
        }
        //memset(f,0,sizeof(f));
        f[0] = 0;
        for(int i = 1;i<=v0;i++){
            f[i] = finf;
        }


        for(int i = 1; i<=n; i++)
        {
            for(int j = v0; j>=w[i]; j--)
            {

                if(f[j]< f[j-w[i]]+v[i])
                {
                    f[j] =  f[j-w[i]]+v[i];
                }

            }
        }
        if(f[v0]<0){
            printf("jpx\n");
        }
        else{
            printf("%d\n", f[v0]);
        }

    }

}
