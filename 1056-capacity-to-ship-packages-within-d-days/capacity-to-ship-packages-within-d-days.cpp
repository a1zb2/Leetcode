class Solution {
public:
    int dayscounter(vector<int>& weights, int capacity){
        int day = 1,load=0;
        for(int i=0;i<weights.size();i++){
            if((load+weights[i])>capacity){
                day = day + 1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(dayscounter(weights,mid)<=days){
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