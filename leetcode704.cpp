#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;    
        while (min <= max){
            int mid = (min + max) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                min = mid + 1;
            if (nums[mid] > target)
                max = mid - 1;
        }
        return -1;
    }
};