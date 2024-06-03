class LFUCache {
    private:
        void updateFrequency(int key) {
            int freq = keyValue[key].second;
            freqList[freq].erase(keyIter[key]);
            if (freqList[freq].empty() && freq == minFreq) {
                minFreq++;
            }

            freqList[freq + 1].push_front(key);
            keyValue[key].second=freq+1;
            keyIter[key] = freqList[freq + 1].begin();
        }

        void evict() {
            int keyToEvict = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }
            keyValue.erase(keyToEvict);
            keyIter.erase(keyToEvict);
            size--;
        }
public:
    int capacity, size, minFreq;
    unordered_map<int, pair<int, int>> keyValue; // key -> {value, frequency}
    unordered_map<int, list<int>> freqList; // frequency -> list of keys
    unordered_map<int, list<int>::iterator> keyIter; // key -> list iterator

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) {
            return -1;
        }
        updateFrequency(key);
        return keyValue[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return; // Early return if capacity is 0

        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key].first = value;
            updateFrequency(key);
        } else {
            if (size == capacity) {
                evict();
            }
            keyValue[key] = {value, 1};
            freqList[1].push_front(key);
            keyIter[key] = freqList[1].begin();
            minFreq = 1;
            size++;
        }
    }

};
