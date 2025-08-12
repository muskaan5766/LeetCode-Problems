class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;

        k = k % n; // handle k > n
        vector<int> temp(k);

        // Step 1: Copy last k elements to temp
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the first n-k elements to the right by k
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: Copy temp elements to the start
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};