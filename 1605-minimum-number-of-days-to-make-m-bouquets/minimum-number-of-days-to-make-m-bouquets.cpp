class Solution {
public:
    bool is_possible(vector<int> &arr,int day,int m,int k){
        int total_count = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day)
            count++;
            else{
                total_count += count/k;
                count = 0;
            }
        }
        total_count+=count/k;
        if(total_count>=m)
        return true;
        else
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k>bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(is_possible(bloomDay,mid,m,k)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};