#include <bits/stdc++.h>

using namespace std;

struct A{
    long long int b;
    long long int e;
};

A data[100005];

bool cmp(A a1, A a2){
    return a1.e<a2.e;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i = 0;i<n;i++){
            scanf("%lld", &data[i].b);
            scanf("%lld", &data[i].e);
        }

        sort(data,data+n, cmp);


        int cnt = 1;
        int now = 0;

        for(int i = 1;i<n;i++){
            if(data[i].b>data[now].e){
                cnt++;
                now = i;
            }
        }

        printf("%d\n", cnt);




    }

    return 0;
}
