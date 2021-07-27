#include<iostream>
#include<string>

using namespace std;

const int MAXN=1001;
const int MAXM=5001;

int main(){
    int n,m;
    string agent[MAXN];
    string serve[MAXM];
    while(cin>>n){
        cin.get();
        for(int i=0;i<n;i++){
            getline(cin,agent[i]);
        }
        cin>>m;
        cin.get();
        for(int i=0;i<m;i++){
            getline(cin,serve[i]);
        }
        int index=0, cnt=0;
        bool flag = true;
        // 同一起点出发法，求每次能达到的最远距离
        while(flag && index < m){
            int max=0;  // 找到agent能达到的最远下标
            for(int i=0;i<n;i++){
                int j=index;
                while(agent[i] != serve[j] && j<m){
                    j++;
                }
                if(j - index > max){
                    max = j-index;
                }
            }
            if(max == 0){  
                // 最远都只有0则无法代理
                flag=false;
            }else{
                cnt++;
                index += max;
            }
        }
        if(flag){
            cout<<cnt-1<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}