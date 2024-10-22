/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#define ll long long
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // priority_queue min heap me store krte jaao level ka sum (nlogn)
        priority_queue<ll>pq;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
           
            int n = q.size();
            ll sum =0;
            while(n--){
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            pq.push(sum);
        }
        if(pq.size()<k)return -1;
        ll ans  = 0;
        while(k){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;

    }
};