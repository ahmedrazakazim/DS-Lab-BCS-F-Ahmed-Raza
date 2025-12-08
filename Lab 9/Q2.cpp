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

int computeBalance(TreeNode *n) { return fetchNodeLevel(n->left) - fetchNodeLevel(n->right); }

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
    int initialData[] = {50, 30, 70, 20, 40, 60, 80};
    int size = 7;
    
    for (int i = 0; i < size; i++)
        root = insertIntoTree(root, initialData[i]);


    root = insertIntoTree(root, 55); 
    
    cout << "Tree after inserting 55 (Inorder): ";
    inorderPrint(root);
    cout << endl;

    
    if (root != NULL && root->right != NULL) {
        root = rotateLeft(root);
        cout << "Tree after manual Left Rotation on root: ";
        inorderPrint(root);
        cout << endl;
    } else {
        cout << "Manual left rotation cannot be performed on the root." << endl;
    }

    delete root;

    return 0;
}
