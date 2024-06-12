// class TrieNode{
//     public:
//         int *children[26];
//         bool flag;
//     TrieNode(){
//         for(int i=0;i<26;++i)children[i]=nullptr;
//         flag = false;
//     }
// };
struct TrieNode {
public:
    TrieNode *children[26]; // Array to store child nodes for each letter
    bool flag; // Flag to indicate if this node is the end of a word
    TrieNode() {
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr; // Initialize all children to nullptr
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
        }
        node->setEnds(); // Mark the end of the word
    }
    
    bool search(string word) {
        TrieNode *node = root; 
        for(int i = 0; i < word.size(); ++i) {
            if(node->containsKey(word[i])) {
                node = node->getChar(word[i]); // Move to the next node
            } else {
                return false; // Word not found
            }
        }
        return node->isEnd(); // Check if the word ends here
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root; 
        for(int i = 0; i < prefix.size(); ++i) {
            if(node->containsKey(prefix[i])) {
               node = node->getChar(prefix[i]); // Move to the next node
            } else {
                return false; // Prefix not found
            }
        }
        return true; // Prefix found
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */