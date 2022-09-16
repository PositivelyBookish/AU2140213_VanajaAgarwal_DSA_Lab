// AU2140213 VANAJA AGARWAL LAB 4
// Q1.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
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

    void push(int val)
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

int main()
{
    MyStack s1;
    s1.push(22);
    s1.push(45);
    s1.push(78);
    s1.push(65);
    s1.push(21);
    s1.push(90);
    cout << s1.pop() << endl;
    s1.isEmpty();
    cout << s1.pop() << endl;
    cout << s1.peek() << endl;
    s1.display();
    return 0;
}