class Solution {
public:
    int jump(vector<int>& nums) {
       // O(N) solution https://youtu.be/vBdo7wtwlXs
        int n = nums.size();
        if (n <= 1) return 0;  // If the array has 1 or fewer elements, no jumps are needed
        int ladder = nums[0];  // Keep track of the furthest reachable index
        int stairs = nums[0];  // Keep track of steps we can still take within the current jump
        int jump = 1;  // At least one jump is needed (since n > 1)

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jump;  // If we've reached the end, return the jump count
            if (i + nums[i] > ladder) {
                ladder = i + nums[i];  // Update the furthest reachable index
            }
            stairs--;  // Move one step forward in the current jump
            if (stairs == 0) {  // If no more steps can be taken in the current jump
                jump++;  // Increment the jump count
                stairs = ladder - i;  // Calculate the new set of stairs for the next jump
            }
        }
        return jump;
    }
};