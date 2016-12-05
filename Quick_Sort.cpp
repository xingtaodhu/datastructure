#include <iostream>
#define Cutoff 100
using namespace std;
typedef int ElementType;

void Swap(ElementType* a,ElementType* b){
    ElementType t;
    t = *a;
    *a = *b;
    *b = t;
}

void Insertion_Sort(ElementType A[],int N){
    for(int i=1;i<N;i++){
        int j = i;
        ElementType temp = A[j];
        for(;j>0;j--){
            if(A[j-1]<=temp)
                break;
            else
                A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

ElementType Median3(ElementType A[],int Left,int Right){
    int Center = (Left+Right)/2;
    if(A[Left] > A[Center])
        Swap(&A[Left],&A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left],&A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center],&A[Right]);
    Swap(&A[Center],&A[Right-1]);
    return A[Right-1];

}


void QuickSort(ElementType A[],int Left,int Right){
    if(Right-Left>=Cutoff){
        int pivot = Median3(A,Left,Right);
        int i = Left;
        int j = Right-1;
        while(true){
            while(A[++i]<pivot){}
            while(A[--j]>pivot){}
            if(i<j)
                Swap(&A[i],&A[j]);
            else
                break;
        }
        Swap(&A[i],&A[Right-1]);

        QuickSort(A,Left,i-1);
        QuickSort(A,i+1,Right);
    }else
        Insertion_Sort(A+Left,Right-Left+1);

}


/*
void QuickSort(ElementType A[],int Left,int Right){//È¡A[Left]×öpivotµã
    if(Right-Left>=Cutoff){
        int pivot = A[Left];
        int i = Left;
        int j = Right;
        while(true){
            while(A[++i]<pivot){}
            while(A[j--]>pivot){}
            if(i<j)
                Swap(&A[i],&A[j]);
            else
                break;
        }
        Swap(&A[j],&A[Left]);

        QuickSort(A,Left,j-1);
        QuickSort(A,j+1,Right);
    }else
        Insertion_Sort(A+Left,Right-Left+1);

}
*/

void Quick_Sort(ElementType A[],int N){
    QuickSort(A,0,N-1);
}

int main(){
    int N;
    cin>>N;
    ElementType *A = new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    Quick_Sort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
}
