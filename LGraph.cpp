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

/*����߽ڵ�ṹ*/
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
    DataType Data;  /*�涥�������*/
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

    /*����ͼ��Ҫ�ٲ���һ�α�*/
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

/* �ڽӱ�洢��ͼ - DFS */

void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}

/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;

    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */

    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )    /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
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
