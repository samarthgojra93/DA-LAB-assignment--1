//You are given a 1D array that may contain both positive and negative integers, and find
//the sum of a contiguous subarray of numbers which has the largest sum. For example, if
//the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

long long maxSubarraySum(const vector<int>& arr) {
    // Initialize with the first element
    long long max_so_far = arr[0];
    long long current_max = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        // Decide: add to existing sum or start fresh?
        current_max = max((long long)arr[i], current_max + arr[i]);
        
        // Update the global maximum
        max_so_far = max(max_so_far, current_max);
    }

    return max_so_far;
}

int main() {
    // Example array from your prompt
    vector<int> nums = {-2, -5, 6, -2, -3, 1, 5, -6};

    cout << "Maximum Contiguous Sum is: " << maxSubarraySum(nums) << endl;

    return 0;
}