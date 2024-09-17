class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }

    // Insert a char into the Trie
    void put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }

    // Check if char exists
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    // Get the child node for a char
    TrieNode* gets(char ch) {
        return children[ch - 'a'];
    }

    // Mark the end of a word
    void setEnd() {
        isEnd = true;
    }

    // Check if it is the end of a word
    bool isWordEnd() {
        return isEnd;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->gets(ch);
        }
        node->setEnd();
    }


};
 int solve(int i ,string &target,TrieNode*root,vector<int>&dp){
    
    if(i==target.size())return 0;
    if(dp[i]!=-1)return dp[i];

    TrieNode*node=root;
    int res = 1e9;

    for(int k = i;k<target.size();++k){
        if(!node->containsKey(target[k]))break;
        node=node->gets(target[k]);
        res = min(res,1+solve(k+1,target,root,dp));
    }

    return dp[i]=res;
 }

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;

        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }
        int n = target.size();
        vector<int>dp(n+1,-1);
        int res = solve(0,target,trie.root,dp);
        if(res>=1e9)return -1;
        return res;
    }
};
