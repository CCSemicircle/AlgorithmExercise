class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = true;
        int cnt=0;
        int length = nums.size();
        nums.insert(nums.end(),1e9);
        for(int i=1;i<length;i++){
            if(nums[i-1] > nums[i]) cnt++;
            // 找数学规律，a > c && b>d 不可以
            if(cnt >= 2 || (i < length-1 && nums[i-1] > nums[i+1] && nums[i] > nums[i+2])){
                flag = false;
                break;
            }
        }
        return flag;
    }
};