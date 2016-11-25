/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex;     /*�ö����±��ʾ���㣬Ϊ����*/
typedef int WeightType; /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;  /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ���*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertext V1,V2;    <V1,V2>
    WeightType Weight; /*Ȩ��*/
};
typedef PtrToENode Edge;

/*ͼ���Ķ���*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;    /* ������*/
    int Ne;    /*����*/
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};

typedef PtrToGNode MGraph;  /*���ڽӾ���洢��ͼ����*/

MGraph CreateGraph(int VertexNum)
{/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V,W;
    MGraph Graph;
    Graph = new struct GNode;
    Graph->Nv = VerteGxNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӾ��� */
    /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
    for (V=0; V<Graph->Nv; V++)
        for (W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
    Graph->G[E->V1][E->V2] = E->Weight;
}
