//to find the first and last occorence of a number repeated in a sorted array, ssee the small diff in lower and upper bound
#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperbound(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums, n, target);
        if (lb == n || nums[lb] != target) return {-1, -1};
        int ub = upperbound(nums, n, target);
        return {lb, ub - 1};  // subtract 1 to get last occurrence
    }
};
