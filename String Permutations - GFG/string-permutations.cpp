//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function

    void help(int start,string &s,vector<string>&ans){
        if(start == s.size()){
            ans.push_back(s);
            return;
        }
        
   
        for(int i = start; i<s.size();++i){
           swap(s[start],s[i]);
            help(start+1,s,ans);
            swap(s[start],s[i]);
           
        }
        
        
    }
    vector<string> permutation(string S)
    {
        vector<string>ans;
        help(0,S,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends