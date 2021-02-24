#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int length = nums.size();
        int prev = 0;
        vector<int> res;
        for (int i = 0; i < length; i++) {
            res.push_back(nums[i] + prev);
            prev = res[i];
        }
        return res;
        
    }
};