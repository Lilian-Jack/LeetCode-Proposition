class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double n = nums2.size();
        double m = nums1.size();
        int taille = n+m;
        vector<int> nums3(taille);
        for(int i = 0; i<n+m; i++){
            if(!nums2.empty() && !nums1.empty()){
                if(nums1.front()<nums2.front()){
                    nums3.insert(nums3.begin() + i,nums1.front());
                    nums1.erase(nums1.begin());
                }else{
                    nums3.insert(nums3.begin() + i,nums2.front());
                    nums2.erase(nums2.begin());
                }
            }else if(!nums2.empty()){
                nums3.insert(nums3.begin() + i,nums2.front());
                nums2.erase(nums2.begin());
            }else if(!nums1.empty()){
                nums3.insert(nums3.begin() + i,nums1.front());
                nums1.erase(nums1.begin());
            }
        }
        if(taille%2==0){
            double m1 = nums3[taille/2-1];
            double m2 = nums3[taille/2];
            return (m1+m2)/2;
        }else{
            int m1 = taille/2;
            return nums3[m1];
        }   
        
    }
};
