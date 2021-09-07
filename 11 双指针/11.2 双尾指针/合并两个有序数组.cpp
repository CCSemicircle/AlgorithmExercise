class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 三个指针，原两个数组的尾指针以及合并数组的尾指针
        int tail = m -- + n--  -1;
        while(m >=0 && n >=0){
            if(nums1[m] > nums2[n]){
                nums1[tail--] = nums1[m--];
            }else{
                nums1[tail--] = nums2[n--];
            }
        }
        while(n >= 0){
            nums1[tail--] = nums2[n--];
        }
    }
};