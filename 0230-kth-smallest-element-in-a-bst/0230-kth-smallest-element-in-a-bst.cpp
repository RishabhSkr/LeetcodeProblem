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
     priority_queue<int> pq;  // Max-heap to store the k smallest elements
    void solve(TreeNode *root, int k) {
        if (root == NULL) return;
        
        // Push current node value into the priority queue
        pq.push(root->val);
        
        // If the size of the priority queue exceeds k, remove the largest element
        if (pq.size() > k) {
            pq.pop();
        }

        // Recurse for the left and right subtrees
        solve(root->left, k);
        solve(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return pq.top();
    }
};