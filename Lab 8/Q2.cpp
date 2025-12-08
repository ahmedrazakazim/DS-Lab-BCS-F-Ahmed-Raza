#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode
{
public:
    int value, height;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int k)
    {
        value = k;
        height = 1;
        left = right = NULL;
    }
};

int getNodeHeight(TreeNode *n)
{
    return n ? n->height : 0;
}

int calculateBalanceFactor(TreeNode *n)
{
    return n ? getNodeHeight(n->left) - getNodeHeight(n->right) : 0;
}

TreeNode *updateHeight(TreeNode *n)
{
    n->height = 1 + max(getNodeHeight(n->left), getNodeHeight(n->right));
    return n;
}

TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode *leftRotate(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode *insertIntoAVL(TreeNode *root, int value)
{
    if (!root)
        return new TreeNode(value);

    if (value < root->value)
        root->left = insertIntoAVL(root->left, value);
    else if (value > root->value)
        root->right = insertIntoAVL(root->right, value);
    else
        return root;

    updateHeight(root);

    int balance = calculateBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && value < root->left->value)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && value > root->right->value)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *avlRoot = NULL;

    int data[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        avlRoot = insertIntoAVL(avlRoot, data[i]);
    

    avlRoot = insertIntoAVL(avlRoot, 55); 
    
    cout << "AVL Tree after insertions (Inorder): ";
    inorderTraversal(avlRoot);
    cout << endl;

    return 0;
}
