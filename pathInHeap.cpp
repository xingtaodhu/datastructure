#include <iostream>
#define MinData -10001
#define MaxData 10001
using namespace std;

typedef struct HeapStruct{
    int* data;
    int capacity;
    int size;
} *MinHeap;


MinHeap Create(int capacity){//创建空堆
    MinHeap H = new struct HeapStruct;
    H->data = new int[capacity+1];
    H->capacity = capacity;
    H->size = 0;
    H->data[0] = MinData;
    return H;
}

bool IsFull(MinHeap H){
    if(H)
        return H->size == H->capacity;
    return false;
}

bool IsEmpty(MinHeap H){
    if(H)
        return H->size == 0;
    return true;
}

void Insert(MinHeap H,int x){//堆中插入一个元素
    int i = ++H->size;
    while(H->data[i/2] >= x){
        H->data[i] = H->data[i/2];
        i/=2;
    }
    H->data[i] = x;
}

int DeleteMin(MinHeap H){//堆中删除一个元素
    if(IsEmpty(H)){
        cout<<"堆为空"<<endl;
        return H->data[0];
    }
    int min = H->data[1];
    int temp = H->data[H->size--];
    int parent,child;
    for(parent = 1;parent*2 <= H->size;parent = child){
        child = parent*2;
        if(child != H->size && (H->data[child]>H->data[child+1]))
            child++;
        if(temp <= H->data[child])
            break;
        else
            H->data[parent] = H->data[child];
    }
    H->data[parent] = temp;
    return min;
}


void printPath (MinHeap H,int p){//打印位置p的元素到根节点的路径
    if(p > 0 && p <= H->size){
        for(int i = p;i > 0; i/=2){
            if(i == 1)
                cout<<H->data[i]<<endl;
            else
                cout<<H->data[i]<<" ";

        }
    }
}

int main(){
    int m,n;
    cin>>n>>m;
    MinHeap H = Create(n);
    int x,y;
    while(n--){
        cin>>x;
        Insert(H,x);
    }
    while(m--){
        cin>>y;
        printPath(H,y);
    }
    return 0;
}



