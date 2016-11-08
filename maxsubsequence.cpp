#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n,*a;
    int ThisSum = 0,MaxSum = 0;
    cin>>n;
    a = (int*)malloc(n*sizeof(int));
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < n;i++) {
        ThisSum += a[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    cout<<MaxSum;
}
