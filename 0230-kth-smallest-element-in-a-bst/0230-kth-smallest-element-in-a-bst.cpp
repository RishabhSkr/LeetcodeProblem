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
        int ans = -1; // Max-heap to store the k smallest elements
    void solve(TreeNode *root, int k,int &cnt) {
        if (root == NULL) return;
        // do inorder traversal
        solve(root->left, k,cnt);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        solve(root->right, k,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        solve(root,k,cnt);
        return ans;
    }
};