#include <iostream>
using namespace std;

class MyListNode {
public:
    pair<int, int> data;
    MyListNode *next;

    MyListNode(pair<int, int> data) {
        this->data = data;
        next = nullptr;
    }
};

class Node {
    MyListNode *dummy;

public:
    Node() {
        // Dummy node for easier management of the linked list
        dummy = new MyListNode({-1, -1});  // Use dummy with invalid event time
    }

    bool insert(MyListNode *newNode) {
        MyListNode *prev = dummy;
        MyListNode *curr = dummy->next;
        // check the node positon
        while(curr!=nullptr && curr->data.first<newNode->data.first){
            prev = curr;
            curr = curr->next;
        }
        //check if node is overlapping or not [3,8] newNode [9,14]  [15,30]
        if(prev!=dummy && prev->data.second >newNode->data.first ||
            curr!=nullptr && curr->data.first<newNode->data.second ){
                return false;
        }

        newNode->next = curr;
        prev->next = newNode;
        return true;
    }
};

class MyCalendar {
    Node *list;

public:
    MyCalendar() {
        list = new Node();
    }

    bool book(int start, int end) {
        return list->insert(new MyListNode({start, end}));
    }
};

