class Solution {
public:
    bool estPresent(vector<int>nums, int x){
        int taille = nums.size();
        for(int i = 0; i<taille; i++){
            if(nums[i]==x) return true;
        }
        return false;
    }
    int removeDuplicates(vector<int>& nums) {
        int taille = nums.size();
        vector<int> aux(taille,-101);
        int indice = 0;
        for(int i = 0; i<taille; i++){
            if(!estPresent(aux,nums[i])){
                aux[indice]=nums[i];
                indice++;
            }
        }
        nums=aux;
        return indice;
    }
};
