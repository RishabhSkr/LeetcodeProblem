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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // logic : if l1 exist add val else add 0 to the sum ->create a new linked list add sum
        ListNode *head = NULL, *tail = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            if (head == NULL) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        // last if carry exist add it to the number as new node
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
};