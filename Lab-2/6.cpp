//AU2140213 Vanaja Agarwal
//Q6.

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

//FUnction to print all the elements present in the Linked List
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

//Function to search for an element in a linked list 
int lsearch(Node * head, int element){
	int res = 1;
	Node *curr =  head;
	while (curr != NULL)
	{
		/* code */
		if ( (curr -> data) == element){
			return res;
		}

		else {
			res = res + 1;
			curr = curr -> next;
		}
	}
	return -1;
}

int main() 
{
	Node *head = new Node(23);
	head->next = new Node(34);
	head->next->next = new Node(45);
	print_ll(head);
	cout << "Position of element in Linked List: " << lsearch(head, 45);
	
	return 0;
}