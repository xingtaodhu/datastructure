#include <iostream>
#define MaxSize 10005

using namespace std;
typedef struct Computer{
    int number;
    int parent;
} *SetComputer;

SetComputer s = new struct Computer[MaxSize];

int N;
void input_connect();
void check_connect();
void stop_connect();
int find(int position);
int finds(int number);
void unions(int root1,int root2);

int main(){
    cin>>N;
    for(int i = 0;i < N;i++){
        s[i].number = i+1;
        s[i].parent = -1;
    }
    char op;
    do{
        cin>>op;
        switch(op)
        {
            case 'I':
                input_connect();
                break;
            case 'C':
                check_connect();
                break;
            case 'S':
                stop_connect();
                break;
        }
    }
    while(op != 'S');
    return 0;
}

void input_connect(){
    int a,b;
    cin>>a>>b;
    int root1 = finds(a);
    int root2 = finds(b);
    if(root1 != root2)
        unions(root1,root2);
}

void check_connect(){
    int a,b;
    cin>>a>>b;
    int root1 = finds(a);
    int root2 = finds(b);
    if(root1 == root2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}

void stop_connect(){
    int cnt = 0;
    for(int i = 0;i < N;i++){
        if(s[i].parent < 0)
            cnt++;
    }
    if(cnt == 1)
        cout<<"The network is connected."<<endl;
    else
        cout<<"There are "<<cnt<<" components."<<endl;
}

int finds(int number)
{   /*
    路径压缩：就是在查找集合元素的根节点的时候，
    一旦找到根节点，在回溯的过程中，
    将其子节点的值全部跟改为根结点的值。
    这样只在第一次查找的时候比较耗时，
    但在后续的查找过程中，将会节省大量的时间。
    **/
    int i;
    for(i = 0;i < MaxSize && s[i].number != number;i++)
    if(i >= MaxSize)
        return -1;

    return find(i);
}

//用到了路径压缩
int find(int position)
{
    if(s[position].parent<0)
    {
        return position;
    }
    return s[position].parent = find(s[position].parent);
}

void unions(int root1,int root2)
{
    if(s[root1].parent < s[root2].parent){
        s[root1].parent += s[root2].parent;
        s[root2].parent = root1;
    }else{
        s[root2].parent += s[root1].parent;
        s[root1].parent = root2;
    }

}

