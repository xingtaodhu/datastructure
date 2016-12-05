#include <iostream>
using namespace std;
typedef int ElementType;

void Table_Sort(ElementType A[],ElementType table[],int N){
    for(int i=0;i<N;i++)
        table[i] = i;
    for(int i=1;i<N;i++){
        int j=i;
        ElementType temp = A[j];
        for(;j>0;j--){
            if(temp>=A[table[j-1]])
                break;
            else
                table[j] = table[j-1];
        }
        table[j] = i;
    }
}

int main(){
    int N;
    cin>>N;
    ElementType *A = new int[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    ElementType *table = new int[N];
    Table_Sort(A,table,N);
    for(int i=0;i<N-1;i++)
        cout<<A[table[i]]<<" ";
    cout<<A[table[N-1]];
}

