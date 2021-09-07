class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 每个字母有一个最后出现位置，当前片段的终点是当前片段内所有字母最终位置的最大值，如果当前下标为终点，则确定一个划分
        vector<int> last(26,0);
        int length = s.size();
        int start =0,end=0;
        vector<int> partition;
        // 先找到所有字母最后出现的位置
        for(int i=0;i<length;i++){
            last[s[i]-'a'] = i;
        }
        // 从左到右遍历，确定划分
        for(int i=0;i<length;i++){
            end = max(end,last[s[i]-'a']);
            if(i == end){
                partition.push_back(end-start+1);
                start = i+1;
                end = i+1;
            }
        }
        return partition;
    }
};