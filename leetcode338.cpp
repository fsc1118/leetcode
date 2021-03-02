#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>* result = new vector<int>(num + 1);
        int mask = 0x0001;
        for (int i = 0; i <= num; i++) {
            int temp = 0;
            for (int j = 31; j >=0; j--) {
                if ((i >> j) & mask != 0){
                    temp++;
                }
            }
            (*result)[i] = temp;
        }
        return *result;
    }
};