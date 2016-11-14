#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

#define MaxSize 1000
//Stack implementation with array
typedef struct stack{
    int Data[MaxSize];
    int cap;
    int top;
}Stack;

int N,M,K;

Stack* CreateStack() {
    Stack *PtrS  = (Stack*)malloc(sizeof(struct stack));
    PtrS->top = -1;
    PtrS->cap = MaxSize;
    return PtrS;
}

void Push(Stack *PtrS,int ele) {
    if(PtrS->top == PtrS->cap-1){
        cout<<"FULL";
        return;
    }
    PtrS->Data[++(PtrS->top)] = ele;
}

int top(Stack *PtrS) {
    return PtrS->Data[PtrS->top];
}

void Pop(Stack *PtrS){
    if(PtrS->top == -1){
        cout<<"Empty";
        return;
    }
    PtrS->top--;
}

int check_stack(int v[]){
    Stack *s = CreateStack();
    Push(s,0); //dummy element,as sential
    int idx = 0;
    int num = 1;
    while(idx < N){
         while(v[idx] > top(s) && s->top < M) {
            Push(s,num++);
         }
         if(v[idx] == top(s)){
            Pop(s);
            idx++;
         }else
            return 0;
    }
    return 1;

}


int main(){
    cin>>M>>N>>K;
    int *v = (int *)malloc(sizeof(int)*N);
    while(K--){
        for(int i = 0;i < N;i++) {
            cin>>v[i];
        }
        if(check_stack(v))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

