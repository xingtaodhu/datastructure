typedef int Vertex  /* 用顶点下标表示顶点，为整型 */

/*定义图节点信息*/
typedef struct{
    int Ne;   //边的数量
    int Nv;   //顶点的数量
    WeightType G[MaxVertextNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
}GNode,*PtrToGNode,*MGraph;

/*定义边节点结构*/
typedef struct ENode{
    Vertex V1,V2;
    WeightType Weight;
}*PtrToENode;

typedef PtrToENode Edge;


MGraph CreateGraph(int VertexNum){
    MGraph Graph;
    Vertex V,W;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Ne = 0;
    Graph->Nv = VertexNum;
    for(V=0;V < Graph->Nv;V++){
        for(W;W < Graph->Nv;W++){
            Graph->G[V][W] = 0;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    /*插入边<V1,V2>*/
    Graph->G[E->V1][E->V2] = E->Weight;
}
