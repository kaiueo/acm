#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
char St[10005];
int main()
{
    int n;
    while(cin>>n)
    {
        int top = -1;
        int f = 0;
        for(int i = 0; i<n; i++)
        {
            string s;
            cin>>s;
            if(s=="TYPE")
            {
                getchar();
                scanf("%c", &St[++top]);
                f = 0;
            }
            else if(s=="CANCLE")
            {
                if(top!=-1)
                {
                    top--;
                    f++;
                }

            }
            else
            {
                if(f)
                {
                    top++;
                    f--;
                }
            }
        }
        St[++top] = '\0';
        printf("%s\n", St);
    }
}
