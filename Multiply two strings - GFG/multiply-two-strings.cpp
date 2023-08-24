//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
   string multiplyStrings(string s1, string s2) {
      if (s1 == "0" || s2 == "0") {
        return "0";
    }
       bool isNegative =false;
      
     if (s1[0] == '-') {
        isNegative = !isNegative;
        s1 = s1.substr(1);
    }

    if (s2[0] == '-') {
        isNegative = !isNegative;
        s2 = s2.substr(1);
    }
   
    
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> ans(len1 + len2, 0);
    
    for (int i = len1 - 1; i >= 0; --i) {
        int c1 = s1[i] - '0'; // Use i to access characters in s1
        for (int j = len2 - 1; j >= 0; --j) {
            int c2 = s2[j] - '0'; // Use j to access characters in s2
            int pdt = c1 * c2; 
            int sum = pdt + ans[i + j + 1]; // add pdt to the unit digit
            ans[i + j + 1] = sum % 10; // store unit digit in ans
            ans[i + j] += sum / 10; // add carry to the prev ans
        }
    }
    
    string finalres = "";
    bool leadingZero = true;
    for (int digit : ans) {
        if (leadingZero && digit == 0) continue;
        leadingZero = false;
        finalres += to_string(digit);
    }
    
     if (isNegative) {
        finalres = "-" + finalres;
    }
    
    return finalres;
}


};



//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends