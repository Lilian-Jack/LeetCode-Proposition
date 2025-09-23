#include <string> 
class Solution {
public:
    bool isPalindrome(int x) {
        std::string c = std::to_string(x);
        int l = c.length();
        for(int i = 0; i<l/2; i++){
            if(c[i]!=c[l-i-1]) return false;
        }
        return true;
    }
};
