#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
typedef int ElementType;
void Swap(ElementType *a,ElementType *b)
{
    ElementType t = *a;*a = *b;*b=t;
}

void PercDown(ElementType A[],int p,int N){
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
  int parent,child;
  ElementType X = A[p];
  for(parent = p;parent*2+1 < N;parent = child){
    child = parent*2+1;
    if(child!=N-1 && (A[child]<A[child+1]))
        child++;
    if(X >= A[child]) break;
    else
        A[parent] = A[child];
  }
  A[parent] = X;
}

void HeapSort(ElementType A[],int N)
{/*������*/
    int i;
    for(i = N/2-1;i>=0;i--) /*��������*/
        PercDown(A,i,N);

    for(i=N-1;i>0;i--){
        /*ɾ�����Ѷ�*/
        Swap(&A[0],&A[i]);
        PercDown(A,0,i);
    }
}

int main(){
    clock_t start,finish;
    int n;
    cin>>n;
    int *A = new int[n];
    for(int i=0;i<n;i++)
       A[i] = rand();
    /*
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    */
    start = clock();
    HeapSort(A,n);
    finish = clock();
    double duration = (double)(finish-start)/CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    /*
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    */
}

/*
int main(){
    int N;
    cin>>N;
    ElementType *A = new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    HeapSort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
}
**/

