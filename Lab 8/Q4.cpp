#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};



TreeNode* insertNode(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }
    return root;
}


TreeNode* searchAndInsert(TreeNode* root, int key, bool& wasInserted) {
    if (root == NULL) {
        wasInserted = true;
        return new TreeNode(key);
    }
    
    if (key < root->data) {
        root->left = searchAndInsert(root->left, key, wasInserted);
    } else if (key > root->data) {
        root->right = searchAndInsert(root->right, key, wasInserted);
    } else {
        wasInserted = false;
    }
    
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);

    cout << "Initial Tree (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    int searchVal1 = 40;
    bool inserted1 = false;
    root = searchAndInsert(root, searchVal1, inserted1);
    
    cout << "--- Search 1: Value " << searchVal1 << " ---" << endl;
    if (inserted1) {
        cout << "Value " << searchVal1 << " did not exist. Inserted." << endl;
        cout << "New Tree: ";
        inorderTraversal(root);
        cout << endl;
    } else {
        cout << "Value " << searchVal1 << " already exists. Tree unchanged." << endl;
    }

    int searchVal2 = 65;
    bool inserted2 = false;
    root = searchAndInsert(root, searchVal2, inserted2);
    
    cout << "--- Search 2: Value " << searchVal2 << " ---" << endl;
    if (inserted2) {
        cout << "Value " << searchVal2 << " did not exist. Inserted." << endl;
        cout << "New Tree: ";
        inorderTraversal(root);
        cout << endl;
    } else {
        cout << "Value " << searchVal2 << " already exists. Tree unchanged." << endl;
    }

    return 0;
}
