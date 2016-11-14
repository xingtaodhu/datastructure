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
    bt->node = new Node[n];
    int *a = new int[n];  //辅助查找根节点的数组
    for(int j = 0;j < n;j++){
        a[j] = 1;
    }

    int i = 0;
    while(i++ < n){
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
    }
    for(int k = 0;k < n;k++){
        if(a[k]){
            bt->root = k;
            break;
        }
    }
    return bt;
}

bool istonggou(BTree t1,BTree t2,char c1,char c2){
    if(c1=='-' && c2=='-')
        return true;
    else if((c1=='-'&&c2!='-') || (c1!='-'&&c2=='-'))
            return false;
    else{
        if(t1->node[c1-'0'].data != t2->node[c2-'0'].data)
            return false;
        else
            return (istonggou(t1,t2,t1->node[c1-'0'].left,t2->node[c2-'0'].left)&&istonggou(t1,t2,t1->node[c1-'0'].right,t2->node[c2-'0'].right))
            || (istonggou(t1,t2,t1->node[c1-'0'].left,t2->node[c2-'0'].right)&&istonggou(t1,t2,t1->node[c1-'0'].right,t2->node[c2-'0'].left));
    }
}


int main(){
    BTree t1 = read();
    BTree t2 = read();
    int r1 = t1->root;
    int r2 = t2->root;
    if(istonggou(t1,t2,(char)r1,(char)r2)){
        cout<<"YES";
    }else
        cout<<"NO";
    system("pause");
    return 0;
}
