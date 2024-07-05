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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL)return {-1,-1};
        int maxi = INT_MIN, mini = INT_MAX;
        int p1 = -1,p2 =-1;
        int cnt = 1; 
        ListNode* prev = head;
        ListNode* curr = head->next;

    while (curr != nullptr && curr->next != nullptr) {
        if ((curr->val > prev->val && curr->val > curr->next->val) || 
            (curr->val < prev->val && curr->val < curr->next->val)) {
            if (p1 == -1) {
                p1 = cnt;
            } else {
                mini = min(mini, abs(cnt - p2));
                maxi = max(maxi, abs(cnt - p1));
            }
            p2 = cnt;
        }
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (mini == INT_MAX || maxi == INT_MIN) {
        return {-1, -1};
    }

    return {mini, maxi};
    }
};