//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > arr, int n)
    {
        // code here 
        int count =0;
        vector<int>rowSum(n);
        vector<int>colSum(n);
        for(int i =0 ;i<n ;++i){
            
            for(int j =0 ;j<n;++j){
                rowSum[i]+=arr[i][j];
                colSum[j]+=arr[i][j];
            }
           
        }
       
            int rowMax = *max_element(rowSum.begin(),rowSum.end());
         
            int colMax = *max_element(colSum.begin(),colSum.end());
            
            int maxSum = max(rowMax,colMax);
            
            for(int i  =0 ;i<n;++i){
               for(int j = 0 ;j<n;++j){
                  
                   int diff =  min(maxSum-rowSum[i],maxSum-colSum[j]);
                        arr[i][j]+=diff;
                        rowSum[i]+=diff;
                        colSum[j]+=diff;
                        count+=diff;
                   
               } 
            }
            
            return count;
            
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends