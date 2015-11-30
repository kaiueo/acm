#include <bits/stdc++.h>

using namespace std;
int num[10];
int m[10];

int main()
{

    while(scanf("%d", &num[1])!=EOF)
    {
        for(int i = 2; i<=6; i++)
        {
            scanf("%d", &num[i]);
        }
        int n;
        scanf("%d", &n);
        int cnt = 0;
        m[1] = 1;
        m[2] = 5;
        m[3] = 10;
        m[4] = 50;
        m[5] = 100;
        m[6] = 500;


        for(int i = 6; num[i]>=0; i--)
        {
            while(n>0&&num[i]>0)
            {
                if(n-m[i]>=0)
                {
                    n -= m[i];
                    num[i]--;
                    cnt++;
                }
                else{
                    break;
                }
            }
        }

        printf("%d\n", cnt);
    }


    return 0;
}
