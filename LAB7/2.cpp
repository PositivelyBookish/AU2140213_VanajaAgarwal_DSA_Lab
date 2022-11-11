// AU2140213 Vanaja Agarwal
// Q2. Breadth first search in a tree

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

void printLevel(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> Queue;

    Queue.push(root);

    while (Queue.empty() == false)
    {
        Node *curr = Queue.front();
        Queue.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
            Queue.push(curr->left);
        if (curr->right != NULL)
            Queue.push(curr->right);
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    cout << "Breadth First Search: \n"
         << endl;
    printLevel(root);
    return 0;
}

// Output:
// Breadth First Search:

// 10 20 30 40 50 60 70