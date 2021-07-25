#include<iostream>
#include<string>
#include<vector>

using namespace std;

string Divide(string str, int x){
    int carry=0;
    for(int i = 0;i<str.size();i++){
        int curr = str[i]-'0' + carry*10;
        str[i] = curr/x+'0';  // 注意结果变为字符
        carry = curr%x;
    }
    // 去除前导0
    int index=0;
    while(index<str.size() && str[index]=='0') index++;  // 注意字符判断 
    return str.substr(index);
}

int main(){
    string num;
    while(getline(cin,num)){
        vector<int> binary;
        while(num.size() != 0){
            binary.push_back((num[num.size()-1]-'0')%2);
            num = Divide(num, 2);
        }
        for(int i=binary.size()-1;i>=0;i--){
            cout<<binary[i];
        }
        cout<<endl;
    }
    return 0;
}
