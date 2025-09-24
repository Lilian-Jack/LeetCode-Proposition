#include <string>
class Solution {
public:

    string longestPalindrome(string s){
        int l = s.length();
        int start = 0;
        int longMax = 1;    
        for(int i = 0; i<l;i++){
            //teste quand c'est impair ou pair
            for(int j = 0; j<=1; j++){
                int inf = i;
                int supp = i + j;
                while(inf>=0 && supp<l && s[inf]==s[supp]){
                    int longaux = supp - inf + 1;
                    if(longaux > longMax){
                        longMax = longaux;
                        start = inf;
                    }
                    inf--;
                    supp++;
                }
            }
        }
        
        return s.substr(start,longMax);
    }
        
};


/*Brute-Force Solution
    string longestPalindrome(string s) {
        if(isPalindrome(s)) return s;
        else{
            int l = s.length();
            string sub1 = s.substr(0,l-1);
            string sub2 = s.substr(1,l-1);
            if(isPalindrome(sub1)) return sub1;
            else if(isPalindrome(sub2)) return sub2;
            else{
                string c1 = longestPalindrome(sub1);
                string c2 = longestPalindrome(sub2);
                if(c1.length()>c2.length()) return c1;
                else return c2;
            }
        }
    }

*/
