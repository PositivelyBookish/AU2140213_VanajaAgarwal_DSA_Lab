//AU2140213 Vanaja Agarwal
//Q7.

#include <bits/stdc++.h>
using namespace std;

//Defining a Structure for Linked List
struct Node
{
	/* data */
	int data;
	Node* next;
	Node (int x){
		data = x;
		next = NULL;
	}
};

//Function to print all the elements present in the Linked List
void print_ll(Node *head){
	Node *curr = head;
	while (curr != NULL)
	{
		/* code */
		cout << curr -> data << " ";
		curr = curr -> next;
	}
	cout << "\n";
	
}

//Function to insert an element at the end of Singly Linked List
Node *linsatend (Node *head, int x)
{
	Node *temp = new Node (x);
	if (head == NULL){
		return temp;
	}
	Node *curr = head;
	while (curr -> next != NULL){
		curr = curr -> next;
	}
	curr -> next = temp;
	return head;
}


int main() 
{
	Node *head = new Node(23);
	head->next = new Node(34);
	head->next->next = new Node(45);
	head = linsatend(head, 22);
	head = linsatend(head, 33);
	head = linsatend(head, 44);
	head = linsatend(head, 55);
	print_ll(head);
	
	return 0;
}