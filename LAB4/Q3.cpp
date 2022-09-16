// AU2140213 VANAJA AGARWAL LAB 4
// Q3.
// Using the program from Q1.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int size;
    MyStack()
    {
        head = NULL;
        size = 0;
    }

    void push(char val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty!"
                 << "\n";
            return INT_MAX;
        }

        int res = head->data;
        head = head->next;
        size--;
        return res;
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty!"
                 << "\n";
            return INT_MAX;
        }

        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void display()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            /* code */
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool isBalanced(string str)
{

    MyStack s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.isEmpty() == true)
                return false;
            else if (matching(s.peek(), str[i]) == false)
                return false;
            else
                s.pop();
        }
    }
    return (s.isEmpty() == true);
}

int main()
{
    string str = "{()}[]";

    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
