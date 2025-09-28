class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows==1) return s;
        int longueur = s.length();
        std::string zigzag  = "";
        std::vector<std::vector<char>> matrice(numRows, std::vector<char>(longueur, ' '));
        int n=0;
        int m=0;
        bool descente = true;
        for(int i = 0; i<longueur; i++){
            matrice[n][m]=s[i];
            if(descente){
                if(n<numRows-1) n++;
                else{
                    descente = false;
                    n--;
                    m++;
                }
            }else{
                if(n==0) {
                    descente = true;
                    n++;
                }
                else{
                    n--;
                    m++;
                }
            }
        }
        for(int i = 0; i<numRows;i++){
            for(int j = 0; j<longueur; j++){
                if(matrice[i][j]!=' ')zigzag = zigzag + matrice[i][j];
            }
        }
        return zigzag;
}
};
