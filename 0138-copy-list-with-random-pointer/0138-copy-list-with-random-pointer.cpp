/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp = head;
        map<Node*,Node*>mp;
        while(temp!=NULL){
            Node * newNode = new Node(temp->val);
            mp[temp]= newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            Node * copyNode = mp[temp];
            copyNode->next = mp[temp->next];
            copyNode->random = mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};