// AU2140213 VANAJA AGARWAL LAB 4
// Q6.
#include <iostream>
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

Node *front = NULL;
Node *rear = NULL;

bool isEmpty()
{
    if (front == NULL and rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAtFront(int val)
{
    Node *temp = new Node(val);

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->next = front;
        front = temp;
    }
}

void enqueueAtRear(int x)
{
    Node *temp = new Node(x);

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeueAtFront()
{
    if (isEmpty())
        cout << "Queue is empty!" << endl;
    else

        if (front == rear)
    {
        delete (front);
        front = rear = NULL;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete (temp);
    }
}

void dequeueAtRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        if (front == rear)
        {
            delete (front);
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            while (temp->next->next != NULL)
            { // accessing the second last element
                temp = temp->next;
            }
            temp->next = NULL;
            rear = temp;
        }
    }
}
void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void getFront()
{
    if (isEmpty())
        cout << "Queue is empty!\n";
    else
        cout << "Queue -> Front: " << front->data << endl;
}

void getRear()
{
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue -> rear: " << rear->data << endl;
}

int main()
{

    enqueueAtFront(13);
    enqueueAtFront(44);
    enqueueAtFront(76);

    enqueueAtRear(81);
    enqueueAtRear(99);
    isEmpty();
    dequeueAtFront();
    dequeueAtRear();
    display();
    getFront();
    getRear();

    return 0;
}