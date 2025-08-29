// u can use linear search and do or since searching in sorted array, we can do this, we can identify the sorted part of the array
// and then do binary search(the low and high ka thing)
#include <iostream>
#include <vector>
using namespace std;
int searchInRotatedSortedArray(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) return mid;

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Otherwise, right half is sorted
        else {
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}
