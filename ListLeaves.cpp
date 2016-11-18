#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    char left;
    char right;
}Node;

typedef struct BNode{
    Node* node;
    int root;
}*Tree;

Tree read(){
    int n;
    char s,p;
    cin>>n;
    Tree t = new struct BNode;
    int* check = new int[n];
    for(int i = 0;i < n;i++){
        check[i] = 1;
    }
    t->node = new Node[n];
    int i = 0;
    while(i < n){
        cin>>s>>p;
        t->node[i].left = s;
        t->node[i].right = p;
        if(s>='0' && s<='9'){
            check[s-'0'] = 0;
        }
        if(p>='0' && p<='9'){
            check[p-'0'] = 0;
        }
        i++;
    }
    for(int i = 0;i < n;i++){
        if(check[i]){
            t->root = i;
            break;
        }
    }
    return t;
}

void printLeaves(Tree t){
    int root = t->root;
    int flag = 0;
    queue<int> q;
    if(t->node)
        q.push(root);
    while(!q.empty()){
        int temp = q.front();
        if(t->node[temp].left != '-')
            q.push(t->node[temp].left-'0');
        if(t->node[temp].right != '-')
            q.push(t->node[temp].right-'0');
        if(t->node[temp].left=='-' && t->node[temp].right=='-'){
            if(!flag){
                cout<<temp;
                flag = 1;
            }else
                cout<<" "<<temp;
        }
        q.pop();
    }
}
int main(){
    Tree t = read();
    printLeaves(t);
}
