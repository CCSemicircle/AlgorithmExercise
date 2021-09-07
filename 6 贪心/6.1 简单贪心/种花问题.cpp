class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 暴力算法
        // int size = flowerbed.size();
        // if(size==0) return 0;
        // flowerbed.push_back(0);  // 在结尾插入一个元素0便于处理
        // int total = 0;
        // if(flowerbed[0] == 0 && flowerbed[1]==0){
        //     ++total;
        //     flowerbed[0] =1; 
        // }
        // for(int i=1;i<size;++i){
        //     if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
        //         ++total;
        //         // 注意修改状态
        //         flowerbed[i] = 1;
        //     }
        // }
        // return n <= total;
        // 跳格子算法
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 1){
                i++;
            }else if(i == flowerbed.size()-1 || flowerbed[i+1] == 0){
                n--;
                i++;
            }else{
                i+=2;
            }
        }
        return n<=0;
    }
};