#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> result;
    void dfs(int startIndex, int lastIndex, int targetLength, int currentLength, vector<int>& holds, vector<int>& nums){
        if (targetLength == currentLength){
            result.push_back(holds);
            return;
        }
        for (int i = 0; i < lastIndex; i++){
            int k = nums.at(i);
            holds.push_back(k);
            vector<int> newNum=nums;
            newNum.erase(newNum.begin() + i);
            dfs(startIndex, lastIndex - 1, targetLength, currentLength + 1, holds, newNum);
            holds.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size();
        vector<int> holds;
        dfs(0, length, length, 0, holds, nums);
        return result;
    }

};