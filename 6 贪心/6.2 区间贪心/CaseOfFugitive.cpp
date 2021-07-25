#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int MAXN=2e5+1;
const long long MAXM=1e18;

struct Island{
	long long left;
	long long right;
};

struct Bridge{
	long long length;
	long long index;
};

struct Interval{
	long long minimum;
	long long maximum;
	long long index;  // 区间编号
	// 按最大值降序排列
	bool operator<(const Interval& x) const{
		return maximum > x.maximum;
	} 
};

Island island[MAXN];
Bridge bridge[MAXN];
Interval interval[MAXN];
long long ans[MAXN];

// 按最小值的升序排列
bool IntervalCompare(Interval x, Interval y){
	if(x.minimum == y.minimum){
		return x.maximum < y.maximum;
	}else{
		return x.minimum < y.minimum;
	}
}

// 按长度的升序排列
bool BridgeCompare(Bridge x, Bridge y){
	return x.length < y.length;
}


bool Solve(int n,int m){
	// 用区间去匹配桥，每次尽量找到最匹配桥大小的区间，与用桥匹配区间相比，这种方法的时间复杂度较小，假设每轮都全遍历，那前者遍历n个，后者遍历m个，且前者可通过empty快速结束遍历
	// 在所有满足 minimum <= length <= maximum 的区间中找到maximum最小的区间 
	priority_queue<Interval> Q;  // 找到当前桥所能搭建的区间
	int position = 0;  // 当前区间的下标
	int number = 0;  // 搭建桥的数目
	for(int i=0;i<m;i++){
		// 使用同一个优先队列，所以需要先排除，再补充

		// 排除当前桥无法搭建的区间
		while(!Q.empty() && Q.top().maximum < bridge[i].length){
			// Q 是按maximum降序排列，且因为bridge是按长度升序排列，因而最一定满足之前的minimum，因而仅根据maximum判断
			Q.pop();  
		}
		// 补充当前桥可以搭建的区间
		while(position < n-1 && interval[position].minimum <= bridge[i].length && interval[position].maximum >= bridge[i].length){
			Q.push(interval[position]);
			position++;
		}
		if(!Q.empty()){
			// 取出maximum最大的区间，作为当前桥最适合搭建的区间，由当前桥搭建，
			Interval current = Q.top();
			Q.pop();
			ans[current.index]= bridge[i].index;
			number++;
		}
	}
	return number == n-1;  // 判断可以搭建的桥数与区间数是否相等
}

int main(){
	int n,m;
	while(cin>>n>>m){
		memset(island,0,sizeof(island));
		memset(bridge,0,sizeof(bridge));
		memset(interval,0,sizeof(interval));
		memset(ans,0,sizeof(ans));

		for(int i=0;i<n;i++){
			cin>>island[i].left>>island[i].right;
			if(i!=0){
				interval[i-1].minimum = island[i].left - island[i-1].right;
				interval[i-1].maximum = island[i].right - island[i-1].left;
				interval[i-1].index = i-1;
			}
		}
		for(int i=0;i<m;i++){
			cin>>bridge[i].length;
			bridge[i].index = i+1;
		}

		sort(interval, interval+n-1,IntervalCompare);  // 按照最小值的升序排列interval
		sort(bridge, bridge+m, BridgeCompare);  // 按照长度的升序排列

		if(Solve(n,m)){
			printf("Yes\n");
			for(int i=0;i<n-1;i++){
				printf("%lld ",ans[i]);
			}
			printf("\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
