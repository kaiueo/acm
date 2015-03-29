#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef struct seqlist{
    int data[105];
    int length;
};
void display(seqlist &L){
    for(int i = 0;i<=L.length;i++){
        printf("%d ", L.data[i]);
    }
    printf("\n");
}
int init(seqlist &L, int n){

    for(int i = 0;i<n;i++){
        scanf("%d", &L.data[i]);
    }
    L.length = n-1;
}
void insert(seqlist &L, int i, int e){
    if(i<1||i>L.length+1){
        printf("Wrong Input!\n");
        return;
    }
    else{
        for(int j = L.length;j>=i-1;j--){
            L.data[j+1] = L.data[j];
        }
        L.data[i-1] = e;
        L.length++;
        display(L);
    }

}

void del(seqlist &L, int e){
    int i = 0;
    for(i = 0;i<=L.length;i++){
        if(L.data[i]==e){
            for(int j = i;j<L.length;j++){
                L.data[j]= L.data[j+1];
            }
            L.length--;
            display(L);

            return;
        }
    }
    printf("Wrong Input!\n");
}

void locate(seqlist &L, int e){
    int i = 0;
    for(i = 0;i<=L.length;i++){
        if(L.data[i] == e){
            printf("%d\n", i+1);
            return;
        }
    }
    printf("Wrong Input!\n");
}

void getelem(seqlist &L, int i){
    if(i<1||i>L.length+1){
        printf("Wrong Input!\n");
        return;
    }
    else{
        printf("%d\n", L.data[i-1]);
        return;
    }
}



int main()
{
    int n,m;
    seqlist L;
    while(scanf("%d%d", &n, &m)!=EOF){
        init(L, n);
        for(int i = 0;i<m;i++){
            string s;
            cin>>s;
            if(s == "Insert"){
                int a, b;
                cin>>a>>b;
                insert(L, a, b);
            }
            else{
                if(s == "Delete"){
                    int a;
                    cin>>a;
                    del(L, a);
                }
                else if(s == "Locate"){
                    int a;
                    cin>>a;
                    locate(L, a);
                }
                else{
                    int a;
                    cin>>a;
                    getelem(L, a);
                }
            }
        }
    }

    return 0;
}

