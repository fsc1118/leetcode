#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, int start, int maxIndex, vector<int>& data){
        result.push_back(data);
        for (int i = start + 1; i < maxIndex; i++){
            if (i != start + 1 && nums.at(i) == nums.at(i - 1))
                continue;           
            data.push_back(nums.at(i));
            dfs(nums, i, maxIndex, data);
            data.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> data;
        sort(nums.begin(), nums.end());
        dfs(nums, -1, nums.size(), data);
        return result;
    }
    
};