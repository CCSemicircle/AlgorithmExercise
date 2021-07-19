// 预处理策略优化
#include<iostream>

using namespace std;

int keytab[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main(){
    string str;
    while(cin>>str){
        int time=0;
        for(int i=0;i<str.size();i++){
            time +=keytab[str[i]-'a'];
            if(i!=0 && str[i]-str[i-1] == keytab[str[i]-'a']-keytab[str[i-1]-'a'])
                time+=2;
        }
        cout<<time<<endl;
    }
    return 0;
}
