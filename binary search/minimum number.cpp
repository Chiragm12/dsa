// if they ask to find minimum number of anything, first start from the minimum, and keep trying upwards, so make a function to 
// check if it is possible for each number, the number will usually be less than 10 from 1-10., or just do binary search

#include <iostream>
#include <vector>
using namespace std;
// Helper function
bool canweplace(vector<int> &stalls, int dist, int cows) {
    int cntcows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            cntcows++;
            last = stalls[i];
        }
        if (cntcows >= cows) return true;
    }
    return false;
}

class Solution {
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1, high = stalls[n - 1] - stalls[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canweplace(stalls, mid, k)) {
                ans = mid;       // store the feasible distance
                low = mid + 1;   // try for a bigger minimum distance
            } else {
                high = mid - 1;  // try for a smaller distance
            }
        }

        return ans;
    }
};
