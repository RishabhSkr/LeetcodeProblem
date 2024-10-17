class Solution {
public:
    int maximumSwap(int num) {
    string no = to_string(num);
    vector<int> last(10, -1); // To store the last occurrence of each digit

    // Store the last occurrence of each digit
    for (int i = 0; i < no.size(); ++i) {
        last[no[i] - '0'] = i;
    }

    // Traverse the number and check if a larger digit exists to the right
    for (int i = 0; i < no.size(); ++i) {
        for (int d = 9; d > no[i] - '0'; --d) {
            if (last[d] > i) {
                // Swap the current digit with the largest digit to its right
                swap(no[i], no[last[d]]);
                return stoi(no); // Return the modified number
            }
        }
    }

    return num; // If no swap was made, return the original number
}

};