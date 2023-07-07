//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
            if(maxi.empty() && mini.empty())maxi.push(x);
            else {
                if(x<maxi.top())maxi.push(x);
                else mini.push(x);
            }
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(int(mini.size()-maxi.size())>1){
            maxi.push(mini.top());
            mini.pop();
            
        }else if(int(maxi.size()-mini.size())>1){
            mini.push(maxi.top());
            maxi.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int c = mini.size() +maxi.size();
        if(c%2==0)
            return (mini.top() + maxi.top())/2 ;
        else{
            if(maxi.size()>mini.size()){
                return  maxi.top();
            }
            else return mini.top();
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends