#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN=11;

int main(){
    int n;
    while(cin>>n){
        vector<string> path[MAXN];  // vector数组，二维数组
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            // 将字符串拆分为目录列表
            string temp;
            for(int j=0;j<str.length();j++){
                if(str[j] != '\\'){
                    temp += str[j];
                }else{
                    path[i].push_back(temp);
                    temp.clear();  // 一定要注意清空
                }
            }
        }
        // 排序
        sort(path,path+n);
        for(int i=0;i<n;i++){
            int index=0;
            string space;
            // 寻找与上一行相同的目录结构，确定每个父路径初始的空格数space
            while(i>0 && index < path[i-1].size() && index < path[i].size() && path[i-1][index] == path[i][index]){
                index++;
                space += "  ";
            }
            // 输出
            for(;index < path[i].size(); index++, space += "  "){
                cout<<space<<path[i][index]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
