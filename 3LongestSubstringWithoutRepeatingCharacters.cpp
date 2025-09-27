class Solution {
public:
    bool estPresent(string s, char c){
        for(int i = 0; i<s.length(); i++){
            if(c==s[i]) return true; 
        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        if(s==" ") return 1;
        int longueur;
        string longSub ="";
        string sub;
        for(int i =0; i<s.length(); i++){
            sub = s[i];
            for(int j = i +1; j<s.length(); j++){
                if(estPresent(sub,s[j])) break;
                else sub = sub + s[j];
            }
            if(sub.length()>longSub.length()) longSub = sub;
        }
        return longSub.length();
    }
};
