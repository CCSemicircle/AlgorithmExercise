#include<iostream>

using namespace std;

int main(){
    int curr,next;
    curr = 0;
    int sum = 0;
    cin>> next;  // 去除表示数字个数的N
    while(cin>>next){
        if(next < curr){
            sum += 4*(curr - next);
        }else{
            sum += 6*(next - curr);
        }
        sum += 5;
        curr = next;
    }
    cout<<sum;
    return 0;
}