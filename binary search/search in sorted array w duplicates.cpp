//we can not use the prev methord as now we have duplicates, so what we do is we will check first, the sorted part of the array 
// and update the minimum, then we'll go to the unsorted array and then find and update the min, in sorted part, the first ele
// will be the smallest ele as it will be sorted.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If the subarray is already sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            if (nums[low] <= nums[mid]) {
                // Left half is sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                // Right half is unsorted, move left
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
