#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int INF = 0x3f3f3f3f;
int data[1000005];
void merge(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1];
    int R[n2+1];
    for(int i = 0; i<n1; i++)
    {
        L[i] = data[p+i];

    }
    for(int j = 0; j<n2; j++)
    {
        R[j] = data[q+j+1];

    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;
    for(int k = p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSort(p, q);
        mergeSort(q+1, r);
        merge(p, q, r);
    }

}

int main()
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i<n;i++){
            scanf("%d", &data[i]);
        }
        mergeSort(0, n-1);
        for(int i = 0;i<n;i++){
            printf("%d ", data[i]);
        }
        printf("\n");

    }
}
