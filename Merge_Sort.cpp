#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

typedef int ElementType;
void Msort(ElementType A[],ElementType Tmp[],int L,int R);
void Merge(ElementType A[],ElementType Tmp[],int L,int R,int RightEnd);


/*µÝ¹é°æ±¾µÄ¹é²¢ÅÅÐò*/
void Merge_Sort(ElementType A[],int N){
    ElementType *Tmp = new ElementType[N];
    Msort(A,Tmp,0,N-1);
    delete Tmp;
}

void Msort(ElementType A[],ElementType Tmp[],int L,int R){
    if(L<R){
        int Center = (R+L)/2;
        Msort(A,Tmp,L,Center);
        Msort(A,Tmp,Center+1,R);
        Merge(A,Tmp,L,Center+1,R);
    }
}

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
    for(int i = L;i <= RightEnd;i++){
        A[i] = Tmp[i];
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
    Merge_Sort(A,n);
    finish = clock();
    double duration = (double)(finish-start)/CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    /*
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    */
}


