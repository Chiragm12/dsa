#include <iostream>
#include <queue>
using namespace std;
#include<vector>
#include<stack>
#include<map>
/*
so here first go through the diagram, so basically if you see 3,1,2,4, first min is 3, then wen u have 3,1 then it'll be 1, then 
3,1,2, it'll be 1, so once u find the minimum value, it doesnt matter how many elements you add the minimum will always be 1
or take 4,3,2, first min will be 4, then 3, then 2, so it's like a decreasing value or queueu, hence monotomic stack.
*/

// Count of subarrays where arr[i] is min = (i - prevLess[i]) * (nextLess[i] - i)
// Contribution to total sum = arr[i] * count
// arr        = [3, 1, 2, 4]
// prevLess   = [-1, -1, 1, 2]
// nextLess   = [1,  4, 4, 4]
// Contribution per element: 3, 6, 4, 4 → Total = 17

int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> prevLess(n), nextLess(n);
    stack<int> s;

    // Previous Less Element
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i])
            s.pop();
        prevLess[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack to reuse
    while (!s.empty()) s.pop();

    // Next Less Element
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        nextLess[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate Result
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - prevLess[i];
        long long right = nextLess[i] - i;
        result = (result + arr[i] * left * right) % MOD;
    }

    return result;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of subarray minimums: " << sumSubarrayMins(arr) << endl;
    return 0;
}
