#include <iostream>
using namespace std;

// Doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    //constructor to initialize node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert at the end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at the beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Print list forward
void printForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Print list backward
void printBackward(Node* head) {
    if (head == nullptr) return;

    // Go to last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Traverse backward
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// Delete a node by value
void deleteNode(Node*& head, int val) {
    if (head == nullptr) return;

    Node* temp = head;

    // Find node with val
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    // If node is head
    if (temp == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
    } else {
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);

    cout << "List forward: ";
    printForward(head);

    cout << "List backward: ";
    printBackward(head);

    deleteNode(head, 20);

    cout << "After deleting 20, list forward: ";
    printForward(head);

    return 0;
}

//reversing a doubly linked list, now u must think that we should reverse, but if we just change the values, that also works 
 //we push all the values in a new stack and then pop them out, 

 
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL || head->next==NULL) return head;
        DLLNode* prev=NULL;
        DLLNode* current=head;
        while(current!=NULL){
            prev=current->prev;
            current->prev=current->next;
            current->next=prev;
            current=current->prev;
        }
        return prev->prev;
    }
};