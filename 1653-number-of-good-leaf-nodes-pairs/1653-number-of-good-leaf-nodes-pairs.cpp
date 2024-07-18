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
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> st;

    void makeGraph(TreeNode* root) {
        if (root == NULL) return;

        bool isLeaf = true;
        
        if (root->left) {
            isLeaf = false;
            adj[root->left].push_back(root);
            adj[root].push_back(root->left);
        }
        
        if (root->right) {
            isLeaf = false;
            adj[root->right].push_back(root);
            adj[root].push_back(root->right);
        }

        if (isLeaf) {
            st.insert(root); // stpre the leaf node in st
        }

        //traverse the entire tree
        makeGraph(root->left);
        makeGraph(root->right);
    }

    int countPairs(TreeNode* root, int distance) {
        makeGraph(root);
        int n= adj.size();
        int cntPair = 0;
        for(auto &leaf : st){
            queue<TreeNode*>que;
            set<TreeNode*>vis;
            que.push(leaf);
            vis.insert(leaf);

            for(int level = 0;level<=distance;level++){ // while(q.empty()==false) ke jagahpr lv
                int size = que.size();
                while(size--){
                    TreeNode*curr = que.front();
                    que.pop();
                    if(curr!=leaf && st.count(curr)>0){
                        cntPair++;
                    }

                    for(auto &nbr : adj[curr]){
                        if(vis.count(nbr)==0){
                            que.push(nbr);
                            vis.insert(nbr);
                        }
                    }
                }
            }
            
        }
        return cntPair/2;
    }
};