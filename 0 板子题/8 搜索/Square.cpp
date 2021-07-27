#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=21;

bool visit[MAXN];
int stick[MAXN];
int side;  // 正方形边长
int m;  // 棍子的数量 

// sum代表当前边已搭建的长度，number代表已经搭建好的边的数量，position代表当前棍子的编号 
bool DFS(int sum,int number, int position){
	if(number == 3){
		// 当搭建好三条边时，因为 总长度%4==0，剩下一条边一定可以搭建
		return true; 
	}
	// 剪枝（3）：跳过上一次不匹配的长度 
	int failure=0;  // 上一次不匹配的长度 
	for(int i=position;i<m;i++){
		if(visit[i] || sum+stick[i] > side || stick[i]==failure){
			continue;
		}
		// 注意DFS中的标记，先标记为true，DFS的结果不符合再重新设置为false，有点类似于试错法 
		visit[i]=true;
		if(sum+stick[i] == side){
			// 凑成一条边，从第0条边开始重新遍历 
			// 不知道第0根棍子是否符合下一条搭建的边 
			if(DFS(0,number+1,0)){
				return true;  // 成功凑成正方形 
			} else{
				failure = stick[i];
			}
		}else{
			// 不能凑成一条边，从第i+1根棍子开始遍历
			// 理由是之前的棍子都已经判断过是否符合当前搭建的边
			if(DFS(sum+stick[i],number,i+1)){
				return true; 
			}else{
				failure = stick[i];
			}
		}
		visit[i]=false;
	}
	return false;
}

bool Compare(int x,int y){
	return x>y;
}

int main(){
	int caseNumber;
	scanf("%d",&caseNumber);
	while(caseNumber--){
		scanf("%d",&m);
		int length =0;
		for(int i=0;i<m;i++){
			scanf("%d",&stick[i]);
			length += stick[i];
		}
		memset(visit,false,sizeof(visit));
		// 剪枝（1） 
		if(length%4 !=0){
			cout<<"no"<<endl;
			continue;
		}
		side = length/4;
		// 将棍子按长度从大到小排列 
		sort(stick,stick+m,Compare);
		// 剪枝（2） 
		if(stick[0]> side){
			cout<<"no"<<endl;
			continue;
		}
		if(DFS(0,0,0)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl; 
		}
	}
	return 0;
}
