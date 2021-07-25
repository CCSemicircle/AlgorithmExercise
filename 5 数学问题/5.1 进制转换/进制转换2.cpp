// 不考虑大整数

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int CharToInt(char ch){
    if(ch>='0' && ch <= '9'){
        return ch-'0';
    }else{
        return ch-'A'+10;
    }
}

char IntToChar(int x){
    if(x>=0 && x<=9){
        return '0'+x;
    }else{
        return 'A'+x-10;
    }
}

int main(){
    int m,n;
    while(cin>>m>>n){
        string str;
        cin>>str;
        // m进制转为10进制
        long long number=0;
        for(int i=0;i<str.size();i++){
            number *= m;
            number += CharToInt(str[i]);
        }
        // 10进制转为n进制
        vector<char> ans;
        while(number){
            ans.push_back(IntToChar(number%n));
            number /= n;
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
