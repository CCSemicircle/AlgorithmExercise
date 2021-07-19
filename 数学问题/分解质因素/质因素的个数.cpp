#include<iostream>
#include<cmath>
using namespace std;
 
int main(){
    int num;
    while(cin >> num){
        int cnt = 0;
        int bound = sqrt(num);
        // 注意从2开始
        for(int i = 2; i <= bound; i++){
            while(num % i == 0){
                cnt ++;
                num /= i;  // 不断做除法
            }
            if(num <= 1) break;
        }
        // 存在大于 sqrt(num) 的因子
        if(num > 1) cnt ++;
        cout << cnt;
    }
    return 0;
}