#include<vector>
using namespace std;
class Solution {
    private:
        int result = -1;
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = 0;
        int length = nums.size();
        int count = 0;
        while (n < length){
            if (nums.at(n) == 1)
                count++;
            else{
                result = max(count, result);
                count = 0;
            }
            n++;
        }
        result = max(count, result);
        return result;
    }
};