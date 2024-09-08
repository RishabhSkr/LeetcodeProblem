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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode * ptr= head;
        while(ptr!=NULL){
            n++;
            ptr= ptr->next;
        }

        int eleSize = n/k;
        int extra = n%k;
        ListNode *node = head;
        vector<ListNode*>ans;
  
        for(int i =0;i<k;++i){
            // push the first node of each partition
            ans.push_back(node);
                
            // Each partition
            int partSize = eleSize +( (extra>0)?1:0); // bug use bracket
            for(int cnt = 0;cnt<partSize-1;cnt++){
                if(node!=NULL){
                   node = node->next;
                }
            }

            if(node!=NULL){
                ListNode * temp =node->next;
                node->next= NULL;
                node = temp;
            }
            extra--;
        }
        return ans;
    }
};