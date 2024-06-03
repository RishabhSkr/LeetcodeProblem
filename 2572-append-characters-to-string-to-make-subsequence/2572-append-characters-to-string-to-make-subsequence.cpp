class Solution {
public:
    int appendCharacters(string s, string t) {
        int i =0,j = 0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j])i++,j++;
            else i++;
            // cout<<i<<" "<<j<<endl;
        }
        return (t.length()-j);

    }
};