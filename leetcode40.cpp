#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    private:
        vector<vector<int>> a;
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            int length = candidates.size();
            sort(candidates.begin(), candidates.end());
            vector<int> b;
            backTracking(candidates, -1, target, 0, b, length);
            return a;
        }
        void backTracking(vector<int>& candidates, int currentIndex, int target, int currentSum, vector<int> data, int size){/*
            cout<<data.size()<<endl;
            for (int i : data){
                cout<<i<<endl;
            }*/
            if (currentSum > target)
                return;
            /*if (currentIndex >= size)
                return;*/
            if (currentSum == target){
                vector<int> newVector(data);
                a.push_back(newVector);
                return;
            }
            for (int i = currentIndex + 1 ; i < size; i++){
                if (i != currentIndex + 1 && candidates.at(i) == candidates.at(i-1))
                    continue;
               // cout<<i<<endl;
                data.push_back(candidates.at(i));
                backTracking(candidates, i, target, currentSum + candidates.at(i), data, size);
                data.pop_back();
            }
        }
};