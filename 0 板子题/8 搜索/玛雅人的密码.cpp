#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

struct Status{
    string str;
    int n;
    Status(string s,int n):str(s),n(n){}
};

// 关键点：使用map结构判断已出现字符串
unordered_map<string, bool> visit; // 避免重复入队，减少遍历

int BFS(int n,string num){
    queue<Status> Q;
    Q.push(Status(num,0));
    while(!Q.empty()){
        Status curr = Q.front();
        Q.pop();
        if(curr.str.find("2012") != string::npos){
            return curr.n;
        }
        for(int i=0;i<n-1;i++){
            string temp = curr.str;
            char ch = temp[i];
            temp[i] = temp[i+1];
            temp[i+1] = ch;
            if(!visit[temp]){
                Q.push(Status(temp,curr.n+1));
                visit[temp]=true;
            }
        }
    }
}

int main(){
    int n;
    string num;
    while(cin>>n>>num){
        // 只要有0 1 2 就可以移动出2012子串，提前判断减少复杂度
        if(num.find("0")==string::npos || num.find("1")==string::npos || num.find("2")==string::npos){
            cout<<-1<<endl;
            continue;
        }
        cout<<BFS(n,num)<<endl;;
    }
    return 0;
}