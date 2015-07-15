#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct Anode{
    int arcvex;
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
    int n; int e;
}ALGraph;

void CreateAlgraph(ALGraph* &G, int a, int b){
    G = (ALGraph*)malloc(sizeof(ALGraph));
    G->n = a;
    G->e = b;
    for(int i = 0;i<a;i++){
        G->adjlist[i].data = i;
        G->adjlist[i].firstarc=NULL;
    }
}

void Addarc(ALGraph* &G, int a, int b){
    ArcNode *p1, *p2;
    p1 = (ArcNode*)malloc(sizeof(ArcNode));
    p2 = (ArcNode*)malloc(sizeof(ArcNode));
    p1->arcvex = b;
    p2->arcvex = a;
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

void BFS(ALGraph* G, int v){
    ArcNode *p;
    int queue[105];
    int front = -1;
    int rear = -1;
    int visited[105];
    int w, i;
    memset(visited, 0, sizeof(visited));
    printf("%d ", v);
    visited[v] = 1;
    rear = (rear+1)%105;
    queue[rear] = v;
    while(front!=rear){
        front = (front+1)%105;
        w = queue[front];
        p = G->adjlist[w].firstarc;
        while(p!=NULL){
            if(visited[p->arcvex]==0){
                printf("%d ", p->arcvex);
                visited[p->arcvex] = 1;
                rear = (rear+1)%105;
                queue[rear] = p->arcvex;
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int i, j;
        ALGraph* G;
        cin>>i>>j;
        CreateAlgraph(G, i, j);
        while(j--){
            int a, b;
            cin>>a>>b;
            Addarc(G,a, b);
        }
        BFS(G, 0);
    }
}
