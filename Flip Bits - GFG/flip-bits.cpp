//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        // kadan
        int i =0,cnt = 0,flip=0;
        while(i<n){
            if(a[i]==0){
                cnt++;
            }
            else cnt--;
            flip=max(flip,cnt);
            if(cnt<0)cnt=0;
            i++;
        }
        for(int i= 0 ; i<n; ++i){
            if(a[i]==1)flip++;
        }
        return flip;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends