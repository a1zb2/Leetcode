class Solution {
public:
    int maxDepth(string s) {
        int curr_count = 0;
        int max_count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                curr_count++;
                max_count = max(max_count,curr_count);
            }
            else if(s[i]==')'){
                curr_count--;
            }
            else{
                continue;
            }
        }
        return max_count;
    }
};