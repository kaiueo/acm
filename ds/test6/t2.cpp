#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Anode{
    int adjvex;
    Anode* nextarc;
    int data;
}ArcNode;

typedef struct Vnode{
    int data;
    Anode* firstarc;
}Vnode;

typedef Vnode AdjList[1005];
typedef struct{
    AdjList adjlist;
    int n, e;
}ALGraph;
int visited[1005] = {0};

void CreateAlgraph(ALGraph* &G, int a, int b){
    G = (ALGraph*)malloc(sizeof(ALGraph));
    G->n = a;
    G->e = b;
    for(int i =0;i<a;i++){
        G->adjlist[i].data = i;
        G->adjlist[i].firstarc=NULL;
    }
}

void Addarc(ALGraph* &G, int a, int b){
    ArcNode *p1, *p2;
    p1 = (ArcNode*)malloc(sizeof(ArcNode));
    p2 = (ArcNode*)malloc(sizeof(ArcNode));
    p1->adjvex = b;
    p2->adjvex = a;
    p1->nextarc = NULL;
    p2->nextarc = NULL;
    ArcNode* p = G->adjlist[a].firstarc;
    if(p==NULL){
        G->adjlist[a].firstarc = p1;
    }
    else{
        while(p->nextarc!=NULL){
            p = p->nextarc;
        }
        p->nextarc = p1;
    }
    p = G->adjlist[b].firstarc;
    if(p==NULL){
        G->adjlist[b].firstarc = p2;
    }
    else{
        while(p->nextarc!=NULL){
            p = p->nextarc;
        }
        p->nextarc = p2;
    }
}

void DFS(ALGraph* G, int v){
    ArcNode* p = G->adjlist[v].firstarc;
    visited[v] = 1;
    printf("%d ", v);
    while(p!=NULL){
        if(visited[p->adjvex]==0){
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void freethem(ALGraph* &G){
    for(int i = 0;i<G->n;i++){
        ArcNode* p = G->adjlist[i].firstarc;
        ArcNode *q;
        while(p!=NULL){
            q = p->nextarc;
            free(p);
            p = q;
        }
    }
    free(G);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ALGraph* G;
        int a, b;
        cin>>a>>b;
        CreateAlgraph(G, a, b);
        while(b--){
            int k, m;
            cin>>k>>m;
            Addarc(G, k, m);
        }
        for(int i = 0;i<100;i++){
            visited[i] = 0;
        }
        DFS(G,0);
        for(int i = 0;i<G->n;i++){
            if(visited[i]==0){
                DFS(G, i);
            }
        }
        freethem(G);
        cout<<endl;
    }
}
