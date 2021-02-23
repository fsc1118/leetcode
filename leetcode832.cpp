#include<vector>
using namespace std;
class Solution {
    void reverse(vector<int>& A){
        int first = 0;
        int last = A.size() - 1;
        while (first <= last){
            int temp = A.at(first);
            A[first++] = A[last];
            A[last--] = temp; 
        }
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int length = A.size();
        for(int i = 0; i < length; i++)
            reverse(A.at(i));
        for (vector<int>& k : A){
            int length = k.size();
            for (int i = 0; i < length; i++){
                k.at(i) = 1 - k.at(i);
               // cout<<k.at(i)<<endl;
            }
        }
     
        return A;
    }
    
};