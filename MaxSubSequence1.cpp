#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int n,*a;
    cin>>n;
    a = (int*)malloc(n*sizeof(int));
    for(int i = 0;i < n;i++)
        cin>>a[i];
    int ThisSum,MaxSum = 0;
    int x=0,y=n-1; //最大子列和起始位置
    for(int i = 0;i < n;i++){
        ThisSum = 0;
        for(int j = i;j < n;j++){
            ThisSum += a[j];
            if(ThisSum > MaxSum){
                MaxSum = ThisSum;
                x=i,y=j;
            }
            if(ThisSum == 0 && MaxSum == 0){
                x=i,y=j;
            }
        }
    }
    cout<<MaxSum<<" "<<a[x]<<" "<<a[y];
}
