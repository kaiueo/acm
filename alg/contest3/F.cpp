#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
long long int f[2][10005],g[2][10005];

int main()
{
    string s1,s2;

    while(cin>>s1)
    {
        cin>>s2;
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        int len1=s1.size()-1,len2=s2.size()-1;
        for(int i=0; i<=len2; i++)g[0][i]=1;
        int k;
        for(int i=1; i<=len1; i++)
        {
            k=i & 1;
            memset(g[k],0,sizeof(g[k]));
            memset(f[k],0,sizeof(f[k]));
            g[k][0]=1;
            g[!k][0]=1;
            for(int j=1; j<=len2; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    f[k][j]=f[!k][j-1]+1;
                    g[k][j]=g[!k][j-1];
                    g[k][j]%=100000000;
                    if(f[k][j]==f[!k][j])
                    {
                        g[k][j]+=g[!k][j];
                        g[k][j]%=100000000;
                    }
                    if(f[k][j-1]==f[k][j])
                    {
                        g[k][j]+=g[k][j-1];
                        g[k][j]%=100000000;
                    }
                }
                else
                {
                    if(f[!k][j]>f[k][j-1])
                    {
                        f[k][j]=f[!k][j];
                        g[k][j]+=g[!k][j];
                        g[k][j]%=100000000;
                    }
                    if(f[!k][j]<f[k][j-1])
                    {
                        f[k][j]=f[k][j-1];
                        g[k][j]+=g[k][j-1];
                        g[k][j]%=100000000;
                    }
                    if(f[!k][j]==f[k][j-1])
                    {
                        f[k][j]=f[!k][j];
                        g[k][j]+=g[!k][j]+g[k][j-1];
                        if(f[!k][j-1]==f[k][j])g[k][j]-=g[!k][j-1];
                        g[k][j]=(g[k][j]+3*100000000)%100000000;
                    }
                }
            }
        }
        printf("%lld\n", f[k][len2]);
        printf("%lld\n", g[k][len2]);

    }
}
