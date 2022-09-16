// AU2140213 VANAJA AGARWAL LAB 4
// Q4.
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

struct Queue
{
	Node *front, *rear;
	Queue()
	{
		front = rear = NULL;
	}

	void enQueue(int x)
	{

		Node *temp = new Node(x);

		if (rear == NULL)
		{
			front = rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void deQueue()
	{

		if (front == NULL)
			return;

		Node *temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete (temp);
	}

	bool isEmpty()
	{
		return front == NULL;
	}
};

int main()
{

	Queue q;
	q.enQueue(23);
	q.enQueue(45);
	q.enQueue(78);
	q.enQueue(65);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}
