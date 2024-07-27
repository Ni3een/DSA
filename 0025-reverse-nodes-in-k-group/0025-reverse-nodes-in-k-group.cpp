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
    ListNode *reverse(ListNode *temp){  
        ListNode *prev = NULL;  
        while(temp != NULL){  
            ListNode *front = temp->next;  
            temp->next = prev;  
            prev = temp ;
            temp = front;  
        }
        return prev; 
    }
    ListNode *findkthelement(ListNode *temp,int k){
        k-=1; // phle mein toh khada hi hu toh k-1 steps chalunga!!!
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
            ListNode *kthelement=findkthelement(temp,k);
            if(kthelement==NULL){ // agr k ki value 2 hai or 1 hi element bcha hai toh
              if(prev)  prev->next=temp; // jo prev ka next temp de do
              break;
            }
            ListNode *nextnode=kthelement->next; // age jodne hai toh kth ko next de do
            kthelement->next=NULL; // puri list ko reverse toh kr ni skte toh
            reverse(temp);         // toh kth element tk toh kr skte hai toh parts krdo
            if(temp==head){ // yaani phla kth node hoga
                head=kthelement;
            }
            else{
                prev->next=kthelement;
            }
            prev=temp; // value 
            temp=nextnode;
        }
        return head;
    }
};