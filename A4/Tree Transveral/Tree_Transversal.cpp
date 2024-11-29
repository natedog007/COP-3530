/*
Nathan Boyden 
COP 3530
Assignment 4
11/28/24
*/

#include <iostream>
using namespace std;
#define MAX 10

// Binary Tree Node
struct TreeNode {
    // Node value
    int val;
    
    // Points to left and right children
    TreeNode* left;
    TreeNode* right;

    // Constructor aka setting default values 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Stack {
    TreeNode* stack[MAX];  
    int top;               
    Stack() : top(0) {}     

    // Push a TreeNode* onto the stack
    void push(TreeNode* node) {
        if (top < MAX) {
            stack[top++] = node;
        } else {
            cout << "\nStack Overflow" << endl;
        }
    }

    // Pop a TreeNode* from the stack
    TreeNode* pop() {
        if (top > 0) {
            return stack[--top];
        } else {
            cout << "\nStack Underflow" << endl;
            return nullptr;
        }
    }

    // Return the top element without removing it
    TreeNode* peek() {
        if (top > 0) {
            return stack[top - 1];
        }
        return nullptr;
    }

    // Checks if the stack is empty
    bool isEmpty() {
        return top == 0;
    }
};

void inorderTraversal(TreeNode* root);
void insert(TreeNode*& root, int value);

int main() {
    TreeNode* root = nullptr; // Start with an empty tree

    // Insert values into the tree
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    inorderTraversal(root);

    return 0;
}

// Insert into Binary Tree
void insert(TreeNode*& root, int value) {
    // If root is empty create a new one
    if (root == nullptr) {
        root = new TreeNode(value); 
        return;
    }
    // If value is less than the root value place child to the left
    if (value < root->val) {
        insert(root->left, value); 
    } 
    // If value is greater than the root value place child to the right
    else {
        insert(root->right, value); 
    }
}



void inorderTraversal(TreeNode* root) {
    Stack nodeStack;
    TreeNode* current = root;

    while (current != nullptr || !nodeStack.isEmpty()) {
        // Reach the leftmost node and push all nodes along the way onto the stack
        while (current != nullptr) {
            // Push the current node onto the stack
            nodeStack.push(current);  
            // Move to the left child
            current = current->left;  
        }
        // Process the top node from the stack
        current = nodeStack.pop();  
        cout << current->val << " ";
        // Pop the top node
        current = current->right;
    }
}
