#include<iostream>
#include<string>

using namespace std;

string Present(int n){
    int index = 0;
    string str="";  // 最终的结果
    bool last = true;  // 判断是不是最后结尾的幂
    while(n){
        int a = n%2;  // 每一位的数字
        n /= 2;
        if(a == 0){
            index++;
            continue;
        }else{
            string curr="";
            if(index == 0){
               curr = "2(0)";
            }
            else if(index == 1){
                curr = "2";
            }else if(index == 2){
                curr = "2(2)";
            }else{
                curr =  "2("+Present(index)+")";
            }
            if(!last){
                curr += "+";
            }else{
                last = false;
            }
            str = curr + str;
        }
        index++;
    }
    return str;
}

int main(){
    int n;
    while(cin>>n){
        cout<<Present(n)<<endl;
    }
    return 0;
}