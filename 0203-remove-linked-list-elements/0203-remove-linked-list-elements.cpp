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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev=NULL,*ptr  = head;
        ListNode * dummy = new ListNode(-1);
            dummy->next = head;
            prev=dummy;
            ptr=dummy->next;
            while(ptr!=NULL){
                if(ptr->val==val){
                    ListNode *temp = ptr;
                    prev->next = ptr->next;
                    ptr=ptr->next;
                    delete temp;
                }
                else{
                    prev = ptr;
                    ptr=ptr->next;
                }
            }
        return dummy->next;
    }
};