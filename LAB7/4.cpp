// AU2140213 Vanaja Agarwal
// Q4. Implement insert, remove and find minimum value methods in A Binary Search Tree (BST).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        key = value;
        left = right = NULL;
    }
};

// INSERTION
Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }
    if (parent == NULL)
    {
        return temp;
    }
    if (parent->key > x)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }
    return root;
}

// DELETION
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *delNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->key > x)
    {
        root->left = delNode(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = delNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }
    }
    return root;
}

// MINIMUM VALUE
int minValue(Node *root)
{

    if (root == NULL)
        return -1;

    if (root->left == NULL)
        return root->key;

    minValue(root->left);
}

void iterativeInorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    cout << "Original BST: " << endl;
    iterativeInorder(root);
    int x = 20;
    cout << "\n\nInserting 20 in the BST." << endl;
    root = insert(root, x);
    iterativeInorder(root);
    cout << "\n\nDeleting 15 from BST." << endl;
    int y = 15;
    root = delNode(root, y);
    iterativeInorder(root);
    int res = minValue(root);
    cout << "\n\nMinimum Value in BST: " << res << endl;
    return 0;
}

// Output:
//  Original BST:
//  5 10 12 15 18

// Inserting 20 in the BST.
// 5 10 12 15 18 20

// Deleting 15 from BST.
// 5 10 12 18 20

// Minimum Value in BST: 5