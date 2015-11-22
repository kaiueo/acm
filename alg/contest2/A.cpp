#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
int data[1000005];
int random(int x, int y){
    srand((unsigned)time(NULL));
    int ran_num = rand()%(y-x)+x;
    return ran_num;
}

int mpartition(int p, int r){
    int x = data[r];
    int i = p-1;
    for(int j = p;j<r;j++){
        if(data[j]<=x){
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[++i], data[r]);
    return i;
}

int randomizedpartition(int p, int r){
    int i = random(p, r);
    swap(data[r], data[i]);
    return mpartition(p, r);
}

int randomizedSelect(int p, int r, int i){
    if(p==r){
        return data[p];
    }

    int q = randomizedpartition(p, r);
    int k = q - p + 1;
    if(i == k){
        return data[q];
    }
    else if(i<k){
        return randomizedSelect(p, q-1, i);
    }
    else{
        return randomizedSelect(q+1, r, i-k);
    }
}

int main()
{
    int n, x;
    while(scanf("%d%d", &n, &x)!=EOF){
        for(int i = 0;i<n;i++){
            scanf("%d", &data[i]);
        }
        int i = randomizedSelect(0, n-1, n-x+1);
        printf("%d\n", i);
    }
    return 0;
}
