#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> s;  // {value, current_min}

public:
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int current_min = min(val, s.top().second);
            s.push({val, current_min});
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return -1;  // Or throw an exception
    }

    int get_min() {
        if (!s.empty()) {
            return s.top().second;
        }
        return -1;  // Or throw an exception
    }

    bool empty() {
        return s.empty();
    }
};
