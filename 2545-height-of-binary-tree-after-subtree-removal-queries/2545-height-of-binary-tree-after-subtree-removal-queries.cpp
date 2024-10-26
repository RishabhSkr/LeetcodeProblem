/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int nodeLevel[100001]; // level of each node
    int height[100001]; // height of each node
    int levelMaxHeight[100001];
    int levelSecondMax[100001];

    int solve(TreeNode * root,int level){
        if(root==NULL)return 0;

        nodeLevel[root->val]=level;
        height[root->val]=1+max(solve(root->left,level+1),solve(root->right,level+1));

        // check and store max height at each level
        if(levelMaxHeight[level]<height[root->val]){
            levelSecondMax[level]=levelMaxHeight[level];
            levelMaxHeight[level]=height[root->val];
        }else if(levelSecondMax[level]<height[root->val]){
            levelSecondMax[level]=height[root->val];
        }
        
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        solve(root,0);
        vector<int>res;
        for(auto node : queries){
            //  if(maxHeight[node]==node) L+H-1
                int level = nodeLevel[node]; 
                int ans = nodeLevel[node]+((height[node]==levelMaxHeight[level])?levelSecondMax[level]:levelMaxHeight[level])-1;
            res.push_back(ans);
        }
        return res;
    }
};