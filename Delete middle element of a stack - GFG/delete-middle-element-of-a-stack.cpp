//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        
       stack<int>st;
        int mid =sizeOfStack/2+1;
        
        if(s.size()%2==0){
              
              while(s.size()>=mid){
                st.push(s.top());
                s.pop();
            }
        }
     else{
         mid+=1;
        while(s.size()>=mid){
            st.push(s.top());
            s.pop();
        }
     }
       
       s.pop();
       while(!st.empty()){
           s.push(st.top());
           st.pop();
       }
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends