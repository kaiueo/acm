#include <iostream>
#include <cstdio>
#include <cstdlib>
#define leafNumber 20
#define totalNumber 39
#define maxValue 1000000;
using namespace std;

typedef double TElemType;
typedef int WType;

typedef struct HuffmanNode{
    TElemType data;
    WType weight;
    int lchild, rchild, parent;
};

typedef struct HuffmanTree{
    HuffmanNode elem[totalNumber];
    int n;
};

void createHuffmanTree(HuffmanTree &HT, WType w[], int n){
    int i, j, p1, p2, min1, min2;
    for(i=0;i<n;i++){
        HT.elem[i].weight = w[i];
    }
    for(i=0;i<2*n-1;i++){
        HT.elem[i].parent = HT.elem[i].lchild = HT.elem[i].rchild = -1;
    }
    for(i=n;i<2*n-1;i++){
        min1 = min2 = maxValue;
        for(j=0;j<i;j++){
            if(HT.elem[j].parent == -1){
                if(HT.elem[j].weight < min1){
                    p2 = p1;
                    min2 = min1;
                    p1 = j;
                    min1 = HT.elem[j].weight;
                }
                else if(HT.elem[j].weight<min2){
                    p2 = j;
                    min2 = HT.elem[j].weight;
                }
            }
        }
        HT.elem[i].lchild = p1;
        HT.elem[i].rchild = p2;
        HT.elem[i].weight = HT.elem[p1].weight + HT.elem[p2].weight;
        HT.elem[p1].parent = HT.elem[p2].parent = i;
    }
    HT.n = 2*n - 1;
}
