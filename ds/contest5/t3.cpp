#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct BTNode
{
    char data[10];
    BTNode *lchild,*rchild;
};
char str[1005];
void CreateBTNode(BTNode *&b)
{
    BTNode *St[1005],*p;
    int top=-1,k,l=strlen(str);
    b=NULL;
    for(int i=0; i<l; ++i)
        switch(str[i])
        {
        case '(':
            St[++top]=p;
            k=1;
            break;
        case ')':
            --top;
            break;
        case ',':
            k=2;
            break;
        default:
            p=(BTNode *)malloc(sizeof(BTNode));
            int j=0;
            while(i<l&&str[i]!='('&&str[i]!=')'&&str[i]!=',')
                p->data[j++]=str[i++];
            --i;
            p->data[j]='\0';
            p->lchild=p->rchild=NULL;
            if(!b)
                b=p;
            else
                switch(k)
                {
                case 1:
                    St[top]->lchild=p;
                    break;
                case 2:
                    St[top]->rchild=p;
                    break;
                }
        }
}

void preOrder(BTNode *root,string s)
{
    if(root==NULL)
        return;
    cout<<s<<root->data<<endl;
    preOrder(root->lchild,s+"  ");
    preOrder(root->rchild,s+"  ");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    BTNode *b;
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    CreateBTNode(b);
    string s = "";
    preOrder(b, s);
    }

}

