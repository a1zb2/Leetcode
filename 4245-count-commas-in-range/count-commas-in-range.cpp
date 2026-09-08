using namespace std;
class Solution {
public:
    int countCommas(int n) {
        if(n<1000)
        return 0;
        else{
            int count = 1;
            for(int i=1000;i<n;i++)
            count++;
            return count;
        }
    }
};