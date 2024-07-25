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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummynode =
            new ListNode(0); // ek dummy node banao jiski val 0ho
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* temp = dummynode;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val <
                t2->val) { // compare kro jiski value choti hogi usko lo
                temp->next =
                    t1; // temp->next mein t1 daaal do ku ki woh choti hai
                temp = t1;
                t1 = t1->next; // t1 ko aage badate rho
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1)
            temp->next = t1; // agr t1 exhaust ho jaye toh sari value daal do
        else {
            temp->next = t2;
        }
        return dummynode->next;
    }
};