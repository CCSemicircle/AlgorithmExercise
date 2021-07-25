// 使用map更方便
#include<iostream>
#include<map>

using namespace std;

int main(){
    string str;
    multimap<char,int> mp;  // 一定要使用multimap
    while(cin>>str){
        mp.clear();
        int len = str.size();
        for(int i=0;i<len;i++)
            mp.insert(pair<char,int>(str[i],i));
        for(int i=0;i<len;i++){
            char ch= str[i];
            if(mp.count(ch)>1){
                auto mit=mp.equal_range(ch);
                for(auto it=mit.first;it!=mit.second;it++){
                    if(it!=mit.first) cout<<',';
                    cout<<ch<<":"<<it->second;
                }
                mp.erase(ch);  // 一定要清除已经输出的字符，防止重复
                cout<<endl;
            }
        }
    }
}
