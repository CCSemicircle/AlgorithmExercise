#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=100;

int ans[MAXN][10];  // 所有排列结果
int curr[10];  // 当前排列
int cnt=0;  // 解的计数器

// position代表当前待确定皇后的编号
void DFS(int position){
    if(position==8){
        cnt++;  // 先加再复制可以直接从1开始计数
        for(int i=0;i<8;i++){
            ans[cnt][i] = curr[i];
        }
        return;
    }
    // 最外层循环列举在该层的所有状态
    // 在此处代表当前位置可以取的8个列位置
    for(int i=0;i<8;i++){
        // position代表行，i代表列
        curr[position] = i;  // 确定当前位置的列数
        int flag = true;  // 是否可行
        for(int j=0;j<position;j++){
            // 判断是否与之前的皇后 同列 或者 同斜线
            // 主对角线上x-y相同，副对角线上x+y相同，原理是斜率分别为1和-1
            if(i == curr[j] || position-i ==j -curr[j] || position+i == j+curr[j]){
                flag = false;
                break;
            }
        }
        // 如果可行确定下一个皇后的位置
        if(flag){
            DFS(position+1);
        }
    }
}

int main(){
    int n;
    DFS(0);  // 初始化
    while(cin>>n){
        for(int i=0;i<8;i++){
            cout<<ans[n][i]+1;
        }
        cout<<endl;
    }
    return 0;
}