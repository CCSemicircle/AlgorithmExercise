#include<bits/stdc++.h>

using namespace std;

void QuickSort(vector<int>& nums,int l, int r){
	if(l+1 >= r){  // 此处不能直接用l > r，因为当l的下一个元素是r时就应该停止
//		printf("l = %d, r = %d\n",l,r); 
		return;
	}
	int first=l,last=r-1,key = nums[first];
	while(first < last){
		while(first < last && nums[last] >= key){
			--last;
		}
		nums[first] = nums[last];
		while(first < last && nums[first] <= key){
			++first;
		}
		nums[last] = nums[first];
	}
	nums[first] = key;
	QuickSort(nums,l,first);
	QuickSort(nums,first+1,r);
}

void MergeSort(vector<int>& nums,int l,int r,vector<int>& temp){
	if(l+1 >= r){  // 此处不能直接用l > r，因为当l的下一个元素是r时就应该停止 
//		printf("l = %d, r = %d\n",l,r); 
		return;
	}
	int m = l + (r-l)/2;
	MergeSort(nums,l,m,temp);
	MergeSort(nums,m,r,temp);
	int p = l,q=m,i=l;
	while(p<m || q<r){
		// 从两个有序子数组中取出较小元素放在辅助数组中 
		if(q>=r || (p<m && nums[p] <= nums[q])){
			// 注意此处的判别条件，同时考虑了某一段遍历结束的情况 
			temp[i++] = nums[p++];
		}else{
			temp[i++] = nums[q++];
		}
	} 
	for(int i=l;i<r;++i){
		nums[i] = temp[i];
	}
}

void InsertionSort(vector<int>& nums,int n){
	for(int i=0;i<n;++i){
		for(int j=i;j>0&&nums[j] < nums[j-1];--j){
			// 往后挪位进行插入 
			swap(nums[j],nums[j-1]);
		}
	}
}

void BubbleSort(vector<int>& nums,int n){
	bool swapped;  // 提前判断是否已经排序完成 
	for(int i=1;i<n;++i){
		swapped = false;
		for(int j=1;j<n-i+1;++j){
			if(nums[j] < nums[j-1]){
				swap(nums[j],nums[j-1]);
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}
}

void SelectionSort(vector<int>& nums,int n){
	int mid;
	for(int i=0;i<n-1;++i){
		mid = i;
		for(int j=i+1;j<n;++j){
			if(nums[j] < nums[mid]){
				mid = j;
			}
		}
		swap(nums[mid],nums[i]);
	}
}

void Print(vector<int>& nums){
	for(int i=0;i<nums.size();++i){
		printf("%d ",nums[i]);
	} 
	printf("\n");
}	

void Reset(vector<int>& nums){
	int arr[] = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
	nums.assign(arr,arr+20);
}

void SortTest() {
	// 均左闭右开 
	vector<int> nums;
	
	Reset(nums);
	vector<int> temp(nums.size());
	Print(nums);
	
	Reset(nums);
	sort(nums.begin(), nums.end());
	Print(nums);
	
	Reset(nums);
	QuickSort(nums, 0, nums.size());
	Print(nums);
	
	Reset(nums);
	MergeSort(nums, 0, nums.size(), temp);
	Print(nums);
	
	Reset(nums);
	InsertionSort(nums, nums.size());
	Print(nums);
	
	Reset(nums);
	BubbleSort(nums, nums.size());
	Print(nums);
	
	Reset(nums);
	SelectionSort(nums, nums.size());
	Print(nums);
}

int main(){
	 SortTest();
	 return 0;
}
