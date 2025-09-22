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
    int taille(liste l1){
        if(l1==nullptr) return 0;
        else return 1 + taille(l1->next);
    } 
    bool plusGrand(int x, int y){
        if(x>y) return true;
        else return false;
    }

 int puissance(int x, int n){
    if(n==0) return 1;
    else if (n==1) return x;
    else return x*puissance(x,n-1);
}

int nListe(liste l1,int taille){
    if(l1==nullptr) return 0;
    else return l1->val*puissance(10,taille) + nListe(l1->next,taille-1);
}
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

void somme(liste l1, liste l2, liste & l3,int reste){
    if(l1!=nullptr && l2!=nullptr){
        int n = l1->val + l2->val + reste;
        if(n>9){
             reste= n/10;
            n = n % 10;
        }else reste= 0;
        std::cout << n << " " << reste << std::endl;
        ajouterFin(l3,n);
        somme(l1->next,l2->next,l3,reste);
    }else if(l1==nullptr && l2!=nullptr){
        int n = l2->val + reste;
        if(n>9){
            reste= n/10;
            n = n % 10;
            
        }else reste =0;
        std::cout << n << " " << reste << std::endl;
        ajouterFin(l3,n);
        somme(nullptr,l2->next,l3,reste);
    }else if(l2==nullptr && l1!=nullptr){
        int n = l1->val + reste;
        if(n>9){
            reste= n/10;
            n = n % 10;
            
        }else reste= 0;
        std::cout << n << " " << reste << std::endl;
        ajouterFin(l3,n);
        somme(l1->next,nullptr,l3,reste);
    }else if(l1==nullptr && l2==nullptr && reste!=0){
        ajouterFin(l3,reste);
    }
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      

        liste l3;
        initialise(l3);
        int reste = 0;
        somme(l1,l2,l3,reste);
        return l3;
    }
};
