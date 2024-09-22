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
        // Observe->
        // rotate head to n-k-1 times why because every time head will n-k+1 node from left
        // n-kth node will be last node
        // 1.convert it into CLL ->
        // 2. rotate n-k+1 time head
        //3. diconnect n-kth node
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int len = 0;
        ListNode * temp =head,*tail = NULL;
        while(temp!=NULL){
            len++;
            tail=temp;
            temp= temp->next;
        }
        tail->next=head; // cll
        k = k%len;
        int cnt = len-k-1;
        temp = head;
        while(cnt--){
            temp = temp->next;
        }
        head=temp->next;
        temp->next = NULL;
        return head;
        
    }
};