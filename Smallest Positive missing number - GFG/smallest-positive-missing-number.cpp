//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    // //Function to find the smallest positive number missing from the array.
    // // Approach1: Using hashmap
    // // T.C O(n), S.C = O(n)
    
    // // Better Approach2 : O(n) O(1)
    // int missingNumber(int arr[], int n) 
    // { 
    //     unordered_map<int,bool>mp;
    //     for(int i =0 ; i<n ; ++i){
    //         mp[arr[i]]=true;
    //     }
    //     int num =1 ;
    //     while(true){
    //         if(mp.find(num)==mp.end())return num;
    //         ++num;
    //     }
    // } 
    
    // Approach 2:

// If we notice the numbers are from 0 onwards, 
// so if we somehow place the number at its correct position based on the index, 
// we are pretty much done with our solution, 
// we will again traverse the array and the first index we encounter not having the corresponding positive interger, we have got the answer and we will return it, in case no such number we have got, 
// then the required number is one greater than size.
// Time Complexity: O(n) -->since we are using two different for loops only
// Space Complexity: O(1) -->isnce we are performing only swaping and just one two variable.
    int missingNumber(int arr[], int n) 
    { 
       for(int i =0 ;i<n; ++i){
           int specifiedPos = arr[i]-1;
           if(specifiedPos>=0 && specifiedPos<n){
               if(arr[i]!=arr[specifiedPos]){
                   swap(arr[i],arr[specifiedPos]);
                   i--;
               }
           }
       }
       for(int i = 0 ; i< n ; i++){
           if(arr[i]!=i+1)return i+1;
       }
       return n+1;
       
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends