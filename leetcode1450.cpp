#include<vector>
using namespace std;
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int result = 0;
        int length = startTime.size();
        for (int i = 0; i < length; i++){
            if (queryTime >= startTime.at(i) && queryTime <= endTime.at(i))
                result++;
        }
        return result;
    }
};