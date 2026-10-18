class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans = -1;
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid = low + (high - low)/2;
            long long hrs = 0;
            for(int i=0;i<piles.size();i++){
                hrs += ceil((double)piles[i]/mid);
            }
            if(hrs<=h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};