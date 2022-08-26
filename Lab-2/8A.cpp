//AU2140213 Vanaja Agarwal
//8A.

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

//Function to insert an element at the beginning of Singly Linked List
Node *linsatbeg(Node *head, int x){
    Node *temp = new Node(x);
    temp -> next = head;
    return temp;
}

int main()
{
    Node *head = NULL;
    head = linsatbeg(head, 21);
    head = linsatbeg(head, 56);
    head = linsatbeg(head, 93);
    head = linsatbeg(head, 111);
    print_ll(head);

    return 0;
}