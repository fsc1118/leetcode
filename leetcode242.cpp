#include<map>
#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        int length = s.length();
        if (t.length() != length)
            return false;
        for (int i = 0; i < length; i++){
            char c = s.at(i);
            if (m.count(c) != 0)
                m[c] = m[c] + 1;
            else
                m[c] = 1;
        }
        for (int i = 0; i < length; i++){
            char c= t.at(i);
            //cout<<m[c]<<endl;
            if (m.count(c) == 0 || m[c] == 0)
                return false;
            else    
                m[c] = m[c] - 1;
        }
        return true;
    }
};