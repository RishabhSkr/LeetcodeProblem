//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
          
            int pIdx = partition(arr, low, high);
            quickSort(arr,low,pIdx-1);
            quickSort(arr,pIdx+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pos=low,pivot=arr[low];
        //how is this working
        while(low<=high){
            while(low<=high && arr[low]<=pivot) low++;
            while(low<=high && arr[high]>pivot) high--;
            if(low<=high)
                swap(arr[low],arr[high]);
            if(low>high)break;
            
        }   
            swap(arr[high],arr[pos]);
            return high;
    }
    
    
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends