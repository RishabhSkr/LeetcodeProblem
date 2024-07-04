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
unordered_map<string, int> subtreeMap;
vector<TreeNode*> ans;

// Helper function to generate string representation of each subtree
string serialize(TreeNode* root) {
    if (root == NULL) return "#"; // Base case: empty node
    
    // Generate the string for the current subtree
    string left = serialize(root->left);
    string right = serialize(root->right);
    string str = to_string(root->val) + "," + left + "," + right;
    
    // Check if this subtree has already been seen
    if (subtreeMap[str] == 1) {
        ans.push_back(root); // Add to result if it's a duplicate
    }
    subtreeMap[str]++;
    
    return str;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        subtreeMap.clear();
        ans.clear();
        serialize(root);
        return ans;
    }
};