#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n,*a;
    int ThisSum = 0,MaxSum = 0;
    cin>>n;
    int t = 0,y = n-1,x = t;  //t暂存目前计算的子列初始位置
    a = (int*)malloc(n*sizeof(int));
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < n;i++) {
        ThisSum += a[i];
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
            x = t;
            y = i;
        }
        else if(ThisSum == 0 && MaxSum == 0)
                x = t,y = i;
        else if(ThisSum < 0) {
            ThisSum = 0;
            t = i + 1;
        }


    }
    cout<<MaxSum<<" "<<a[x]<<" "<<a[y];
}
