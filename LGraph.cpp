#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define MaxVertexNum 100

bool Visited[MaxVertexNum] = {false};

typedef int Vertex;
typedef int WeightType;
typedef int DataType;
typedef struct AdjVNode *PtrToAdjVNode;

/*定义边节点结构*/
typedef struct ENode{
    Vertex V1,V2;
    WeightType Weight;
}*PtrToENode;

typedef PtrToENode Edge;

struct AdjVNode {
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode {
    PtrToAdjVNode FirstEdge;
    DataType Data;  /*存顶点的数据*/
}AdjList[MaxVertexNum];

typedef struct GNode{
    int Nv;
    int Ne;
    AdjList G;
} *PtrToGNode;
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph = new struct GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0;V < Graph->Nv;V++)
    {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode p = new struct AdjVNode;
    p->AdjV = E->V2;
    p->Weight = E->Weight;
    p->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = p;

    /*无向图还要再插入一次边*/
    p = new struct AdjVNode;
    p->AdjV = E->V1;
    p->Weight = E->Weight;
    p->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = p;
}

LGraph BuildGraph(){
    int Nv;
    cin>>Nv;
    LGraph Graph = CreateGraph(Nv);
    cin>>(Graph->Ne);
    if(Graph->Ne != 0){
        Edge E = new struct ENode;
        for(int i = 0;i < Graph->Ne;i++){
            cin>>E->V1>>E->V2>>E->Weight;
            InsertEdge(Graph,E);
        }
    }
    return Graph;
}

/* 邻接表存储的图 - DFS */

void Visit( Vertex V )
{
    printf("正在访问顶点%d\n", V);
}

/* Visited[]为全局变量，已经初始化为false */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
    PtrToAdjVNode W;

    Visit( V ); /* 访问第V个顶点 */
    Visited[V] = true; /* 标记V已访问 */

    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* 对V的每个邻接点W->AdjV */
        if ( !Visited[W->AdjV] )    /* 若W->AdjV未被访问 */
            DFS( Graph, W->AdjV, Visit );    /* 则递归访问之 */
}

void BFS(LGraph Graph,Vertex V,void (*Visit)(Vertex) )
{
    PtrToAdjVNode P;
    queue<Vertex> q;
    Visit(V);
    Visited[V]  = true;
    q.push(V);
    while(!q.empty()){
        for(P = Graph->G[q.front()].FirstEdge;P;P = P->Next){
            if(!Visited[P->AdjV]){
                Visit(P->AdjV);
                Visited[P->AdjV] = true;
                q.push(P->AdjV);
            }
        }
        q.pop();
    }
}

int main(){
    LGraph Graph = BuildGraph();
    BFS(Graph,1,Visit);
}
