#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>
using namespace std;

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if (m<n)
        {
            int t=m;
            m=n;
            n=t;
        }
        int f=1;
        while (m/n==1&&m%n)
        {
            int t=m%n;
            m=n;
            n=t;
            f=-f;
        }
        if (f==1) printf("Nova\n");
        else printf("LaoWang\n");
    }
}
