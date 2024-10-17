class Solution {
public:
    int maximumSwap(int num) {
        string no = to_string(num);
        string maxi = no;
        for(int i =0;i<no.size();++i){
            for(int j = i+1;j<no.size();++j){
                swap(no[i],no[j]);
                maxi = max(maxi,no);
                swap(no[i],no[j]);
            }
        }
        return stoi(maxi);
    }
};