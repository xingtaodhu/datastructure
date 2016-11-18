#include <iostream>
using namespace std;
typedef int ElementType;
struct AVLNode{
    ElementType data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};
typedef struct AVLNode *AVLTree;

int GetHeight(AVLTree T){//获取二叉树的高度
    if(!T)
        return -1;
    else
        return max(GetHeight(T->left),GetHeight(T->right))+1;
}

AVLTree SingleLeftRotation(AVLTree A)
{
    /*注意：A必须有一个左儿子B*/
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max(GetHeight(A->left),GetHeight(A->right))+1;
    B->height = max(GetHeight(B->left),A->height)+1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max(GetHeight(A->left),GetHeight(A->right))+1;
    B->height = max(GetHeight(B->right),A->height)+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->left = SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->right = SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}

AVLTree AVL_Insert(AVLTree T,ElementType X){
    if(!T){
        T = new struct AVLNode;
        T->data = X;
        T->left = T->right = NULL;
        T->height = 0;
    }else if(X<T->data){
        T->left = AVL_Insert(T->left,X);
        if(GetHeight(T->left)-GetHeight(T->right)>1){
            if(X<T->left->data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }else if(X>T->data) {
        T->right = AVL_Insert(T->right,X);
        if(GetHeight(T->right) - GetHeight(T->left) > 1){
            if(X>T->right->data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
    T->height = max(GetHeight(T->left),GetHeight(T->right))+1;
    return T;
}

int main()
{
    int n,m;
    AVLTree T = NULL;
    cin>>n;
    while(n--){
        cin>>m;
        T = AVL_Insert(T,m);
    }
    cout<<T->data;
}
