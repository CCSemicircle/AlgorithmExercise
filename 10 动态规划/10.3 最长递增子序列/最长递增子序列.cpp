#include<iostream>

using namespace std;

const int MAXN=100001;

int arr[MAXN];
int tails[MAXN];  // 表示长度为 i+1 的最长递增子序列的值最小的结束元素
int dp[MAXN];
int ans[MAXN];

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        dp[0]=1;
        tails[0] = arr[0];
        int right= 0;  // tails的有效范围为 [0, right]
        int l = 0;
        int r = 0;
        int maxLen = dp[0];  // 当前最长递增子序列长度
        int maxIndex = 0;  // 最长递增子序列的最后一个元素下标
        for(int i=1;i<n;i++){
            dp[i] = 1;
            l = 0;
            r = right;
            // 二分查找arr[i]在tails有效范围内的插入位置，如果比其内所有元素都大，
            // 则扩展tails
            while(l <= r){
                int mid = (l+r) >> 1;
                if(arr[i] > tails[mid]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            // l 代表着最终的插入位置
            right = max(right, l);  // 判断是否需要扩展tails
            tails[l] = arr[i];  // 更新长度为i+1的递增子序列的结束元素
            dp[i] = l+1;  // l+1是 以arr[i]为结束元素的最长递增子序列 长度
            // 由于题目要求字典序最小，此处必须包含 =，
            // 因为二者相等表示arr[i]插入了最后的位置，代表更新了最长递增子序列的结束元素
            if(dp[i] >= maxLen){
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        // 从后往前找最长递增子序列中的元素
        int temp = maxLen;  // 保存最长递增子序列长度
        for(int i=maxIndex; i>=0; i--){
            if(dp[i] == temp){
                ans[--temp] = arr[i];
            }
        }
        for(int i=0;i<maxLen;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}