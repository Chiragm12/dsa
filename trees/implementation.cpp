#include <vector>
#include <iostream>
// we create a dobly linked list node
// which will be used to create a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

int main(){
    struct Node* root=new Node(1); //basically this is the root node            1
    root->left=new Node(2);                                             //    2   3
    root->right=new Node(3);                                            
    root->left->right=new Node(4);
}