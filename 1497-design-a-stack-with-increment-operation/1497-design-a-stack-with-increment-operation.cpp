class CustomStack {
public:
    vector<int>st;
    int capacity,size =0;
    CustomStack(int maxSize) {
        capacity = maxSize;
        st.resize(capacity,-1);
    }
    
    void push(int x) {
        if(size==capacity)return;
        st[size++]=x;
    }
    
    int pop() {
       if(size>0)return st[--size];
       return -1;
    }
    
    void increment(int k, int val) {
        for(int i =0;i<min(k,size);++i){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */