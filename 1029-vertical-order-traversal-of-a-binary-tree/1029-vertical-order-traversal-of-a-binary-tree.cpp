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
 struct nodeData{
    int val;
    int row;
    int col;
 };

class Solution {
public:
    map<int,vector<nodeData>>mp;
    static bool comp(const nodeData& data1, const nodeData& data2){
        if(data1.row==data2.row) return data1.val<data2.val;
        return data1.row<data2.row;
    }
   void solve(TreeNode * root,int row,int col){
        if(root==NULL)return ;
        solve(root->left,row+1,col-1);
        mp[col].push_back({root->val,row,col});
        solve(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // since we need to store we some how need the traversal it can be any type ()
        // since we need to store colwise node we need to define some data structure and if 
        // same col appears push the nodes in it
        // now sort the col ans 
        // push the final int res.
        solve(root,0,0);
        vector<vector<int>>res;
        for(auto data : mp){
            vector<int>temp;
            auto storedData = data.second;
            sort(storedData.begin(),storedData.end(),comp);
            for(auto x : storedData){
                temp.push_back(x.val);
            }
            res.push_back(temp);
        }
        return res;
    }
};