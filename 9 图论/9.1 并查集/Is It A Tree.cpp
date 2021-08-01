#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=10001;

int inDegreee[MAXN];
int visit[MAXN];

int main(){
    int start,end;
    int caseNumber=1;
    while(cin>>start>>end){
        if(start == -1){
            break;
        }
        memset(inDegreee,0,sizeof(inDegreee));
        memset(visit, false, sizeof(visit));
        inDegreee[end]++;
        // 考虑空树
        if(start==0 && end==0){
            printf("Case %d is a tree.\n",caseNumber++);
            continue;
        }
        visit[start]=true;
        visit[end]=true;
        while(cin>>start>>end && start){
            inDegreee[end]++;
            visit[start]=true;
            visit[end]=true;
        }
        int root = 0;
        int flag=true;
        // 从1开始编号
        for(int i=1;i<MAXN;i++){
            if(!visit[i]){
                continue;
            }
            if(inDegreee[i]==0){
                root++;
            }
            if(inDegreee[i] > 1){
                flag = false;
            }
        }
        if(root == 1 && flag){
                printf("Case %d is a tree.\n",caseNumber++);
         }else{
                printf("Case %d is not a tree.\n",caseNumber++);
         }
    }
    return 0;
}