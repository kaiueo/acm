#include <bits/stdc++.h>

using namespace std;

int data[500];

char s[100005];


int main()
{
    int t;
    scanf("%d", &t);



    while(t--)
    {
        scanf(" %s", s);
        priority_queue<int ,vector<int>,greater<int> >q;
        memset(data,0, sizeof(data));
        sort(s, s+strlen(s));
        char a = s[0];
        int l = strlen(s);
        int tmp = 1;
        int off = 0;

        for(int i = 1;i<l;i++){
            if(s[i]==a){
                tmp++;
            }
            else{
                data[off++] = tmp;
                tmp = 1;
                a = s[i];
            }
        }
        data[off++] = tmp;


        while(!q.empty())
            q.pop();
        for(int i= 0; i<off; i++)
        {
            q.push(data[i]);
        }

        int ans=0;
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            ans+=(a+b);
            q.push(a+b);
        }
        printf("%d\n",ans);

    }

    return 0;
}
