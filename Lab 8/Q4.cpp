#include <iostream>
#include <algorithm>

using namespace std;

class AVL_Node
{
public:
    int data, level;
    AVL_Node *left;
    AVL_Node *right;

    AVL_Node(int d)
    {
        data = d;
        level = 1;
        left = right = NULL;
    }
};

int getNodeLevel(AVL_Node *n) { return n ? n->level : 0; }

AVL_Node *updateLevel(AVL_Node *n)
{
    n->level = 1 + max(getNodeLevel(n->left), getNodeLevel(n->right));
    return n;
}

AVL_Node *rightRotate(AVL_Node *y)
{
    AVL_Node *x = y->left;
    AVL_Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    updateLevel(y);
    updateLevel(x);

    return x;
}

AVL_Node *leftRotate(AVL_Node *x)
{
    AVL_Node *y = x->right;
    AVL_Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    updateLevel(x);
    updateLevel(y);

    return y;
}

int getBalanceFactor(AVL_Node *n) { return getNodeLevel(n->left) - getNodeLevel(n->right); }

AVL_Node *insertNode(AVL_Node *r, int data)
{
    if (!r)
        return new AVL_Node(data);

    if (data < r->data)
        r->left = insertNode(r->left, data);
    else if (data > r->data)
        r->right = insertNode(r->right, data);
    else
        return r;

    updateLevel(r);

    int balance = getBalanceFactor(r);

    if (balance > 1 && data < r->left->data)
        return rightRotate(r);
    if (balance < -1 && data > r->right->data)
        return leftRotate(r);

    if (balance > 1 && data > r->left->data)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    if (balance < -1 && data < r->right->data)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

AVL_Node *findKthSmallest(AVL_Node *root, int &k)
{
    if (!root)
        return NULL;

    AVL_Node *leftResult = findKthSmallest(root->left, k);
    if (leftResult)
        return leftResult;

    k--;
    if (k == 0)
        return root;

    return findKthSmallest(root->right, k);
}

AVL_Node *findKthLargest(AVL_Node *root, int &k)
{
    if (!root)
        return NULL;

    AVL_Node *rightResult = findKthLargest(root->right, k);
    if (rightResult)
        return rightResult;

    k--;
    if (k == 0)
        return root;

    return findKthLargest(root->left, k);
}

int main()
{
    AVL_Node *root = NULL;
    int array[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        root = insertNode(root, array[i]);

    int k1 = 3, k2 = 2;

    AVL_Node *smallest = findKthSmallest(root, k1);
    

    int k_temp = k2; 
    AVL_Node *largest = findKthLargest(root, k_temp);

    cout << "3rd Smallest: " << smallest->data << endl;
    cout << "2nd Largest: " << largest->data << endl;

    cout << "Left Height from Root: " << getNodeLevel(root->left) << endl;
    cout << "Right Height from Root: " << getNodeLevel(root->right) << endl;

    return 0;
}
