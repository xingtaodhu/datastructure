#include <iostream>
#include <string>
using namespace std;
#define MaxNum 64

typedef struct TreeNode{
    int weight = 0;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef TreeNode *PtrToTreeNode;
typedef PtrToTreeNode HuffmanTree;

typedef struct HeapStruct{
    PtrToTreeNode* data;
    int capacity;
    int size;
} *MinHeap;

typedef struct JNode{
    int Flag = 0;
    struct JNode *left = NULL;
    struct JNode *right = NULL;
}JNode;

int A[MaxNum] = {0};

MinHeap Create(int capacity){//创建空堆
    MinHeap H = new struct HeapStruct;
    H->data = new PtrToTreeNode[capacity+1];
    H->capacity = capacity;
    H->size = 0;
    H->data[0] = new TreeNode;
    H->data[0]->weight = -10001;
    H->data[0]->left = NULL;
    H->data[0]->right = NULL;
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

void Insert(MinHeap H,PtrToTreeNode x){//堆中插入一个元素
    int i = ++H->size;
    while(H->data[i/2]->weight >= x->weight){
        H->data[i] = H->data[i/2];
        i/=2;
    }
    H->data[i] = x;
}

PtrToTreeNode DeleteMin(MinHeap H){//堆中删除一个元素
    if(IsEmpty(H)){
        cout<<"堆为空"<<endl;
        return NULL;
    }
    PtrToTreeNode min = H->data[1];
    PtrToTreeNode temp = H->data[H->size--];
    int parent,child;
    for(parent = 1;parent*2 <= H->size;parent = child){
        child = parent*2;
        if(child != H->size && (H->data[child]->weight>H->data[child+1]->weight))
            child++;
        if(temp->weight <= H->data[child]->weight)
            break;
        else
            H->data[parent] = H->data[child];
    }
    H->data[parent] = temp;
    return min;
}

MinHeap readData(int N){
    MinHeap H = Create(MaxNum);
    char c;
    int f;
    PtrToTreeNode T = NULL;
    for(int i = 0;i < N;i++){
        cin>>c;
        cin>>f;
        A[i] = f;
        T = new TreeNode;
        T->left = NULL;
        T->right = NULL;
        T->weight = f;
        Insert(H,T);
    }
    return H;
}

HuffmanTree Build(int N) {
    MinHeap H = readData(N);
    int size = H->size;
    for(int i = 0;i < size-1;i++){
        PtrToTreeNode T = new struct TreeNode;
        T->left = DeleteMin(H);
        T->right = DeleteMin(H);
        T->weight = T->left->weight+T->right->weight;
        Insert(H,T);
    }
    return DeleteMin(H);
}

int getWPL(HuffmanTree T,int Depth){
    if((T->left == NULL) && (T->right == NULL))
        return Depth*T->weight;
    return getWPL(T->left,Depth+1)+getWPL(T->right,Depth+1);
}

bool Judge(string S,JNode *J)
{
    int i = 0;
    for(;i<S.length();i++){
        if(S[i] == '0'){
            if(J->left == NULL){
                JNode *J_0 = new struct JNode;
                J->left = J_0;
            }else{
                if(J->left->Flag == 1)
                    return false;
            }
            J = J->left;
        }else{
           if(J->right == NULL) {
                JNode *J_1 = new struct JNode;
                J->right = J_1;
           }else{
               if(J->right->Flag == 1)
                    return false;
           }
           J = J->right;
        }
    }
    J->Flag == 1;
    if((J->left==NULL) && (J->right==NULL))
            return true;
    else
            return false;

}

int main(){
    int N;
    cin>>N;
    HuffmanTree T = Build(N);
    int codelen = getWPL(T,0);
    int k;
    cin>>k;

    while(k--){
        int count = 0;
        char c;
        string S;
        JNode *J = new struct JNode;
        bool result = true;
        for(int i = 0;i < N;i++){
            cin>>c>>S;
            count += A[i]*S.length();
            if(result){
                if(!Judge(S,J))
                    result = false;
            }
        }
        delete J;
        if((count==codelen)&&(result))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}



