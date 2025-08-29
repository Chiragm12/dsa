// here we should find the next greatest element so->
// [2,1,5,6,2,3]
//  5 5 6 -1 3 -1 should be your answer.
//we can do this using for loop but gives us O(n^2), which we cant do , so use monotomic stack
// we use decreasing monotomic stack
/*
so what we do is, we start from the end, so last ele will be -1, and push that ele to stack , next go to the last second ele,
and check like-> [3,1,2,4,6], push 6 to stack, next 4, 6>4 so push 4 to stack, and 6 will be the nge for 4, push 4 to stack
always compare the element in the array to the element on top of the stack, next 2, 4>2, push to stack and 4 is nge of 2,
similarly for 1,  byur for 3, 3>1, so pop 1, next 3>2 pop 2, 4>3, dont pop, 4 is the nge of 3, push 3 into stack.
asthe bro
*/
#include <iostream>
#include <queue>
using namespace std;
#include<vector>
#include<stack>
#include<map>
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();

            st.push(arr[i]);
        }

        return nge;
    }
};

//in leetcode they give 2 arrays, and instead of finiding the nge for all elements, only find for the ones in the first array
// so we use unordered maps, first we do the same as above, and then check the map for the numbers
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;  // monotonic decreasing stack

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

            // Maintain a decreasing stack
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // If stack is empty, no greater element exists
            nextGreater[num] = st.empty() ? -1 : st.top();

            // Push current number onto stack
            st.push(num);
        }

        // Build result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
/*
| Key | Value |
| --- | ----- |
| 2   | -1    |
| 4   | -1    |
| 3   | 4     |
| 1   | 3     |

*/