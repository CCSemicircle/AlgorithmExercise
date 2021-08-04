#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MAXN=128;

char child[MAXN];
int height[MAXN];
    
int main(){
    int n,m;
    while(cin>>n>>m){
        // 初始化
        memset(height,0,sizeof(height));
        memset(child,0,sizeof(child));
        cin.get();
        for(int i=0;i<n;i++){
            string str;
            getline(cin,str);
            // 注意高度设置是子结点高度+1
            if(str[1] != '-'){
                child[str[1]] = str[0];
                height[str[1]] = height[str[0]]+1;
            }
            if(str[2] != '-'){
                child[str[2]] = str[0];
                height[str[2]] = height[str[0]]+1;
            }
        }
        while(m--){
            string str;
            getline(cin,str);
            char a = str[0];
            char b = str[1];
            
            bool isChild=false;  // 判断原始的a是不是更小
            // 设置a永远比b大
            if(height[a] < height[b]){
                char temp = a;
                a = b;
                b = temp;
                isChild = true;
            }
            // 同一级，无直系关系
            if(height[a] == height[b]){
                cout<<"-"<<endl;
                continue;
            }
            // 统计关系层级差
            int cnt=0;  // 层级数
            int flag = false;  // 是否找到
            char ch = a;
            while(ch != 0){
                if(ch == b){
                    flag = true;
                    break;
                }
                cnt++;
                ch = child[ch];
            }
            if(flag){
                string relation = "parent";
                if(isChild){
                    relation = "child";
                }
                if(cnt == 1){
                    cout<<relation<<endl;
                }else if(cnt == 2){
                    cout<<"grand"<<relation<<endl;
                }else{
                    for(int i=2;i<cnt;i++){
                        cout<<"great-";
                    }
                    cout<<"grand"<<relation<<endl;
                }
            }else{
                cout<<"-"<<endl;
            }
        }
    }
    return 0;
}