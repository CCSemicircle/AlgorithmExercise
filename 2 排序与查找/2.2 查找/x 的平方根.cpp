class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1,r=x;
        while(l <= r){
            int mid = l + (r-l) /2;
            int ans = x / mid;  // 不能采用平方比大小，会溢出
            if(ans == mid){
                return mid;
            }else if(ans > mid){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        // 一直找不到时，l>r，此时的r就是要求的结果
        return r;
    }
};

// 牛顿迭代法，x(n+1) = x(n) - f(x(n))/f'(x(n))，x(n+1)指的是f(r) = 0，r的n+1次近似值
// class Solution {
// public:
//     int mySqrt(int x) {
//         long a = x;
//         while (a * a > x) {
//             a = (a + x / a) / 2;
//         }
//         return a;
//     }
// };