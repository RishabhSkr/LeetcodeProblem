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
    ListNode* deleteDuplicates(ListNode* head) {
         if(head ==NULL || head->next ==NULL)return head;
        ListNode * prev= NULL,*curr = head,*nxt = head->next;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val!=nxt->val){
                prev = curr;
                curr=nxt;
                nxt = nxt->next;
            }else{
                if(head->val==nxt->val){
                    curr=nxt;
                    nxt = nxt->next;
                    head= nxt;
                }else{
                    int val = curr->val;
                    while(nxt!=NULL && val==nxt->val){
                        curr=nxt;
                        nxt = nxt->next;
                    }
                    prev->next=curr->next;
                    curr=nxt;
                    if(nxt!=NULL)
                    nxt = nxt->next;
                    
                }
            }
        }
        return head;
    }
};