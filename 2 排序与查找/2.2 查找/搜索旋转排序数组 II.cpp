class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 直接二分查找
        int l =0 , r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid]){
                // 无法区分哪个是递增区间，此时只能缓慢移动左端点
                ++l;
            }else if(nums[l] < nums[mid]){
                // 左边是递增区间
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                // 右边是递增区间
                if(target > nums[mid] && target <= nums[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return false;
    }
};