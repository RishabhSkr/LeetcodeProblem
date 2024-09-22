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
    void reverse(ListNode *s,ListNode *e){
    ListNode * p=NULL,*c=s,*n=s->next;
     while(p!=e){
         c->next=p;
         p=c;
         c=n;
         if(n!=NULL)
         n=n->next;
     }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
     if(head==NULL || head->next==NULL || k==1)return head;
     ListNode *s=head,*e=head;
     int x=k-1;
     while(x--){
         e=e->next;
        if(e==NULL) return head;
     }
     ListNode * rem=reverseKGroup(e->next,k);
     reverse(s,e);
     s->next=rem;
     return e;
    }
};

// Recursive
    // 	ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode* cursor = head;
    //     for(int i = 0; i < k; i++){
    //         if(cursor == nullptr) return head;
    //         cursor = cursor->next;
    //     }
    //     ListNode* curr = head;
    //     ListNode* prev = nullptr;
    //     ListNode* nxt = nullptr;
    //     for(int i = 0; i < k; i++){
    //         nxt = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nxt;
    //     }
    //     head->next = reverseKGroup(curr, k);
    //     return prev;
    // }

// Iterative
	// ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode* dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode* before = dummy;
    //     ListNode* after = head;
    //     ListNode* curr = nullptr;
    //     ListNode* prev = nullptr;
    //     ListNode* nxt = nullptr;
    //     while(true){
    //         ListNode* cursor = after;
    //         for(int i = 0; i < k; i++){
    //             if(cursor == nullptr) return dummy->next;
    //             cursor = cursor->next;
    //         }
    //         curr = after;
    //         prev = before;
    //         for(int i = 0; i < k; i++){
    //             nxt = curr->next;
    //             curr->next = prev;
    //             prev = curr;
    //             curr = nxt;
    //         }
    //         after->next = curr;
    //         before->next = prev;
    //         before = after;
    //         after = curr;
    //     }
    // }