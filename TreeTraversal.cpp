#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MAXSIZE 30

int preOrder[MAXSIZE];
int inOrder[MAXSIZE];
int postOrder[MAXSIZE];

void Solve(int preL, int inL, int postL, int n);

int main()
{
    for (int i = 0; i < MAXSIZE; i++)    //初始化数组
    {
        preOrder[i] = 0;
        inOrder[i] = 0;
        postOrder[i] = 0;
    }
    stack<int> inputStack;
    int nodeNum;
    cin >> nodeNum;
    int i, data;
    int preIndex = 0, inIndex = 0, postIndex = 0;
    string str;
    for (i = 0; i < 2 * nodeNum; i++)
    {
        cin >> str;
        if (str == "Push")
        {
            cin >> data;
            preOrder[preIndex++] = data;
            inputStack.push(data);
        }
        else if (str == "Pop")
        {
            inOrder[inIndex++] = inputStack.top();
            inputStack.pop();
        }
    }
    Solve(0, 0, 0, nodeNum);
    for (int i = 0; i < nodeNum; i++)
    {
        if ( i == nodeNum - 1 )
        {
            cout << postOrder[i] << endl;
        }
        else
        {
            cout << postOrder[i] << ' ';
        }
    }
}

void Solve(int preL, int inL, int postL, int n)
{
    if(n == 0)
        return;
    if(n == 1){
        postOrder[postL] = preOrder[preL];
        return;
    }
    int root = preOrder[preL];
    postOrder[postL+n-1] = root;
    int i;
    for(i = 0;i < n;i++){
        if(inOrder[inL+i] == root)
            break;
    }
    int L,R;
    L = i;
    R = n-L-1;
    Solve(preL+1,inL,postL,L); //递归构建左子树中序
    Solve(preL+1+L,inL+L+1,postL+L,R); //递归构建右子树中序
}
