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
    
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// --- Insertion (Recursive) ---
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

// --- Search ---
bool searchNode(TreeNode* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

// --- Deletion Helper: Find Minimum Value Node ---
TreeNode* findMinNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// --- Deletion (Recursive) ---
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            root->right = NULL; // Prevent destructor from deleting the subtree
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            root->left = NULL; // Prevent destructor from deleting the subtree
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        TreeNode* temp = findMinNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --- Traversals ---

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}


int main() {
    TreeNode* root = NULL;

    // Inserting
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder Traversal (Sorted): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Searching
    cout << "Searching for 40: ";
    if (searchNode(root, 40)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for 90: ";
    if (searchNode(root, 90)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    // Deleting
    cout << "Deleting 20 (Leaf)" << endl;
    root = deleteNode(root, 20);
    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Deleting 70 (2 Children)" << endl;
    root = deleteNode(root, 70);
    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "Deleting 50 (Root)" << endl;
    root = deleteNode(root, 50);
    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
