#include<vector>
using namespace std;
/*
Dynamical programming. dp[i] represents the maximum length of increasing series in the first n number, 
and such series must also include nums[i]


*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        int* dp = new int[length];
        int res = -1;
        for (int i = 0; i < length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
    
        delete[] dp;
        return res;
    }
};