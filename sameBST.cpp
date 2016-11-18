#include <iostream>
using namespace std;

typedef struct BinNode{
    int data;
    struct BinNode* left;
    struct BinNode* right;
}*BinTree;

bool isSame(BinTree bt1,BinTree bt2){
    if(!bt1 && !bt2)
        return true;
    else if((!bt1&&bt2) || (bt1&&!bt2))
        return false;
    else if(bt1->data != bt2->data)
        return false;
    else
        return isSame(bt1->left,bt2->left) && isSame(bt1->right,bt2->right);
}

BinTree insert(BinTree bt,int data){
    if(!bt){
        bt = new struct BinNode;
        bt->data = data;
        bt->left = NULL;
        bt->right = NULL;
    }else{
        if(data>bt->data)
            bt->right = insert(bt->right,data);
        else if(data<bt->data)
            bt->left = insert(bt->left,data);
    }
    return bt;
}

BinTree createBST(int n){
    int data;
    BinTree bt = NULL;
    for(int i = 0;i < n;i++){
        cin>>data;
        bt = insert(bt,data);
    }
    return bt;
}

int main(){
    int n,m;
    BinTree BT1,TEMP;
    while(cin>>n){
        if(n == 0)
            break;
        cin>>m;
        BT1 = createBST(n);
        for(int i = 0;i<m;i++){
            TEMP =  createBST(n);
            if(isSame(BT1,TEMP))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}

