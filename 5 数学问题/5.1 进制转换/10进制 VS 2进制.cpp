#include<iostream>
#include<string>
#include<vector>

using namespace std;


string Divide(string str, int x){
    int carry=0;
    for(int i=0;i<str.size();i++){
        int curr = str[i]-'0' + carry*10;
        str[i] = curr/x + '0';
        carry = curr%x;
    }
    int pos=0;
    while(pos < str.size() && str[pos] == '0') pos++;  // 注意符号
    return str.substr(pos);
}


string Multiple(string str, int x){
    int carry=0;
    for(int i=str.size()-1;i>=0;i--){
        int curr = (str[i]-'0')*x + carry;
        str[i] = curr%10 + '0';
        carry = curr/10;
    }
    if(carry > 0){
        str = (char)(carry+'0') + str;
    }
    return str;
}

string Add(string str,int x){
    int carry = x; // 只加1次 
    for(int i=str.size()-1;i>=0;i--){
        int curr = str[i]-'0'+ carry;
        str[i] = curr%10 + '0';  // 注意此处为mod 10
        carry = curr/10;
        if(carry == 0){
            break;
        }
    }
    if(carry > 0){
        str = (char)(carry+'0') + str;
    }
    return str;
}

int main(){
    string num;
    while(getline(cin,num)){
        vector<int> binary;
        // 十进制转二进制，是取模，反复除，类似十进制数转为字符串
        while(num.size() != 0){
            int last = num[num.size()-1]-'0';
            binary.push_back(last%2);
            num = Divide(num,2);
        }
        // 二进制转十进制相反，是反复乘，再取余数，类似字符串转为十进制
        string ans="0";
        for(int i=0;i<binary.size();i++){
            ans = Multiply(ans, 2);
            ans = Add(ans,binary[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
