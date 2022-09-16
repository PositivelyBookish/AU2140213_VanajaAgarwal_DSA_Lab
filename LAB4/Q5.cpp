// AU2140213 VANAJA AGARWAL LAB 4
// Q5.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
};

Node *front = NULL;

void enQueue(int data, int priority)
{

    Node *temp, *curr, *prev = NULL;

    temp = new Node;
    temp->data = data;
    temp->priority = priority;

    if (front == NULL or priority < front->priority)
    {
        temp->next = front;
        front = temp;
    }

    else
    {
        curr = front;

        while (curr and priority >= curr->priority)
        {
            prev = curr;
            curr = curr->next;
        }

        temp->next = prev->next;
        prev->next = temp;
    }
}

void deQueue()
{
    if (front == NULL)
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    else
    {
        Node *temp;
        temp = front;

        cout << "deQueued item is " << temp->data << endl;

        front = temp->next;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
        cout << "Priority-Queue is empty" << endl;

    Node *curr = front;

    cout << "\nPriority-Queue elements are : ";

    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;

    return;
}

void peek()
{
    cout << "Peek element is :" << front->data << endl;
}

int main()
{
    enQueue(22, 9);
    enQueue(33, 4);
    enQueue(61, 5);
    enQueue(52, 8);

    display();

    peek();

    deQueue();
    deQueue();
    display();

    return 0;
}