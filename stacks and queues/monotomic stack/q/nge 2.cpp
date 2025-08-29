/*
here its like a circular queue, like [3,13,12] here the nge for 12 will be 13, as u can wrap around and also check for nge.
*/

// we assume the array to be 2x the size, matlab [1,2,3,4] we'll make it [1,2,3,4,1,2,3,4] and then push and pop everything in the 
// stack until we reach the original array, and then do everythig normally.

#include <iostream>
#include <queue>
using namespace std;
#include<vector>
#include<stack>
#include<map>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  // Initialize result with -1
        stack<int> st; // store indices

        for (int i = 2 * n - 1; i >= 0; --i) {
            int idx = i % n;
            //[1,2,1] we make it as [1,2,1,1,2,1] and then do
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    nge[idx] = nums[st.top()];
                }
            }

            st.push(idx);
        }

        return nge;
    }
};
