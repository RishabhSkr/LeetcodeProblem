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
    bool solve(TreeNode * root1,TreeNode*root2){
          if (root1 == NULL && root2 == NULL) return true; // Both are NULL
        if (root1 == NULL || root2 == NULL) return false; // One is NULL, the other is not
        if (root1->val != root2->val) return false; // Values don't match

         // Check if trees are equivalent without flip or with flip
        bool noFlip = solve(root1->left,root2->left) && solve(root1->right,root2->right);
        bool flip = solve(root1->left ,root2->right) && solve(root1->right ,root2->left);
        return noFlip || flip;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};
// (1,2,3) (1,2,null,3)