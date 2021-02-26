#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return *recursion(rowIndex + 1);
    }
    vector<int>* recursion(int rowIndex){
        vector<int>* v = new vector<int>(rowIndex);
       // cout<<(*v).size()<<endl;
        (*v)[0] = 1; // first element is 1
        (*v)[rowIndex - 1] = 1; //last element is 1
      //  cout<<(*v).size()<<endl;
        if (rowIndex == 1)
            
            return v;
        
        vector<int>* prev = recursion(rowIndex - 1);
        for (int i = 1; i < rowIndex - 1; i++)
                (*v)[i] = (*prev)[i - 1] + (*prev)[i];
        delete(prev);
        return v;        
    }
};