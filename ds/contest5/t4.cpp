#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
int array[1010];
typedef struct node
{
    node *lChild;
    int data;
    node *rChild;
} BTreeNode, *BTree;
void InitBTree(BTree &BT)
{
    BT = NULL;
}

BTree CreateBiTree(BTree &BT, int arr[], int i, int n)
{

    if(BT)
    {
        cout << BT->data << endl;
    }
    if(i > n)
    {
        return NULL;
    }
    else
    {

        BT = (BTree)malloc(sizeof(BTreeNode));
        BT->data = array[i-1];
        BT->lChild = NULL;
        BT->rChild = NULL;
        if((2*i-1) < n && array[2*i-1] !=-1)
        {
            BT->lChild = CreateBiTree(BT->lChild, array, 2*i, n);
        }

        if((2*i) < n && array[2*i] !=-1)
        {
            BT->rChild = CreateBiTree(BT->rChild, array, 2*i+1, n);
        }
        return BT;
    }
}

void printTree(BTree &BT)
{
    if(BT == NULL)return;
    else
    {
        cout<<BT->data;
        if(BT->lChild!=NULL||BT->rChild!=NULL)
        {
            cout<<'(';
            if(BT->lChild!=NULL)
            {
                printTree(BT->lChild);
            }
            if(BT->rChild!=NULL)
            {
                cout<<',';
                printTree(BT->rChild);
            }
            cout<<')';
        }
    }
}
int main()
{
    int n;
    BTree bt;
    cin >> n;
    for(int i = 0; i <n; ++i)
    {
        cin >> array[i];
    }
    InitBTree(bt);
    CreateBiTree(bt, array, 1, n);
    printTree(bt);
    return 0;
}

