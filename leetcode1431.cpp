#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandy = -1;
        for (int i : candies)
            maxCandy = max(i, maxCandy);
        for (int i : candies)
            (i + extraCandies >= maxCandy)?result.push_back(true):result.push_back(false);
        return result;        
        
    }
};