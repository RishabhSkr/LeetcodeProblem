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
int HeightBTree(TreeNode *root){
    if(root==NULL)return 0;
    int LeftH=HeightBTree(root->left);
    int RightH=HeightBTree(root->right);
    return 1+max(LeftH,RightH);
}
int Diameter(TreeNode* root){
    if(root==NULL) return 0;
    int  leftH=0, rightH=0,Dia=0;
    Dia=HeightBTree(root->left)+HeightBTree(root->right);
    leftH=Diameter(root->left);
    rightH=Diameter(root->right);
    return max(leftH,max(rightH,Dia));
}
    int diameterOfBinaryTree(TreeNode* root) {
        return Diameter(root);
    }
};