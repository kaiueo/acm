#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int data[25][25];

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0){
            return 0;}
        string s;
        cin>>s;

        memset(data, 0, sizeof(data));
        int cnt = 0;
        int l = s.length();
        int x = s.length()/n;
        int tmp = 2;
        for(int i = 1; i<=x; i++)
        {
            if(i%2!=0&&i!=1){
                cnt++;
            }
            for(int j = 1; j<=n; j++)
            {
                if(i%2!=0)
                    data[i][j] = s[cnt++];
                else
                    data[i][j] = s[cnt--];
            }
            cnt = tmp*n-1;
            if(i%2==0){
                tmp = tmp+2;
            }
        }


        for(int j = 1; j<=n; j++)
        {
            for(int i = 1; i<=x; i++)
            {
                printf("%c", data[i][j]);
            }
        }
        printf("\n");
    }
}
