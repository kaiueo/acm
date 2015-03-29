#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct seqlist
{
    int data[10005];
    int length;
};

void init(seqlist &L)
{
    L.length = 0;
}

void insert(seqlist &L, int i, int e)
{

    for(int j = L.length; j>=i-1; j--)
    {
        L.data[j+1] = L.data[j];
    }
    L.data[i-1] = e;
    L.length++;

}


int main()
{

    int n;
    while(scanf("%d", &n)!=EOF){
        seqlist L;
        init(L);
        for(int i = 1;i<=n;i++){
            int a, b;

            scanf("%d%d", &a,&b);
            insert(L, a, b);
        }
        for(int i =0;i<L.length;i++){
            printf("%d ", L.data[i]);
        }
        printf("\n");
    }

    return 0;
}

