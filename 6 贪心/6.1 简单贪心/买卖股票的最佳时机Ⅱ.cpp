class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 找规律，连续上涨等价于每天交易（单日上涨），连续下跌不交易
        int sum=0;
        int length = prices.size();
        for(int i=0;i<length-1;i++){
            int temp = prices[i+1]-prices[i];
            if(temp > 0) sum+=temp;
        }
        return sum;
    }
};