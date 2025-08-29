#include <iostream>
#include <queue>
using namespace std;
#include<vector>
#include<stack>
#include<map>

//find nse on the left side, not the right side
// before for nge, we started the iteration from the right side, now we do it from the left side


vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, -1);  // Result vector initialized to -1
    stack<int> st;           // Monotonic increasing stack

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }

        st.push(arr[i]);
    }

    return nse;
}
