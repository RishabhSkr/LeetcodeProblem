struct TrieNode {
public:
    TrieNode *children[10]; // Array to store child nodes for each letter
    bool flag; // Flag to indicate if this node is the end of a word
    TrieNode() {
        for(int i = 0; i <=9; ++i) {
            children[i] = nullptr; // Initialize all children to nullptr
        }
        flag = false; // Initialize flag to false
    }
    bool containsKey(int ch) {
        return children[ch] != nullptr; // Check if the child node exists
    }
    void puts(int ch, TrieNode *node) {
        children[ch] = node; // Create a link to the child node
    }
    TrieNode *getChar(int ch) {
        return children[ch]; // Get the reference to the child node
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
    
    void insert(vector<int>& num) {
        
        TrieNode *node = root; // Start from the root
        for(int i =num.size()-1;i>=0;i--) {
            int rem =num[i];
            if(!node->containsKey(rem)) { 
               node->puts(rem, new TrieNode()); // Create a new node if it doesn't exist
            }
            node = node->getChar(rem); // Move to the next node
        }
        node->setEnds(); // Mark the end of the word
    }
    
    int startsWith(vector<int>& num) {
        TrieNode *node = root; 
        int cnt =0;
        for(int i =num.size()-1;i>=0;i--) {
            int rem = num[i];
            if(node->containsKey(rem)) {
               node = node->getChar(rem); // Move to the next node
               cnt++;
            } else {
                return cnt; // Prefix not found
            }
        }
        return cnt; // Prefix found
    }
};
    vector<int> reverseDigits(int num){
        vector<int>digits;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        return digits;
    }
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie * ptr = new Trie();
        int ans =0;
        // insert
        for (const auto& x : arr1) {
            vector<int> num = reverseDigits(x);
            ptr->insert(num);
        }
        for (const auto& x : arr2) {
            vector<int> num = reverseDigits(x);
            ans = max(ans, ptr->startsWith(num));
        }

        return ans;
    }
};