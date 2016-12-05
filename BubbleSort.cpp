#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
typedef int ElementType;
void Swap(ElementType *a,ElementType *b){
    ElementType t = *a;*a = *b;*b=t;
}

void Bubble_Sort(ElementType A[],int N){

    for(int p = N-1;p>0;p--){
        int flag = 0;
        for(int i = 0;i<p;i++){
            if(A[i]>A[i+1]){
                Swap(&A[i],&A[i+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
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
    Bubble_Sort(A,n);
    finish = clock();
    double duration = (double)(finish-start)/CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );

    //for(int i=0;i<n;i++)
    //    cout<<A[i]<<" ";

}

/*
int main(){
    int N;
    cin>>N;
    ElementType *A = new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    Bubble_Sort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
}
**/
