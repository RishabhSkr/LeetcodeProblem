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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode * curr = head;
        ListNode * nxt = head->next;
        swap(curr->val,nxt->val);
        while(curr!=NULL && nxt!=NULL){
            curr = nxt->next;
            if(curr==NULL)break;
            nxt = curr->next;
            if(nxt!=NULL)swap(curr->val,nxt->val);
        }   
        return head;
    }
};