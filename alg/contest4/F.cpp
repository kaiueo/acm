#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[50]={0};
int k;
int increment()
{
        int i=0;
        int c=0;
        while(i<k&&a[i]==1)
        {
            a[i]=0;c++;
            i++;
        }
        if(i<k)
        {
            a[i]=1;c++;
        }
        return c;
}
int main()
{
    while(cin>>k)
    {
        memset(a,0,sizeof(a));
        int i=0;

        for(int i = k-1;i>=0;i--){
            scanf("%d", &a[i]);
        }

        int n;
        cin>>n;
        int pre=0,d=0;
        for(int j=0;j<k;j++)
            if(a[j]) pre++;
         for(int i=1;i<=n;i++)
        {
            int c=increment();
            d=0;
            for(int j=0;j<k;j++)
            if(a[j]) d++;
            cout<<c+d-pre<<" ";
            pre=d;
        }
        cout<<endl;
    }
}
