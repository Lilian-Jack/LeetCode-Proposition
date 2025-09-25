/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
using liste = ListNode*;
void initialise(liste & L)
{
    L=nullptr;
}

void ajouterFin(liste & l1, int n){
    if(l1==nullptr){
        liste aux = new ListNode;
        aux->next = l1;
        aux->val = n;
        l1 = aux;
    }else ajouterFin(l1->next,n);
    
}

liste merge(liste L1, liste L2, liste & L3){
    if(L1==nullptr & L2==nullptr) return L3;
    else if(L2==nullptr || (L1!=nullptr && L1->val<=L2->val)){
        ajouterFin(L3,L1->val);
        merge(L1->next,L2,L3);
    }else{
        ajouterFin(L3,L2->val);
        merge(L1,L2->next,L3);
    }
    return L3;
}
    ListNode* mergeTwoLists(ListNode* nums1, ListNode* nums2) {
        liste L3;
        initialise(L3);
        return merge(nums1,nums2,L3);
    }
};
