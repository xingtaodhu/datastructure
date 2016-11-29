typedef int Vertex  /* �ö����±��ʾ���㣬Ϊ���� */

/*����ͼ�ڵ���Ϣ*/
typedef struct{
    int Ne;   //�ߵ�����
    int Nv;   //���������
    WeightType G[MaxVertextNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
}GNode,*PtrToGNode,*MGraph;

/*����߽ڵ�ṹ*/
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
    /*�����<V1,V2>*/
    Graph->G[E->V1][E->V2] = E->Weight;
}
