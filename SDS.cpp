#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
#define MaxVertexNum 10002
bool Visited[MaxVertexNum] = {false};
typedef int Vertex;
typedef struct ENode *Edge;
struct ENode{ //边结构的定义
    Vertex V1,V2;
};

typedef struct AdjVNode{//邻接点定义
    Vertex AdjV;
    struct AdjVNode *Next;
} *PtrToAdjVNode;

typedef PtrToAdjVNode AdjList[MaxVertexNum];

typedef struct GNode{
    int Nv;
    int Ne;
    AdjList G;
} *LGraph;

struct QueueNode{
    int Data;
    QueueNode *Next;
};

struct Queue{
    int num;
    QueueNode *Front;
    QueueNode *Rear;
};

Queue* BuildQueue(){
    Queue *Q = new struct Queue;
    Q->num = 0;
    Q->Front=Q->Rear=NULL;
    return Q;
}

void InsertQueue(Queue *Q,int item){
    QueueNode *New = new struct QueueNode;
    New->Data = item;
    New->Next = NULL;
    if(Q->num == 0)
        Q->Front=Q->Rear=New;
    else{
        Q->Rear->Next = New;
        Q->Rear = New;
    }
    Q->num++;
}

int PopQueue(Queue *Q)
{
    int temp = Q->Front->Data;
    Q->num--;
    QueueNode *p = Q->Front;
    if(Q->num == 0)
        Q->Front=Q->Rear=NULL;
    else
        Q->Front = Q->Front->Next;
    delete p;
    return temp;
}

LGraph CreateGraph(int VertexNum)
{
    LGraph Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(Vertex V = 1;V <= Graph->Nv;V++)
        Graph->G[V] = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode p = new struct AdjVNode;
    p->AdjV = E->V2;
    p->Next = Graph->G[E->V1];
    Graph->G[E->V1] = p;

    p = new struct AdjVNode;
    p->AdjV = E->V1;
    p->Next = Graph->G[E->V2];
    Graph->G[E->V2] = p;

}

LGraph BuildGraph(int Nv,int Ne){
    LGraph Graph = CreateGraph(Nv);
    Edge E = new struct ENode;
    while(Ne--){
        cin>>E->V1>>E->V2;
        InsertEdge(Graph,E);
    }
    return Graph;
}

int BFS(LGraph Graph,Vertex V) {
    for(Vertex i = 1;i <= Graph->Nv;i++)
        Visited[i] = false;
    int count = 0;
    Queue *Q = BuildQueue();
    InsertQueue(Q,V);
    Visited[V] = true;
    count++;
    Vertex W;
    Vertex last = V,tail;
    PtrToAdjVNode P;
    int level = 0;
    while(Q->num>0){
        W = PopQueue(Q);
        for(P=Graph->G[W];P;P = P->Next){
            if(!Visited[P->AdjV]){
                InsertQueue(Q,P->AdjV);
                Visited[P->AdjV] = true;
                count++;
                tail = P->AdjV;
            }
        }
        if(W == last){
            last = tail;
            level++;
        }
        if(level == 6)
            break;
    }
    return count;
}

int main(){
    int Nv,Ne;
    cin>>Nv>>Ne;
    LGraph Graph = BuildGraph(Nv,Ne);
    for(Vertex i = 1;i <= Graph->Nv;i++)
    {
        printf("%d: %.2f%%\n",i,double(BFS(Graph, i)*100/(double)Nv));
    }
}
