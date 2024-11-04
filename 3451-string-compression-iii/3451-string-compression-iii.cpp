class Solution {
public:
    string compressedString(string word) {
        string comp ="";
        int i =0,j =0;
        while(j<word.length()){
            int cnt=0;
            while(word[i]==word[j] && cnt<9){
                j++;
                cnt++;
            }
            comp+=to_string(cnt)+word[i];
            i=j;
        }
        return comp;
    }
};