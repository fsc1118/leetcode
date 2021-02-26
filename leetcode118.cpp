#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int count = 1;
        vector<vector<int>> result;
        vector<int>* pointer = 0;
        while (count <= numRows){
            vector<int>* a = new vector<int>(count);
            (*a)[0] = 1; // first element is 1
            (*a)[count - 1] = 1; //last element is 1
            for (int i = 1; i < count - 1; i++)
                (*a)[i] = (*pointer)[i - 1] + (*pointer)[i];          
            pointer = a;
            count++;
            result.push_back(*a);
        }
        return result;
    }
};