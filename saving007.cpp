#include <iostream>
#include <cmath>
using namespace std;
bool Visited[100] = {false}; //��ǽڵ��Ƿ���ʹ�������
int dis,num; //007����Ծ����,���������
struct Node{
    int x;
    int y;
};
Node nodes[100];

bool FirstJump(int i){//��ԭ���ܷ������ڵ�i
    int x = nodes[i].x,y = nodes[i].y;
    if(x*x + y*y <= (dis+7.5)*(dis+7.5))
        return true;
    return false;
}


bool IsSafe(int i){//��i���ܷ��ϰ�
    int x = nodes[i].x;
    int y = nodes[i].y;
    if(abs(x-50)<=dis || abs(x+50)<=dis || abs(y-50)<=dis || abs(y+50)<=dis)
        return true;
    return false;
}

bool reachable(int i,int j){//�ڵ�i,j֮���Ƿ�ɴ�
    int x1,x2,y1,y2;
    x1 = nodes[i].x;
    x2 = nodes[j].x;
    y1 = nodes[i].y;
    y2 = nodes[j].y;
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= dis*dis)
        return true;
    return false;
}

bool DFS(int i){ //������ȱ���
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

void IsSaving(){ //007�ܷ�þ�
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
