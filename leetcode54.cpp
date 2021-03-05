#include<vector>
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
using namespace std;
class Solution {
    int up_limit = 0;
    int down_limit;
    int right_limit;
    int left_limit = 0;
public:
    int direction = RIGHT;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        down_limit = matrix.size() - 1;
        right_limit = matrix[0].size() - 1;
        vector<int> result;
        int size = 1;
        int target = (down_limit + 1) * (right_limit + 1);
      //  cout<<target<<endl;
        while (size <= target){
            
            if (direction == RIGHT){
                for (int i = left_limit; i <= right_limit; i++) {
                    size++;
                    result.push_back(matrix[up_limit][i]);
                   // cout<<matrix[up_limit][i]<<endl;
                }
                up_limit++;
                direction = DOWN;
            } else if (direction == DOWN){
                for (int i = up_limit; i <= down_limit; i++) {
                    size++;
                    result.push_back(matrix[i][right_limit]);
                    //cout<<matrix[i][right_limit]<<endl;
                }
                right_limit--;
                direction = LEFT;            
            } else if (direction == LEFT){
                for (int i = right_limit; i >= left_limit; i--) {
                    size++;
                    result.push_back(matrix[down_limit][i]);
                    //cout<<matrix[down_limit][i]<<endl;
                }
                down_limit--;
                direction = UP;        
            } else{
                for (int i = down_limit; i >= up_limit; i--) {
                    size++;
                    result.push_back(matrix[i][left_limit]);
                  //  cout<<matrix[i][left_limit]<<endl;
                }
                left_limit++;
                direction = RIGHT;  
            }     
        }
        //cout<<size<<endl;
        return result;
    }
};