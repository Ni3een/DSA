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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0);
        ListNode *head=l3;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int value=l1->val+l2->val+carry;
             carry=value/10; //16/10=1 // jb sum krke k value 9 se bdi agyi toh integer devesion krenge
             l3->next=new ListNode(value%10); // 6+4=10 10%10=0
             l3=l3->next; // L3 MOVE krega apne resultant list mei 
             l2=l2->next; // l2 apne node mein move krega
             l1=l1->next; // l1 apne mein krega
        }
        while(l1){
            int value=l1->val+carry;
             carry=value/10; //16/10=1
             l3->next=new ListNode(value%10);
             l3=l3->next;
             l1=l1->next;
        }
        while(l2){
            int value=l2->val+carry;
             carry=value/10; //16/10=1
             l3->next=new ListNode(value%10);
             l3=l3->next;
             l2=l2->next;
        }
        if(carry){
            l3->next=new ListNode(carry); // agr last mein carry bchta hai 
        }                                // toh ek naya node mein store

             return head->next;
        
    }
};