class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            // 如果以右边为基准，先判断右边是否为递增区间
            // 如果以左边为基准，先判断左边是否为递增区间
            if(nums[r] == nums[mid]){
                // 无法区分递增区间
                --r;
            }else if(nums[mid] < nums[r]){
                // 右边是递增区间，一定先判断左边，防止未旋转的特殊数组
                r = mid;
            }else{
                // 左边是递增区间
                l = mid+1;
            }
        }
        return nums[r];
    }
};