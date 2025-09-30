class Solution {
public:
    int longueurPlusPetiteChaine(vector<string> str){
        int longueur = str[0].length();
        for(int i =1;i<str.size();i++){
            if(str[i].length()<longueur) longueur = str[i].length();
        }
        return longueur;
    } 

    string longestCommonPrefix(vector<string>& strs) {
        int longueur = strs.size();
        int plusPetit = longueurPlusPetiteChaine(strs);
        string prefix = "";
        bool condition;
        for(int i = 0; i<plusPetit; i++){
            condition = true;
            for(int j = 0; j<longueur-1; j++){
                if(strs[j].substr(i,1)!=strs[j+1].substr(i,1)) condition =false;
            }
            if(condition) prefix = prefix + strs[0].substr(i,1);
            else break;
        }
        return prefix;
    }
};
