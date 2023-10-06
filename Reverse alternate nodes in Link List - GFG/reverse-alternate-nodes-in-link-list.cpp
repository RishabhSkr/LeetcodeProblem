//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    struct Node * reverseR(struct Node *head){
        if(head==NULL || head->next==NULL)return head;
        struct Node * newHead=reverseR(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
         if (odd == NULL || odd->next == NULL) return;
    
        struct Node * ptr1= odd;
        struct Node * ptr2 = odd ->next,*even;
        odd =ptr1;
        even = ptr2;
        while(ptr1 && ptr2){
            if(ptr1->next!=NULL){
                ptr1->next = ptr1->next->next;
            }
            if(ptr2->next!=NULL){
                ptr2->next = ptr2->next->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        even = reverseR(even);
        ptr1 = odd;
        while(ptr1->next){
            ptr1 =ptr1->next;
        }
        ptr1->next = even;
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends