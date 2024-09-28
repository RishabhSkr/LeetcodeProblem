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
/*
       #---->@---->@---->@---->@---->@---->@
                   ^     ^
                   pre   cur

      1. pre->next = cur->next
                    __________
                   /          \
       #---->@---->@     @---->@---->@---->@
                   ^     ^
                   pre   cur

      2. pre = pre->next
                    __________
                   /          \
      #---->@---->@      @---->@---->@---->@
                         ^     ^
                         cur   pre

      3. cur->next = pre->next
                    __________
                   /          \
       #---->@---->@     @     @---->@---->@
                          \_________/
                         ^     ^
                         cur   pre

      4. pre->next = cur
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^     ^
                        cur   pre
    
      5. pre = cur; cur = cur->next
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^           ^
                        pre         cur
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * prev =dummy;
        ListNode * curr = dummy->next;
        // method 2 without swapping values swap by pointers
        while(curr!=NULL && curr->next!=NULL){
            prev->next = curr->next;
            prev =prev->next;
            curr->next = prev->next;
            prev ->next= curr;
            prev = curr;
            curr= curr->next;
        }   
        return dummy->next;
    }
};