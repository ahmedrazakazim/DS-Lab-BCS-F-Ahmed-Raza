#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode
{
public:
    int data, level;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        data = d;
        level = 1;
        left = right = NULL;
    }
    
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

int fetchNodeLevel(TreeNode *n) { return n ? n->level : 0; }
int computeBalance(TreeNode *n) { return n ? fetchNodeLevel(n->left) - fetchNodeLevel(n->right) : 0; }

TreeNode *adjustLevel(TreeNode *n)
{
    n->level = 1 + max(fetchNodeLevel(n->left), fetchNodeLevel(n->right));
    return n;
}

TreeNode *rotateRight(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    adjustLevel(y);
    adjustLevel(x);

    return x;
}

TreeNode *rotateLeft(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    adjustLevel(x);
    adjustLevel(y);

    return y;
}

TreeNode *insertIntoTree(TreeNode *root, int data)
{
    if (!root)
        return new TreeNode(data);

    if (data < root->data)
        root->left = insertIntoTree(root->left, data);
    else if (data > root->data)
        root->right = insertIntoTree(root->right, data);
    else
        return root;

    adjustLevel(root);

    int balance = computeBalance(root);

    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    if (balance > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

TreeNode *findKthSmallest(TreeNode *root, int &k)
{
    if (!root)
        return NULL;

    TreeNode *leftResult = findKthSmallest(root->left, k);
    if (leftResult)
        return leftResult;

    k--;
    if (k == 0)
        return root;

    return findKthSmallest(root->right, k);
}

TreeNode *findKthLargest(TreeNode *root, int &k)
{
    if (!root)
        return NULL;

    TreeNode *rightResult = findKthLargest(root->right, k);
    if (rightResult)
        return rightResult;

    k--;
    if (k == 0)
        return root;

    return findKthLargest(root->left, k);
}

void inorderPrint(TreeNode *r)
{
    if (!r)
        return;
    inorderPrint(r->left);
    cout << r->data << " ";
    inorderPrint(r->right);
}

int main()
{
    TreeNode *root = NULL;
    int dataArray[] = {40, 20, 60, 10, 30, 50, 70};
    int arraySize = 7;
    
    for (int i = 0; i < arraySize; i++)
        root = insertIntoTree(root, dataArray[i]);

  
    root = insertIntoTree(root, 55); 
    
    cout << "--- Tree Information ---" << endl;
    cout << "Tree Keys (Inorder): ";
    inorderPrint(root);
    cout << endl;
  
    int k_smallest = 3;
    int k_temp_small = k_smallest;
    TreeNode *smallest = findKthSmallest(root, k_temp_small);

    if (smallest) {
        cout << k_smallest << "rd Smallest Value: " << smallest->data << endl;
    } else {
        cout << "Could not find " << k_smallest << "th smallest value." << endl;
    }


    int k_largest = 2;
    int k_temp_large = k_largest;
    TreeNode *largest = findKthLargest(root, k_temp_large);

    if (largest) {
        cout << k_largest << "nd Largest Value: " << largest->data << endl;
    } else {
        cout << "Could not find " << k_largest << "th largest value." << endl;
    }


    cout << "Left Subtree Height from Root: " << fetchNodeLevel(root->left) << endl;
    cout << "Right Subtree Height from Root: " << fetchNodeLevel(root->right) << endl;

    delete root;

    return 0;
}
