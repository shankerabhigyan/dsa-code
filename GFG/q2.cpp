#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000000007;

    void countSubarrays(int start, int end, int max_elem, vector<int>& arr, int k, int& count) {
        if (end >= arr.size()) return; // Stop if end exceeds the array bounds

        // Update the maximum element for the current subarray
        max_elem = max(max_elem, arr[end]);

        // Check if the current subarray ending at 'end' is valid
        if ((abs(max_elem - (arr[start] + arr[end])) % k) == 0) {
            count = (count + 1) % mod; // Valid subarray found
        }

        // Option 1: Continue with the current subarray
        countSubarrays(start, end + 1, max_elem, arr, k, count);

        // Start a new subarray from the next element, if 'end' is not the last element
        if (end + 1 < arr.size()) {
            countSubarrays(end + 1, end + 1, arr[end + 1], arr, k, count);
        }
    }

    int specialSubarrays(int n, vector<int>& arr, int k) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            countSubarrays(i, i, arr[i], arr, k, count); // Start a new subarray from each element
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 7, 2, 4};
    cout << "Number of special subarrays: " << sol.specialSubarrays(4, arr, 2) << endl;
    return 0;
}
