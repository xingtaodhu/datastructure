/* ͼ���ڽӱ��ʾ�� */

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;   /* �ڽӵ��±�*/
    WeightType Weight;  /*��Ȩ��*/
    PtrToAdjVNode Next;   /*ָ����һ���ڽӵ��ָ��*/
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVerTexNum];

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

LGraph CreateGraph( int VertexNum )
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V;
    LGraph Graph;

    Graph = new struct GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0;V < Graph->Nv;V++){
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge( LGraph Graph, Edge E ){
    PtrToAdjVNode NewNode;
    NewNode = new struct AdjVNode;
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
}
