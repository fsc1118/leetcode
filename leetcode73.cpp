#include<set>
#include<vector>
using namespace std;
class Solution {
    typedef struct {
        int x;
        int y;
    } pair;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        set<pair*> a;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    pair* p = new pair();
                    p->x = j;
                    p->y = i;
                    a.insert(p);
                }
            }
        }
        for (pair* p : a){
        
            for (int i = 0; i < n; i++)
                matrix[p->y][i] = 0;
            for (int i = 0; i < m; i++)
                matrix[i][p->x] = 0;
        }

    }
};