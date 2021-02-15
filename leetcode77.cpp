#include<vector>
using namespace std;
class Solution {
    private:
        vector<vector<int>> answer;
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<int> ans;
            dfs(n, k, 0, 0,ans);
            return answer;
        }
        void dfs(int higherBound, int targetNum, int currentIndex, int currentNum, vector<int> ans){
            if (currentNum == targetNum){
                vector<int> newAnswer(ans);
                answer.push_back(newAnswer);
                return;
            }
            for (int k = currentIndex + 1; k <= higherBound; k++){
                ans.push_back(k);
                dfs(higherBound, targetNum, k, currentNum + 1, ans);
                ans.pop_back();
            }
        }
};