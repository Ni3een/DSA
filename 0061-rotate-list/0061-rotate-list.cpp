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
    ListNode *lastNode(ListNode *temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        int len=1;
        ListNode *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
            
        } 
        
        if(k%len==0) return head;  // agr len mera multiplier hua k ka jaise k
        k=k%len;                     // mera 15  hai or len 5 toh whi ayega
        // attach tail to head
        tail->next=head;
        ListNode *newlastnode=lastNode(head,len-k); // len - k krenge toh new tail
        head=newlastnode->next;                    // ayega
        newlastnode->next=NULL;
        return head;
    }
};