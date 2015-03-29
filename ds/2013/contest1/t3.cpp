#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXN 100001
typedef struct {
    int *data;
    int length;
}Node;
Node *LA, *LB, *LC;
void init(int marker){
    if(marker == 1){
        LA = new Node;
        LA->data =new int[MAXN];
        LA->length = 0;
    }
    else {
        LC = new Node;
        LC->data = new int[MAXN];
        LC->length=0;
    }
}

void creat(int n){
    LB = new Node;
    LB->data=new int[MAXN];
    for(int i = 0;i<n;i++){
        scanf("%d", &LB->data[i]);
    }
    LB->length = n;
}

void DestroyList(int marker){
    switch(marker){
        case 1:
            free(LA->data);
            free(LA);
            break;
        case 2:
            free(LB->data);
            free(LB);
            break;
        case 3:
            free(LC->data);
            free(LC);
            break;
    }
}

void unionList(){
    int i = 0, j = 0, k = 0;
    init(2);
    while(i<LA->length&&j<LB->length){
        if(LA->data[i]<LB->data[j]){
            LC->data[k++] = LA->data[i++];
        }
        else{
            LC->data[k++] = LA->data[i++];
        }
    }
    while(i<LA->length){
        LC->data[k++] = LA->data[i++];
    }
    while(j<LA->length){
        LC->data[k++] = LA->data[j++];
    }
    for(int l = 0;l<k;l++){
        LA->data[l] = LC->data[l];
    }
    LA->length = k;
    DestroyList(2);
    DestroyList(3);
}

void display(){
    for(int i = 0;i<LA->length;i++){
        printf("%d ", LA->data[i]);
    }
    printf("\n");
}
int main(){
    int n, m;
    while(scanf("%d", &n)!=EOF){
        init(1);
        for(int i = 0;i<n;i++){
            scanf("%d", &m);
            creat(m);
            unionList();
        }
        display();
        DestroyList(1);
    }
}
