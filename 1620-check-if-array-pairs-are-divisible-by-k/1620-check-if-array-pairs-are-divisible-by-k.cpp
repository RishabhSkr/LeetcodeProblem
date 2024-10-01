class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
      // sum => (arr[i]+arr[j])%k==0  n/2 pairs from arr 
      int n = arr.size();
      vector<int>freq(k,0);
      for(int i =0;i<n;++i){
        int rem = (arr[i]%k+k)%k;
        freq[rem]++;
      }
        for(int i =1;i<k;++i){
        if(freq[i]!=freq[k-i])return false;
      }
      return freq[0]%2==0;

    }
};
