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
    // getKthNode
    ListNode* getKthNode(ListNode* head,int k){
        k--;
        while(head!=NULL && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
    // reverse
    ListNode* reversekNode(ListNode * head){
        if(head==NULL || head->next==NULL)return head;
        ListNode * prev = NULL,*curr = head,*nxt = head->next;
        while(curr!=NULL){
            nxt = curr->next; // save the nxt node
            curr->next = prev;
            prev = curr;
            curr= nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head; // Base case

        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode *prevGroupEnd = dummy;
        while(true){
            // get the kthNode
            ListNode*kthNode = getKthNode(prevGroupEnd->next,k);
            if(kthNode==NULL)break; // no nodes left

            // mark the pointers
            ListNode* groupStart = prevGroupEnd->next;
            ListNode * nextGroupStart = kthNode->next;
            // break the node
            kthNode->next = NULL;

            //connect the links
            prevGroupEnd->next = reversekNode(groupStart);
            groupStart->next = nextGroupStart;

            // Move prevGroupEnd to the end of the reversed group
            prevGroupEnd = groupStart;
        }
        return dummy->next;
    }
};  