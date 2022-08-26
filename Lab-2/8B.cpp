//AU2140213 Vanaja Agarwal
//8B.

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

//Function to delete the last element of Singly Linked List
Node *delatend(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if ((head -> next) == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while ((curr -> next -> next) != NULL)
    {
        curr = curr -> next;
    }
    delete (curr -> next);
    curr -> next = NULL;

    return head;
}


int main()
{
    Node *head = new Node(78);
    head -> next = new Node(63);
    head -> next -> next = new Node (89);
    print_ll(head);

    head = delatend(head);
    cout << "After deletion: ";
    print_ll(head);
}