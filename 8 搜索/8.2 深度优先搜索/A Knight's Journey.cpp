#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

const int MAXN=27;

int p,q;

bool visit[MAXN][MAXN];
int direction[8][2]={
	{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}
};

bool DFS(int x,int y, int step,string ans){
	if(step == p*q){		
		cout<<ans<<endl<<endl;
		return true;
	} 
	for(int i=0;i<8;i++){
		int nx = x+direction[i][0];
		int ny = y+direction[i][1];
		char col = 'A'+ny;
		char row = '1'+nx;
		if(nx < 0 || ny < 0 || nx>=p || ny>=q || visit[nx][ny]){
			continue;
		}
		visit[nx][ny]=true;
		// 深度优先搜索返回结果为true，代表该路径可行 
		if(DFS(nx,ny,step+1,ans+col+row)){
			return true;
		}
		// 否则不可行，该点重新设置为未访问 
		visit[nx][ny]=false;
	}
	return false;
}

int main(){
	int caseNumber;
	scanf("%d",&caseNumber);
	for(int i=1;i<=caseNumber;i++){
		// 输入很大，一定要用scanf，否则会超时
		scanf("%d%d",&p,&q);
		memset(visit,false,sizeof(visit));
		cout<<"Scenario #"<<i<<":"<<endl;
		visit[0][0]=true;
		if(!DFS(0,0,1,"A1")){
			cout<<"impossible"<<endl<<endl;
		}
	}
	return 0;
}


