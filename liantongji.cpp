#include <iostream>
#include <queue>
using namespace std;
#define MaxVertexNum 10

bool Visited[MaxVertexNum] = {false};

typedef int WeightType;
typedef int Vertex;

typedef struct ENode{
    Vertex V1,V2;
    WeightType Weight = 0;
} *Edge;
struct AdjVNode{
    Vertex AdjV;
    WeightType Weight = 0;
    struct AdjVNode *Next;
};
typedef struct AdjVNode *PtrToAdjVNode;
typedef PtrToAdjVNode AdjList[MaxVertexNum];

typedef struct GNode{
    int Ne;
    int Nv;
    AdjList G;
}*PtrToGNode;
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph = new struct GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0 ;V < Graph->Nv;V++)
    {
        Graph->G[V] = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E)
{
    PtrToAdjVNode p = new struct AdjVNode;
    p->AdjV = E->V2;
    p->Weight = E->Weight;

    PtrToAdjVNode cur = Graph->G[E->V1];
    if(!cur){
        p->Next = NULL;
        Graph->G[E->V1] = p;
    }else if(!(cur->Next)){
        if(cur->AdjV > p->AdjV){
            p->Next = cur;
            Graph->G[E->V1] = p;
        }else{
            p->Next = NULL;
            cur->Next = p;
        }
    }else{
        PtrToAdjVNode pre = cur;
        cur = cur->Next;
        for(;cur && cur->AdjV < p->AdjV;pre = cur,cur = cur->Next)
            ;
        p->Next = pre->Next;
        pre->Next = p;
    }


    p = new struct AdjVNode;
    p->AdjV = E->V1;
    p->Weight = E->Weight;
    cur = Graph->G[E->V2];
    if(!cur){
        p->Next = NULL;
        Graph->G[E->V2] = p;
    }else if(!(cur->Next)){
        if(cur->AdjV > p->AdjV){
            p->Next = cur;
            Graph->G[E->V2] = p;
        }else{
            p->Next = NULL;
            cur->Next = p;
        }
    }else{
        PtrToAdjVNode pre = cur;
        cur = cur->Next;
        for(;cur && cur->AdjV < p->AdjV;pre = cur,cur = cur->Next)
            ;
        p->Next = pre->Next;
        pre->Next = p;
    }
}

void Visit(Vertex V){
    cout<<V<<" ";
}

void DFS(LGraph Graph,Vertex V)
{   /*以顶点V出发做深度优先遍历*/
    PtrToAdjVNode P;
    Visit(V);
    Visited[V] = true;
    for(P = Graph->G[V];P;P = P->Next){
        if(!Visited[P->AdjV]){
            DFS(Graph,P->AdjV);
        }
    }
}

void BFS(LGraph Graph,Vertex V)
{   /*以顶点V出发做深度优先遍历*/
    PtrToAdjVNode W;
    queue<Vertex> q;
    Visit(V);
    Visited[V] = true;
    q.push(V);
    while(!q.empty()){
        for(W=Graph->G[q.front()];W;W = W->Next){
            if(!Visited[W->AdjV]){
                Visit(W->AdjV);
                Visited[W->AdjV] = true;
                q.push(W->AdjV);
            }
        }
        q.pop();
    }

}

void LianTongJi(LGraph Graph){//深度优先遍历联通集
    Vertex V;
    for(V = 0;V < Graph->Nv;V++){
        if(!Visited[V]){
            cout<<"{ ";
            DFS(Graph,V);
            cout<<"}"<<endl;
        }
    }
    for(Vertex W = 0;W < MaxVertexNum;W++)
        Visited[W] = false;

    for(V = 0;V < Graph->Nv;V++){
        if(!Visited[V]){
            cout<<"{ ";
            BFS(Graph,V);
            cout<<"}"<<endl;
        }
    }
}





LGraph Build(){
    int n,m;
    cin>>n>>m;
    LGraph Graph = CreateGraph(n);
    while(m--){
        Edge E = new struct ENode;
        cin>>E->V1>>E->V2;
        InsertEdge(Graph,E);
    }
    return Graph;
}

int main(){
    LGraph Graph = Build();
    LianTongJi(Graph);
}
