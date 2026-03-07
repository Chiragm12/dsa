// to run the code g++ basics.cpp -o basics, and then ./basics
// here insteaf of using null like we do in c, we use nullptr ***********
// instead of free(), we do  delete toDelete;

// check selectoin sort ad merge sort codes for array and for linkedlists

#include <iostream>
using namespace std;

// Define a node of the linked list
struct Node {
    int data;      // data part
    Node* next;    // pointer to next node

    // Constructor
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to insert node at the end
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);  // create a new node
    if (head == nullptr) {
        head = newNode;  // first node in the list
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;  // move to the last node
    }
    temp->next = newNode;  // link new node at the end
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete a node with given value
void deleteNode(Node* &head, int val) {
    if (head == nullptr) return;  // empty list

    // if head node is to be deleted
    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found in list" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main() {
    Node* head = nullptr;  // start with an empty list

    // Insert elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Linked list after insertion:" << endl;
    printList(head);

    // Delete a node
    deleteNode(head, 20);
    cout << "Linked list after deleting 20:" << endl;
    printList(head);

    // Delete head
    deleteNode(head, 10);
    cout << "Linked list after deleting 10:" << endl;
    printList(head);

    return 0;
}



//************************************************imp*********************************************************** 
struct ListNode
{
    int val;            // stores the data in the node
    ListNode *next;     // pointer to the next node in the list

    // Constructor 1: for a node with just data (next defaults to NULL)
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }

    // Constructor 2: for a node with data and a given next pointer
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
// if they give like this above, then what you do is->
/*🔹 int val;
👉 This is the data part of the node.
👉 It holds the integer value stored in the node.

🔹 ListNode *next;
👉 This is the pointer part of the node.
👉 It points to the next node in the linked list.
👉 If this node is the last node, next will be NULL */
ListNode* node = new ListNode(5);
//✅ Creates a node with val = 5, next = NULL.

ListNode* node2 = new ListNode(10, node);//chumma wrote node so no errors, should actually be node1
//✅ Creates a node with val = 10, and next points to node1 

