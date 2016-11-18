#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    char data;
    char left;
    char right;
}Node;

typedef struct BNode{
    Node *node;
    int  root;
}*BTree;


BTree read(){//根据输入生成二叉树
    int n;
    cin>>n;
    BTree bt = new struct BNode;
    if(n == 0){
        bt->node = NULL;
        bt->root = 0;
        return bt;
    }
    bt->node = (Node*)malloc(sizeof(Node)*n);
    int *a = (int*)malloc(sizeof(int)*n); //辅助查找根节点的数组
    for(int j = 0;j < n;j++){
        a[j] = 1;
    }

    int i = 0;
    while(i < n){
        char m,s,p;
        cin>>m>>s>>p;
        bt->node[i].data = m;
        bt->node[i].left = s;
        bt->node[i].right = p;
        if(s>='0' && s<='9'){
            a[s-'0'] = !a[s-'0'];
        }
        if(p>='0' && p<='9'){
            a[p-'0'] = !a[p-'0'];
        }
        i++;
    }
    for(int k = 0;k < n;k++){
        if(a[k]){
            bt->root = k;
            break;
        }
    }
    return bt;
}


bool istonggou(BTree t1,BTree t2,char r1,char r2){
    if(r1=='-' && r2=='-')
        return true;
    else if((r1=='-'&&r2!='-') || (r1!='-'&&r2=='-'))
        return false;
    else if(t1->node[r1-'0'].data != t2->node[r2-'0'].data)
        return false;
    else if(t1->node[r1-'0'].left=='-' && t2->node[r2-'0'].left=='-')
        return istonggou(t1,t2,t1->node[r1-'0'].right,t2->node[r2-'0'].right);
    else if(t1->node[r1-'0'].left!='-' && t2->node[r2-'0'].left!='-'){
        if(t1->node[t1->node[r1-'0'].left-'0'].data == t2->node[t2->node[r2-'0'].left-'0'].data)
            return istonggou(t1,t2,t1->node[r1-'0'].left,t2->node[r2-'0'].left) && istonggou(t1,t2,t1->node[r1-'0'].right,t2->node[r2-'0'].right);
        else
            return istonggou(t1,t2,t1->node[r1-'0'].left,t2->node[r2-'0'].right) && istonggou(t1,t2,t1->node[r1-'0'].right,t2->node[r2-'0'].left);
    }else
       return istonggou(t1,t2,t1->node[r1-'0'].left,t2->node[r2-'0'].right) && istonggou(t1,t2,t1->node[r1-'0'].right,t2->node[r2-'0'].left);
}

int main(){
    BTree t1 = read();
    BTree t2 = read();
    int root1 = t1->root;
    int root2 = t2->root;
    if(t1->node==NULL && t2->node==NULL){
        cout<<"Yes\n";
        return 0;
    }
    char r1 = '0'+root1;
    char r2 = '0'+root2;
    if(istonggou(t1,t2,r1,r2))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
