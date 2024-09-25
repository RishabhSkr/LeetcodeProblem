struct TrieNode {
public:
    TrieNode *children[26]; // Array to store child nodes for each letter
    bool flag; // Flag to indicate if this node is the end of a word
    int prefixCnt;
    TrieNode() {
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr; // Initialize all children to nullptr
            prefixCnt =0;

        }
        flag = false; // Initialize flag to false
    }
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr; // Check if the child node exists
    }
    void puts(char ch, TrieNode *node) {
        children[ch - 'a'] = node; // Create a link to the child node
    }
    TrieNode *getChar(char ch) {
        return children[ch - 'a']; // Get the reference to the child node
    }
    void setEnds() {
        flag = true; // Mark this node as the end of a word
    }
    bool isEnd() {
        return flag; // Check if this node is the end of a word
    }
    void increasePrefixCnt(){
        prefixCnt++;
    }
    int getprefixCnt(){
        return prefixCnt;
    }
};

class Trie {
    TrieNode *root; // Root node of the Trie
public:
    Trie() {
       root = new TrieNode(); // Initialize the root node
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode *node = root; // Start from the root
        for(int i = 0; i < n; ++i) {
            if(!node->containsKey(word[i])) { 
               node->puts(word[i], new TrieNode()); // Create a new node if it doesn't exist
            }
            node = node->getChar(word[i]); // Move to the next node
            node->increasePrefixCnt();
        }
        node->setEnds(); // Mark the end of the word
    }
    
    int startsWith(string prefix) {
        TrieNode *node = root; 
        int ans = 0;
        for(int i = 0; i < prefix.size(); ++i) {
            if(node->containsKey(prefix[i])) {
               node = node->getChar(prefix[i]); // Move to the next node
               ans+=node->getprefixCnt();
            } else {
                return ans; // Prefix not found
            }
        }
        return ans; // Prefix found
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie * ptr= new Trie();
        for(auto w : words){
            ptr->insert(w);
        }
        vector<int>res;
        int ans = 0;
        for(auto w : words){
            ans=ptr->startsWith(w);
            res.push_back(ans);
        }
        return res;
    }
};