#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct list{
    int data[105];
    int data1[105];
    int length;
}*seqlist, seq;

void initlist(seqlist &l, int n){
    l->length = n;
}
int search(seqlist &l, int e){
    for(int i = 0;i<l->length;i++){
        if(l->data[i] == e){
            return i;
        }
    }
    return -1;
}

int func(seqlist &l){
    int p=0,q=0;
    while(p!=-1||q!=-1){
        p = search(l,l->data1[p]);
        q = search(l,l->data1[q]);
        if(q==-1){
            return -1;
        }

        q = search(l,l->data1[q]);
        if(l->data[p] == l->data[q]){
            int x = p;
            int c = 0;
            do{
                x = search(l, l->data1[x]);
                c++;
            }while(x!=p);
            return c;
        }
    }
}


int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        seqlist l;
        l = (seqlist)malloc(sizeof(seq));
        initlist(l, n);
        for(int i = 0;i<n;i++){
            int a, b;
            scanf("%d%d", &a, &b);
            l->data[i] = a;
            l->data1[i] = b;

        }
        int c = func(l);
        if(c!=-1){
            printf("%d\n", c);
        }
        else{
            printf("No Loop\n");
        }
    }
}
