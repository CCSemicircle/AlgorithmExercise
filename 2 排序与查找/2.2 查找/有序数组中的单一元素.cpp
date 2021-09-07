class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 二分查找，如果 左区间数字为单数，且中间数跟左边相等，则出现一次的数在左边，右边同理，每次查找去除一对数字
        int l=0,r=nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            bool isLeftOdd = (mid-l)%2==0;  // 左边是否为奇数个数
            if(nums[mid-1] == nums[mid]){
                // 中间位置与左边数字相等，根据左边是否为奇数
                if(isLeftOdd){
                    r = mid-2;
                }else{
                    l = mid+1;
                }
            }else if(nums[mid+1] == nums[mid]){
                // 中间位置与右边数字相等，根据左边是否为奇数
                if(isLeftOdd){
                    l = mid+2;
                }else{
                    r = mid-1;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[r];
    }
};