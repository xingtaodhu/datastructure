#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MaxSize 100000
struct TNode {
    int data;
    int next;
};
struct TNode A[MaxSize];
struct Node {
    int address;
    int data;
    int next_address;
    struct Node* next;
};

typedef struct Node *List;


List read(int *i){
    List head = (List)malloc(sizeof(struct Node));
    head->next = NULL;
    struct Node *rear = head,*temp;
    int head_addr,node_count,reverse_node_count;
    cin>>head_addr>>node_count>>reverse_node_count;
    *i = node_count/reverse_node_count;
    int m,n,p;
    while(node_count--){
        cin>>m>>n>>p;
        A[m].data = n;
        A[m].next = p;
    }
    int position = head_addr;
    while(position != -1){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->address = position;
        temp->data = A[position].data;
        temp->next_address = A[position].next;
        position = A[position].next;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
    return head;
}

void printList(List L){
    struct Node *temp = L->next;
    while(temp){
        if(temp->next_address!=-1)
            printf("%05d %d %05d\n",temp->address,temp->data,temp->next_address);
        else
            printf("%05d %d %d\n",temp->address,temp->data,temp->next_address);
        temp = temp->next;
    }
}

void reverse_List(List L) {
    struct Node *pre,*cur = NULL,*next = NULL;
    pre = L->next;
    if(pre) {
        cur = pre->next;
        pre->next = NULL;
        pre->next_address = -1;
    }
    while(cur){
       next = cur->next;
       cur->next = pre;
       cur->next_address = pre->address;
       pre = cur;
       if(!next){
        L->next = cur;
       }
       cur = next;
    }
}

List reverse_List(List L,int K){
    int count = 1;
    struct Node *cur = L->next,*old = cur->next;
    struct Node *temp;
    while(count++<K){
        temp = old->next;
        old->next = cur;
        cur = old;
        old = temp;
    }
    L->next->next = old;
    L->next = cur;
    return cur;

}


int main(){
    int i;
    List L = read(i);
    cout<<endl;
    printList(L);
    system("pause");
}
