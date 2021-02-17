#include<vector>
using namespace std;
class Solution {
    
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int length = T.size();

        vector<int> result(length);
        if (length == 1){
            result[0] = 0;
            return result;
        }
        result[length - 1] = 0;
        for (int i = length - 2; i >= 0; i--){
            if (T[i] < T[i+1]){
                result[i] = 1;
            } else{
                if (result[i + 1] == 0){
                    result[i] = 0;
                } else{
                    for (int j = i + 1 + result[i + 1]; j < length; j++){
                        if (T[j] > T[i]){
                            result[i] = j - i;
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};