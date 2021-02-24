#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
/*
给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int*> m;
        int length = nums.size();
        for (int i = 0; i < length; i++){
            if (m.count(nums[i]) == 0){ //no such element
                int* a  = (int*)malloc(12);
                a[0] = i;
                a[1] = i;
                a[2] = 1; // first: start index, second: end index, third: times of appearance
                m[nums[i]] = a;
            } else {
                int* k = m[nums[i]];
                k[1] = i;
                k[2] = k[2] + 1;
            } 
        }
        map<int, int*>::iterator it;
       // cout<<1<<endl;
        int _max = 0;
        int res = 0;
        for (it = m.begin(); it != m.end(); it++) {
            int key = it->first;
            int* val = it->second;
            if (val[2] > _max){
                _max = val[2];
                res = val[1] - val[0] + 1;
                //cout<<res<<endl;
            } else if (val[2] == _max)
                res = min(res, val[1] - val[0] + 1);     
        }
        return res;
    }
};