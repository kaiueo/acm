#include <bits/stdc++.h>

using namespace std;
int w[10005];
int v[10005];
double r[10005];

struct A
{
    int w;
    int v;
    double r;
};

bool cmp(A a1, A a2)
{
    return a1.r>a2.r;
}

A a[10005];

int main()
{
    int G, K, N;
    while(scanf("%d%d%d", &G, &K, &N)!=EOF)
    {
        for(int i = 0; i<K; i++)
        {
            scanf("%d", &a[i].w);
            scanf("%d", &a[i].v);
            a[i].r = (double)a[i].v/(double)a[i].w;
        }
        sort(a, a+K, cmp);

        double sum = 0;
        double l = G;
        for (int i = 0; i < K; i++)
        {
            if(l>0)
            {
                if(l>a[i].w)
                {
                    l -= a[i].w;
                    sum += a[i].v;
                }
                else
                {
                    sum += l*a[i].r;
                    l =0;
                    break;
                }

            }
        }

        if(sum<N){
            printf("%.3f\n", N-sum);
        }
        else{
            printf("summon!\n");
        }



    }

    return 0;
}
