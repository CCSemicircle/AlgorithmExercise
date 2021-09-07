class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& a,vector<int>& b){
            if(a[0] > b[0] || (a[0]==b[0] && a[1] < b[1])){
                return true;
            }
            return false;
        } );
        // 优先身高 高 与 排名 前的先插入
        vector<vector<int> > que;
        int length = people.size();
        for(int i=0;i<length;i++){
            int position = people[i][1];
            que.insert(que.begin()+position,people[i]);
        }
        return que;
    }
};