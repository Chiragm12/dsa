#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Access front and back
    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back: " << q.back() << endl;    // 30

    // Dequeue
    q.pop();

    cout << "Front after pop: " << q.front() << endl;  // 20

    // Size and empty check
    cout << "Size: " << q.size() << endl;
    if (q.empty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }

    return 0;
}
// using arrays
#include <iostream>
using namespace std;

class Queue {
    int arr[100];     // Array to store elements
    int front, rear;  // Pointers to front and rear

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Enqueue (Insert)
    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }

    // Dequeue (Remove)
    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    // Get Front Element
    int peek() {
        if (front > rear) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front > rear;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl;  // 10

    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl;  // 20

    q.dequeue();
    q.dequeue();
    q.dequeue();  // Should show underflow

    return 0;
}
