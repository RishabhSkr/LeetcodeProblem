class NumberContainers {
public:
    unordered_map<int,int>mp1;// idx=>no.
    unordered_map<int,set<int>>mp2;// number=>{idx}

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       // If the index already has a number, remove it from mp2
        if (mp1.count(index)) {
            int oldNumber = mp1[index];
            mp2[oldNumber].erase(index); // Remove the index from the old number's set
            if (mp2[oldNumber].empty()) {
                mp2.erase(oldNumber); // Clean up if the set is empty
            }
        }

        // Update mp1 and mp2 with the new number
        mp1[index] = number;
        mp2[number].insert(index);
    }
    
    int find(int number) {
        if (mp2.count(number)) {
            auto& st = mp2[number]; // Get the set of indices for the number
            if (!st.empty()) {
                return *st.begin(); // The smallest index is the first element in the set
            }
        }
        return -1; // Return -1 if the number doesn't exist or has no indices
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */