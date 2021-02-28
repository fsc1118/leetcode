#include<vector>
#include<limits.h>
#include<stdlib.h>

using namespace std;
class NumArray {
    vector<int> target;
    int* m;
    int sumRange(int k){
       int ans = 0;
       //cout<<k<<endl;
        for (int i = k; i >= 0; i--) {
            //cout<<m[i]<<endl;;
            if (m[i] != INT_MAX){     
                ans = ans + m[i];
                break;
            } else{
                ans = ans + target[i];
            }
            //cout<<ans<<endl;
        }
        m[k] = ans;
       // cout<<ans<<endl;
        return ans;
    }
public:
    NumArray(vector<int>& nums) {
        target = nums;
        int length = nums.size();
        m = (int*)malloc(sizeof(int) * length);
        for (int i = 0; i < length; i++){
            *(m + i) = INT_MAX;
        }
    }
    
    int sumRange(int i, int j) {
        int prev = sumRange(i);
        //cout<<prev<<endl;
        int total = sumRange(j);
        //cout<<total<<endl;
        return total - prev + target[i];
    }
};