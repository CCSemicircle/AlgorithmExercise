#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        // 注意必须使用两个map，如果只使用一个map，可能因为有人的离开时间的数值最早导致被误判为开门人
        // 如离开为2点，开门进入的最早为3点，那使用一个map时，2点的人会判定为开门人，不符合题意
        map<string, string> open,close;
        string name,start,end;
        for(int i=0;i<n;i++){
            cin>>name>>start>>end;
            open[start]=name;
            close[end]=name;
        }
        auto last = close.end();
        last--;
        cout<<open.begin()->second<<" "<<last->second<<endl;
    }
    return 0;
}