#include <iostream>
#include <cmath>
using namespace std;
bool Visited[100] = {false}; //标记节点是否访问过的数组
int dis,num; //007的跳跃距离,鳄鱼的数量
struct Node{
    int x;
    int y;
};
Node nodes[100];

bool FirstJump(int i){//从原点能否跳到节点i
    int x = nodes[i].x,y = nodes[i].y;
    if(x*x + y*y <= (dis+7.5)*(dis+7.5))
        return true;
    return false;
}


bool IsSafe(int i){//从i点能否上岸
    int x = nodes[i].x;
    int y = nodes[i].y;
    if(abs(x-50)<=dis || abs(x+50)<=dis || abs(y-50)<=dis || abs(y+50)<=dis)
        return true;
    return false;
}

bool reachable(int i,int j){//节点i,j之间是否可达
    int x1,x2,y1,y2;
    x1 = nodes[i].x;
    x2 = nodes[j].x;
    y1 = nodes[i].y;
    y2 = nodes[j].y;
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= dis*dis)
        return true;
    return false;
}

bool DFS(int i){ //深度优先遍历
    Visited[i]  =true;
    bool answer;
    if(IsSafe(i))
        return true;
    for(int j = 0;j < num;j++)
    {
        if(!Visited[j] && reachable(i,j)){
            answer = DFS(j);
        }
        if(answer)
            break;
    }
    return answer;
}

void IsSaving(){ //007能否得救
    bool answer = false;
    for(int i = 0;i < num;i++){
        cin>>nodes[i].x>>nodes[i].y;
    }
    for(int i = 0;i < num;i++){
        if(!Visited[i] && FirstJump(i))
            answer = DFS(i);
        if(answer)
            break;
    }
    if(answer)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){
    cin>>num>>dis;
    IsSaving();
}
