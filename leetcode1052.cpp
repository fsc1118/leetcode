#include<vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int count = 0;
        int length = customers.size();
        for (int i = 0; i < length; i++){
            if (grumpy[i] == 0)
                count = count + customers[i];
        }
       // cout<<length<<endl;
        int reduce = 0;
        int result = 0;
        for (int i = 0; i <= length - X; i++){
            //cout<<1<<endl;
            if (i == 0){
                int count = 0;
                while (count < X){
                    if (grumpy[count])
                        result = result + customers[count];
                    count++;            
                }
                reduce = result;
              //  cout<<reduce<<endl;
            } else {
                if (grumpy[i - 1])
                    result = result - customers[i - 1];
                if (grumpy[i + X - 1])
                    result = result + customers[i + X - 1];
                reduce = max(reduce, result);
                cout<<reduce<<endl;
            }
        }
        return count + reduce;
    }
};