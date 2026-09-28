class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long long int low = 1;
        long long int high = x;
        int ans = 1;
        while(low<=high){
            long long int mid = low + (high - low)/2;
            long long prod = mid * mid;
            if(prod<=x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};