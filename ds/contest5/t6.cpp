#include <stdio.h>
#include <string.h>
char s1[50005],s2[50005];
void s(int l)
{
    scanf("%s",s1);
    scanf("%s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int ans = 100000,cnt = 0;
    for(int i = 0; i <= l1 - l2; i++)
    {
        cnt = 0;
        for(int j = 0; j < l2; j++)
        {
            if(s1[i+j] != s2[j])
                cnt++;
            if(cnt > ans) break;
        }
        if(cnt < ans) ans = cnt;
    }
    printf("Case #%d: %d\n",l,ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int l = 1; l <= t; l++)
        s(l);
    return 0;
}

