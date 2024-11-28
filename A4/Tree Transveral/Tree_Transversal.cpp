/*
Nathan Boyden 
COP 3530
Assignment 4
11/28/24
*/

#include <iostream>
using namespace std;

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert into Binary Tree
void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value); // Create new node if root is null
        return;
    }
    if (value < root->val) {
        insert(root->left, value); // Insert into left subtree
    } else {
        insert(root->right, value); // Insert into right subtree
    }
}

// In-order Traversal (recursive)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Main Function
int main() {
    TreeNode* root = nullptr;

    // Insert values into the binary tree
    insert(root, 12);
    insert(root, 7);
    insert(root, 3);
    insert(root, 3);
    insert(root, 9);
    insert(root, 14);
    insert(root, 8);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    inorderTraversal(root);

    return 0;
}