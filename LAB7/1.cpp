// AU2140213 Vanaja Agarwal
// Q1. Implementation of Inorder, Preorder, and Postorder Traversal using stacks (*Iterative method*)

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

void iterativeInorder(Node *root)
{
    stack<Node *> Stack1;
    Node *curr = root;
    while (curr != NULL || Stack1.empty() == false)
    {
        while (curr != NULL)
        {
            Stack1.push(curr);
            curr = curr->left;
        }
        curr = Stack1.top();
        Stack1.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

void iterativePreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> Stack2;
    Node *curr = root;
    while (curr != NULL || Stack2.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right != NULL)
            {
                Stack2.push(curr->right);
            }
            curr = curr->left;
        }
        if (Stack2.empty() == false)
        {
            curr = Stack2.top();
            Stack2.pop();
        }
    }
}

void iterativePostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> Stack3;
    Stack3.push(root);

    stack<int> Output;

    while (Stack3.empty() == false)
    {
        Node *curr = Stack3.top();
        Stack3.pop();

        Output.push(curr->key);

        if (curr->left)
        {
            Stack3.push(curr->left);
        }

        if (curr->right)
        {
            Stack3.push(curr->right);
        }
    }
    while (Output.empty() == false)
    {
        cout << Output.top() << " ";
        Output.pop();
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << "INORDER TRAVERSAL" << endl;
    iterativeInorder(root);
    cout << "\nPREORDER TRAVERSAL" << endl;
    iterativePreorder(root);
    cout << "\nPOSTORDER TRAVERSAL" << endl;
    iterativePostorder(root);
    return 0;
}

// Output:
// INORDER TRAVERSAL
// 20 10 40 30 50
// PREORDER TRAVERSAL
// 10 20 30 40 50
// POSTORDER TRAVERSAL
// 20 40 50 30 10