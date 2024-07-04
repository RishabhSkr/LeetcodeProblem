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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*curr=head,*ptr =head,*nxt = head->next;
        while(nxt!=NULL){
            int sum =0;
            while(nxt->val!=0){
                sum+=nxt->val;
                nxt =nxt->next;
            }
            if(ptr==head){
                ptr->next = new ListNode(sum);
                ptr=ptr->next;
                curr= ptr;
            }else{
               ptr->next = new ListNode(sum);
               ptr=ptr->next;
            }
            nxt = nxt->next;
            
        }
        return curr;
    }
};