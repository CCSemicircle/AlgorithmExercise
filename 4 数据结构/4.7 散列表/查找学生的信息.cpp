#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<int,string> student;
    int n,m;
    while(cin>>n){
        student.clear();
        cin.get();
        for(int i=0;i<n;i++){
            string str;
            getline(cin,str);
            int index = stoi(str.substr(0,str.find(" ")));
            student[index]=str;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            // 注意此处的判断条件
            if(student[x]!=""){
                cout<<student[x]<<endl;
            }else{
                cout<<"No Answer!"<<endl;
            }
        }
    }
}