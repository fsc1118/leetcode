#include<vector>
#include<stdlib.h>
using namespace std;
class NumMatrix {
    int* m;
    int height;
    int width;
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int height = matrix.size();
        if (height == 0)
            return;
        this->height = height;
        int width = matrix[0].size();
        this->width = width;
        m = (int*)malloc(sizeof(int) * height * width);
        *m = matrix[0][0];
        for (int i = 0; i < height; i++){
            
            for (int j = 0; j < width; j++){
                if (i == 0){
                    if (j == 0)
                        continue;
                    *(m + j) = matrix[0][j] + *(m + j - 1);
                } else if (j == 0) {
                    *(m + i * width) = matrix[i][0] + *(m + (i - 1) * width);
                } else {
                    *(m + i * width + j) = *(m + (i - 1) * width + j) + 
                    *(m + i * width + j - 1) - *(m + (i - 1) * width + j - 1) + matrix[i][j];
                }          
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (col1 == 0 && row1 == 0)
            return *(m + row2 * width + col2);
        if (col1 == 0){
            return *(m + row2 * width + col2)  - *(m + (row1 - 1) * width + col2);
        }
        if (row1 == 0){
            return *(m + row2 * width + col2) - *(m + row2 * width + col1 - 1);
        }
        return *(m + row2 * width + col2) - *(m + row2 * width + col1 - 1) - *(m + (row1 - 1) * width + col2) + *(m + (row1 - 1) * width + col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */