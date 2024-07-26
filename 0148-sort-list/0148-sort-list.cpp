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
     ListNode *findmiddle(ListNode *head){
        ListNode *slow=head,*fast=head;
        fast=fast->next; // fast phle se ek bada denge taaki even len mein bich wla hi mid ho
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
     }
     ListNode *merge(ListNode *list1,ListNode *list2){
        ListNode *dummynode=new ListNode(0);
        ListNode *temp=dummynode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){ // compare kr rhe hai left or right k list ko
                temp->next=list1; // left chota hai toh temp mein daal do jo temp dummynode ko point kra
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
            if(list1) temp->next=list1;  // agr list1 exhaust ni hua toh sari value daal denge
            else temp->next=list2;
            
            return dummynode->next; 
     }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){ // edge case
            return head;
        }
        ListNode *middle=findmiddle(head);  // middle find krna hai
         ListNode *right=middle->next; // left or right mein todenge toh middle+1 right ka hoga
         middle->next=nullptr; // kyu ki humne left or right mein tood diya toh middle ka  agla null hoga
        ListNode *left=head; // left or right mein todenge toh left head p point krega
        left=sortList(left);
       right=sortList(right);
        return merge(left,right); // left or right list merge hoo rhi hai
    }
};