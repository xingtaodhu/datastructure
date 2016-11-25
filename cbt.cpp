#include <iostream>
#include <cmath>
#include <cstdlib>
#define MAXSIZE 1000

using namespace std;

int A[MAXSIZE];
int T[MAXSIZE];

int GetLeftLength(int n);
int compare(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

void solve(int ALeft,int ARight,int TRoot){
    int n;
    n = ARight-ALeft+1;
    if(n == 0)
        return;
    int L = GetLeftLength(n);    //计算N个节点的完全二叉树的左子树的节点数
    T[TRoot] = A[ALeft+L];
    int Left = TRoot*2+1;       //左子树的根节点
    int Right = 2*(TRoot + 1);  //右子树的根节点
    solve(ALeft,ALeft+L-1,Left);
    solve(ALeft+L+1,ARight,Right);
}

int GetLeftLength(int n){
    int H = floor(log(n+1)/log(2));
    int x = n-pow(2,H)+1;
    return min(x,(int)pow(2,H-1))+pow(2,H-1)-1;
}

int main(){
    int N,m;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>m;
        A[i] = m;
    }
    qsort(A,N,sizeof(int),compare);
    solve(0,N-1,0);
    for(int i = 0;i < N;i++){
        if(i == N-1)
            cout<<T[i];
        else
            cout<<T[i]<<" ";
    }
}
