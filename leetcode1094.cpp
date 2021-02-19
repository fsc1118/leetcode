#include<vector>
#include<map>
using namespace std;
class Solution {
    map<int, int> change;

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxOn = -1;
        for (vector<int> a : trips){
            int onboard = a[1];
            int offboard = a[2];
            int num = a[0];
            maxOn = max(maxOn, onboard);
            if (change.find(onboard) == change.end()){
                change.insert(pair<int, int>(onboard, num));
            } else{
                change[onboard] = change[onboard] + num;
            }
            if (change.find(offboard) == change.end()){
                change.insert(pair<int, int>(offboard, -1 * num));
            } else{
                change[offboard] = change[offboard] - num;
            }
        }
        int currentPasseneger = 0;
        for (int i = 0; i <= maxOn; i++){
            currentPasseneger = currentPasseneger + change[i];
            if (currentPasseneger > capacity)
                return false;
        }
        return true;

    }
};