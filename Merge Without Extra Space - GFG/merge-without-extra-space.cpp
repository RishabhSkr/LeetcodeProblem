//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // find min size arr
            int l = min(n,m);
            int j= n-1;
            
            // run loop for minim length array
            for(int i = 0 ; i<l;i++){
                // largest ele of arr1 is greater than 
                //smallest of ele of arr2 swap ele, 
                if(arr1[j]>arr2[i])swap(arr1[j--],arr2[i]);
                else break;
            }
            // sort the arrays again
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
   } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends