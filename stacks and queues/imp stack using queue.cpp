/*
so we have push, pop,peek as main functions of stack , so to implement them by queue
firstly q is fifo, and stack is lifo, so pushing mai, if we do->

push(10), push(20), push(30)
then we will have [10,20,30]
now to pop, if we use queue it pops out 10, but we want to pop out 30, as stack is lifo
so we will have to do something like this, we will reverse the order of elements in queue
and then pop the first element, and will be correctly popped out

🧠 Example Walkthrough:
Let’s say we push 10, then 20, then 30 using this logic.

Push 10:

Queue = [10]

No rotation needed.

Push 20:

After push: Queue = [10, 20]

Rotation:

Move 10 to back → Queue = [20, 10]

Push 30:

After push: Queue = [20, 10, 30]

Rotation:

Move 20 to back → [10, 30, 20]

Move 10 to back → [30, 20, 10]

So now:

Front of queue = 30 → acts like top of a stack

Pop just does q.pop() → removes 30, the last pushed item*/
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    // Push element onto stack
    void push(int x) {
        q.push(x); //this adds elements from the end, not from front.
        int size = q.size();

        // Rotate the queue to move the new element to the front
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    // Pop element from stack
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    // Get the top element
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    // Check if stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;  // 30
    s.pop();
    cout << "Top after pop: " << s.top() << endl;  // 20

    return 0;
}
