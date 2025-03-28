class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0, i = 0;
    while (i < str1.size() && j < str2.size()) {
        if (str1[i] == str2[j]) {
            j++;
        } else {
            // Increment character cyclically
            char ch1 = (str1[i] - 'a' + 1) % 26 + 'a';

            if (ch1 == str2[j]) {
                j++;
            }
        }
        i++; 
    }
        
        
    if (j >= str2.size()) 
        return true;
        
    return false;
    }
};