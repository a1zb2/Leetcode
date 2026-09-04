class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        unordered_map<int,int> instability_score;
        for(int i=0;i<nums.size();i++){
            int max_nums=INT_MIN;
            for(int j=0;j<=i;j++){
                max_nums = max(max_nums,nums[j]);
            }
            int min_nums = INT_MAX;
            for(int z=i;z<nums.size();z++){
                min_nums = min(min_nums,nums[z]);
            }
            int score = max_nums - min_nums;
            if(score<=k && (instability_score.find(score)==instability_score.end())){
                instability_score[score] = i;
            }
        }
        if(instability_score.empty()){
            return -1;
        }
        else{
            int min_index = INT_MAX;
            for(auto [score,index]:instability_score){
                min_index = min(index,min_index);
            }
            return min_index;
        }
    }
};