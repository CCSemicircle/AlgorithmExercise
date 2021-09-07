class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        int n =intervals.size();
        // 保留终点最小的区间
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){ return a[1] < b[1]; });  // 此处vector需要使用引用，否则会超时
        int total = 0, prev = intervals[0][1];  // prev代表前一个区间的终点
        for(int i=1;i<n;++i){
            if(intervals[i][0] < prev){
                ++total;
            }else{
                prev = intervals[i][1];
            }
        }
        return total;
    }
};