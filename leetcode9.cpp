#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        auto last = str.length() - 1;
        int head = 0;
        while (last > head){
            if (str.at(head++) != str.at(last--))
                return false;
        }
        return true;
    }

};