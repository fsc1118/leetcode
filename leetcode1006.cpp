
#define ADD 1
#define MINUS 2
#define MULTIPLY 3
#define DIV 4
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        int result = 0;
        int s = N--;
        int next_step = MULTIPLY;
        while (N >= 1){
            if (next_step == ADD){
                next_step = MINUS;
                result += s;

                s = N;
            } else if (next_step == MINUS){
                next_step = MULTIPLY; 
                result += s;
                s = -1 * N;
            } else if (next_step == MULTIPLY){
                s *= N;
                next_step = DIV;   
            } else{
                s /= N;
                next_step = ADD;
            }
            N--;
        }
        return result + s;
    }
};