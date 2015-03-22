#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXSIZE 200
using namespace std;
typedef int DataType;
typedef struct {
    DataType *data;
    int length;
} SeqList;

void initList(SeqList &L){
    L.data = (DataType*) malloc(MAXSIZE * sizeof(DataType));
    L.length = 0;
}
void clearList(SeqList &L){
    L.length = 0;
}
int isEmpty(SeqList &L){
    return L.length == 0;
}
int isFull(SeqList &L){
    return L.length == MAXSIZE;
}
int length(SeqList &L){
    return L.length;
}
int search(SeqList &L, DataType e){
    for(int i = 0;i<L.length;i++){
        if(L.data[i] == e){
            return i;
        }
    }
    return -1;
}
int insert(SeqList &L,int i, DataType e){
    if(L.length == MAXSIZE){
        return 0;
    }
    else if(i<1||i>L.length+1){
        return 0;
    }
    else{
        for(int j = L.length;j>=i-1;j--){
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
        L.length++;
        return 1;
    }
}
int remove(SeqList &L, int i, DataType &e){
    if(i<1||i>L.length){
        return 0;
    }
    else{
        e = L.data[i-1];
        for(int j = i-1;j<L.length;j++){
            L.data[j] = L.data[j+1];
        }
        L.length--;
        return 1;
    }
}
void copy(SeqList &L1, SeqList &L2){
    for(int i = 0;i<L1.length;i++){
        L2.data[i] = L1.data[i];
        L2.length++;
    }
}


int main(){
    SeqList L1;
    initList(L1);
    for(int i = 0;i<=10;i++){
        insert(L1,i+1,i);
    }
    for(int i = 0;i<L1.length;i++){
        printf("%d ", L1.data[i]);
    }
    printf("\n\n");
    insert(L1, 3, 100);
    for(int i = 0;i<L1.length;i++){
        printf("%d ", L1.data[i]);
    }

    printf("\n\n");
    DataType a;
    remove(L1, 5,a);
    for(int i = 0;i<L1.length;i++){
        printf("%d ", L1.data[i]);
    }
    printf("\n\n");
    printf("%d\n\n",a);

    int b = search(L1, 10);
    printf("%d\n\n", b);

    SeqList L2;
    initList(L2);
    copy(L1, L2);
    for(int i = 0;i<L2.length;i++){
        printf("%d ", L2.data[i]);
    }

    clearList(L2);

    printf("\n\n");
    printf("%d", isEmpty(L2));
    printf("\n\n");
    printf("%d", isEmpty(L1));
    printf("\n\n%d", L2.length);



    return 0;
}

