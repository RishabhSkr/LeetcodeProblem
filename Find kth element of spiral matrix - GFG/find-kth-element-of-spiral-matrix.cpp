//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		
 		int rowLower =0,rowUpper=n-1,colLower=0,colUpper=m-1,count =0;
 		while(count<m*n){
 		    
 		    for(int i=colLower; i<=colUpper;++i){
 		        count++;
 		        if(count == k)return a[rowLower][i];
 		    }
 		    rowLower++;
 		    
 		    for(int i=rowLower; i<=rowUpper;++i){
 		      
 		        count++;
 		        if(count == k)return a[i][colUpper];
 		    }
 		   
 		    colUpper--;
 		    for(int i=colUpper; i>=colLower;--i){
 		       
 		        count++;
 		        if(count == k)return a[rowUpper][i];
 		    }
 	
 		    rowUpper--;
 		    for(int i=rowUpper; i>=rowLower;--i){
 		    
 		        count++;
 		        if(count == k)return a[i][colLower];
 		    }
 		   
 		    colLower++;
 		}
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends