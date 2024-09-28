class MyListNode{
    public:
        int data;
        MyListNode*next;
        MyListNode(int data){
            this->data = data;
            next = nullptr;
        }
};
class MyCircularDeque {
    MyListNode *dummy,*tail,*front;
    int size,capacity;
    public:
    MyCircularDeque(int k) {
        dummy = new MyListNode(-1); // Initialize dummy node
        tail = nullptr;
        front = dummy;
        size = 0;         // Initialize size to 0 (current number of elements)
        capacity = k;     // Set capacity
    }

    ~MyCircularDeque() {
        MyListNode* current = dummy;
        while (current != nullptr) {
            MyListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    bool insertFront(int value) {
        if(isFull())return false;

        MyListNode *newNode = new MyListNode(value);
        newNode->next = dummy->next;
        dummy->next = newNode;

        if(tail==nullptr)tail = newNode;
        front = newNode;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        
        if(isFull())return false; // check full

        MyListNode *newNode  = new MyListNode(value);
        if(tail ==nullptr){
            dummy->next = newNode;
            tail =newNode ;
            front = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;

        // handle for one node
        MyListNode *temp = dummy->next;
        dummy->next = temp->next;
        delete temp;

        if(dummy->next==nullptr){
            front = nullptr;
            tail=nullptr;
        }else{
            front = dummy->next;
        }
       
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;

       // handle one element
        if(dummy->next==tail){
            dummy->next= nullptr;
            tail=nullptr;
            front =nullptr;
        }else{
            MyListNode *ptr = dummy->next;
             // Find the node before tail
            while(ptr->next != tail){
                ptr = ptr->next;
            }
            delete tail;

            tail = ptr;
            tail->next= nullptr;
        }
        
        size--;
        return true;
        
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return front->data;
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return tail->data;
    }
    
    bool isEmpty() {

         return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */