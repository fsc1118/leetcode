#include <string.h>
#define MAX(a,b) (a > b ? a : b)
static int recur(int* nums, int* dp, int numsSize, int currentIndex) {
    if (currentIndex >= numsSize) {
        return 0;
    }
    if (dp[currentIndex] != -1) {
        return dp[currentIndex];
    }
    int i1 = recur(nums, dp, numsSize, currentIndex + 2);
    int i2 = recur(nums, dp, numsSize, currentIndex + 3);
    int max = MAX(i1, i2) + nums[currentIndex];
    dp[currentIndex] = max;
    return max;
}
int rob(int* nums, int numsSize){
    int dp[numsSize];
    memset(dp, -1, numsSize * sizeof(int));
    return MAX(recur(nums, dp, numsSize, 1), recur(nums, dp, numsSize, 0));
}
