//AU2140213 Vanaja Agarwal
//Q10.

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

//Function to replace an element in the linked_list at the specified position.
Node *replatind(Node * head, int pos, int element){
	int res = 1;
	Node *curr =  head;
	while (curr != NULL)
	{
		/* code */
		if (pos == res){
			(curr -> data) = element;
            return head;
		}

		else {
			res = res + 1;
			curr = curr -> next;
		}
	}
    return NULL;
}

int main() 
{
	Node *head = new Node(23);
	head->next = new Node(34);
	head->next->next = new Node(45);
    cout << "Lined List before Replacement: ";
	print_ll(head);
    cout << endl;
    cout << "Linked List after Replacement: ";
    replatind(head, 1, 11);
    print_ll(head);
	
	return 0;
}