/*
here we use 2 stacks, we push the ele in one stack, then pop them to another stack, then insert new ele in the empty stack,
then push the elements to the single ele stack and then pop it all out to the other stack->
[4] [], [] [4]. [2] [4], [2,4] [], [] [4,2], [3] [4,2], [3,2,4][]

so in the last u see it'll be like that so if they ask for the top element(q.front()) if we do q.top() it'll give the correct ans
*/

/* the code bellow is optimised one, check his vid ull understand, basically instead of pusing to other stack all the time, 
only push when u encounter a pop, then push all to other sdtack and pop, if we get a push, push it to the first stack which is 
empty only, and then continue the operations.
*/

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;   // Used to push new elements
    stack<int> outStack;  // Used to pop or peek oldest elements

    // Move elements from inStack to outStack
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
        // constructor
    }

    // Push element to back of queue
    void push(int x) {
        inStack.push(x);
    }

    // Removes element from front of queue
    int pop() {
        shiftStacks();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    // Get front element
    int peek() {
        shiftStacks();
        return outStack.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
