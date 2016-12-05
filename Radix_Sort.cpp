/* �������� - ��λ���� */
#include <iostream>
/*����Ԫ�������MaxDigit���ؼ��֣�����ȫ��ͬ����Radix*/
#define MaxDigit 10
#define Radix 10

using namespace std;
typedef int ElementType;

/*ͰԪ�ؽڵ�*/
typedef struct Node *PtrToNode;
struct Node {
    int key;
    PtrToNode next;
};

/*Ͱͷ���*/
struct HeadNode {
    PtrToNode head,tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X,int D)
{   /*Ĭ�ϴ�λD=1����λD<=MaxDigit*/
    int d,i;
    for(i=1;i<=D;i++){
        d = X%Radix;
        X = X/Radix;
    }
    return d;
}

void LSDRadixSort(ElementType A[],int N){
    /*�������� - ��λ���� */
    int D,Di,i;
    Bucket B;
    PtrToNode tmp,p,List = NULL;

    for(i=0;i<Radix;i++)/* ��ʼ��ÿ��ͰΪ������ */
        B[i].head = B[i].tail = NULL;
    for(i=0;i<N;i++){/* ��ԭʼ������������ʼ����List */
        tmp = new struct Node;
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    /* ���濪ʼ���� */
    for(D=1;D<=MaxDigit;D++){/* �����ݵ�ÿһλѭ������ */
        /*�����Ƿ���Ĺ���*/
        p = List;
        while(p) {
            Di = GetDigit(p->key,D); /* ��õ�ǰԪ�صĵ�ǰλ���� */
            tmp = p;p = p->next;
            /*����B[Di]��Ͱβ*/
            tmp->next = NULL;
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else{
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }
        /*�������ռ��Ĺ���*/
        List = NULL;
        for(Di = Radix-1;Di>=0;Di--) {/* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
            if(B[Di].head){
                B[Di].tail->next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL;
            }
        }
    }

    /* ��List����A[]���ͷſռ�*/
    for(i=0;i<N;i++) {
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        delete tmp;
    }
}


int main(){
    int N;
    cin>>N;
    ElementType *A = new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    LSDRadixSort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
}
