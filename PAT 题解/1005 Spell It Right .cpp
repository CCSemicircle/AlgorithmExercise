#include<iostream>
#include<string>

using namespace std;

string tap[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string str;
    cin>>str;
    int sum =0;
    for(int i=0;i<str.size();i++){
        sum += str[i]-'0';
    }
    string ans = to_string(sum);
    cout<<tap[ans[0]-'0'];
    for(int i=1;i<ans.size();i++){
        cout<<" "<<tap[ans[i]-'0'];
    }
    cout<<endl;
    return 0;
}