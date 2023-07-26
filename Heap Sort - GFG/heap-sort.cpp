//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
         int size =n;
        while(size > 1) { //?I forgot this condition to write thats why sorting is not done appropriately
            swap(arr[0],arr[size-1]);
            size--;
            int parentIndex = 0;
            int leftChildIndex = 2*parentIndex+1;
            int rightChildIndex = 2*parentIndex+2;
            while (leftChildIndex<size)
            {
                int largest = parentIndex;
                if(arr[leftChildIndex]>arr[largest])largest=leftChildIndex;
                if(rightChildIndex<size && arr[rightChildIndex]>arr[largest])largest=rightChildIndex;
                else if(largest==parentIndex) break;
                swap(arr[largest],arr[parentIndex]);
                parentIndex = largest;
                leftChildIndex=2*parentIndex+1;
                rightChildIndex=2*parentIndex+2;
            }
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for (int  i = 1; i < n; i++){
        int childIndex = i;
        while(childIndex>0){
         int parentIndex = (childIndex-1)/2;
            if(arr[childIndex]>arr[parentIndex]){
                swap(arr[childIndex],arr[parentIndex]);
                childIndex=parentIndex;
            }else break;
          }
        }
        heapify(arr,n,0);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends