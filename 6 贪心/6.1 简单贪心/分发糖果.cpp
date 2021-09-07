class Solution {
public:
    int candy(vector<int>& ratings) {        
        int size =2;
        if(ratings.size() < size){
            return ratings.size() ;
        }else{
            size = ratings.size();
        }
        vector<int> num(size,1);  // 初始默认为1
        // 从左往右遍历，右边的比当前大，则分配比当前糖果数+1，否则分配1个（即便相等）
        for(int i=1;i<size;i++){
            if(ratings[i] > ratings[i-1]){
                num[i] = num[i-1]+1;
            }
        }
        // 从右往左遍历，左边比当前大，则应该左边糖果多余右边糖果
        for(int i=size-1;i>0;i--){
            if(ratings[i-1] > ratings[i]){
                num[i-1] = max(num[i-1],num[i]+1);  // 是否原来的就多，还是右边糖果数+1更大
            }
        }
        return accumulate(num.begin(),num.end(),0);
    }
};