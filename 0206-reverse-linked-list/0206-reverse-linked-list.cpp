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
    ListNode* reverseList(ListNode* head) {  
        if(head==NULL){  
            return NULL;  
        }  
        if(head->next == NULL){  
            return head;  
        }  

        ListNode *curr = head;  
        ListNode *prev = NULL;  
        while(curr != NULL){  
            ListNode *front = curr->next;  // curr ki next ki node front mein de do
            curr->next = prev;   // curr next ki value piche de do kyu ki reverse k baad curr k nodes bhi reverse hogye
            prev = curr;  // piche ki value age de do
            curr = front;  // or age bdte rho
        }  

        return prev;  
    }  
};
    
    