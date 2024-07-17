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

//  Recursive Traversal: Perform a postorder traversal to ensure that we process all descendant nodes before the current node (node):

// Recursively call processNode for the left child of node and update the left child with the return value.
// Similarly, recursively call processNode for the right child of node and update the right child with the return value.
// Node Evaluation:
// Check if the current node needs to be deleted by checking if its value exists in the toDeleteSet. If the node needs to be deleted:
// If node has a left child that is not null, add the left child to the forest.
// If node has a right child that is not null, add the right child to the forest.
// Delete the current node and return null to effectively remove the node by not reconnecting it to its parent.
// If the node is not to be deleted, return the node itself.
class Solution {
public:
    vector<TreeNode*>ans;
    unordered_set<int>st;
    TreeNode * deleteNode(TreeNode*root){
        if(root==NULL)return NULL;
        root->left =deleteNode(root->left);
        root->right=deleteNode(root->right);
        if(st.find(root->val)!=st.end()){
            if(root->left )ans.push_back( root->left);
            if(root->right)ans.push_back( root->right);
            // delete the curr node and return null to its parent
            delete root;
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
       for(auto it : del)st.insert(it);
        if (root && st.find(root->val) == st.end()) ans.push_back(root);
        root = deleteNode(root);
        return ans;
    }
};