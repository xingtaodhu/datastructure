#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
typedef int ElementType;

/*迭代版本的归并排序*/
void Merge(ElementType A[],ElementType Tmp[],int L,int R,int RightEnd){
    int pL,pR,pT;
    pL = L;
    pT = L;
    pR = R;
    int LeftEnd = R-1;
    while(pL<=LeftEnd && pR<=RightEnd){
        if(A[pL]<=A[pR])
            Tmp[pT++] = A[pL++];
        else
            Tmp[pT++] = A[pR++];
    }
    while(pL<=LeftEnd)
        Tmp[pT++] = A[pL++];
    while(pR<=RightEnd)
        Tmp[pT++] = A[pR++];
}

void Merge_pass(ElementType A[],ElementType Tmp[],int N,int length){/*length = 当前有序子列的长度*/
    int i;
    for(i = 0;N-i>=2*length;i+=2*length){
        Merge(A,Tmp,i,i+length,i+2*length-1);
    }
    if(i+length<=N-1)
        Merge(A,Tmp,i,i+length,N-1);
    else
        for(;i<N;i++)
            Tmp[i] = A[i];
}

void MergeSort(ElementType A[],int N){
    ElementType *Tmp = new ElementType[N];
    int length = 1;
    while(length < N){
        Merge_pass(A,Tmp,N,length);
        length*=2;
        Merge_pass(Tmp,A,N,length);
        length*=2;
    }
    delete Tmp;
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
    MergeSort(A,n);
    finish = clock();
    double duration = (double)(finish-start)/CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    /*
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    */
}


