//AU2140213 Vanaja Agarwal
//Q11.

#include <bits/stdc++.h>
using namespace std;

//Defining a Structure for Linked List
struct Node
{
	/* data */
	int data;
    Node* prev;
	Node* next;
	Node (int x){
		data = x;
        prev = NULL;
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

//function dubbly_append(dlinked_list,element) to append an element into the doubly linked list.
Node *dubbly_append(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }

    Node *curr = head;
    while (curr -> next != NULL)
    {
        /* code */
        curr  = curr -> next;
    }

    curr -> next = temp;
    temp -> prev = curr;
    
    return head;
}

int main()
{
    Node *head=new Node(34);
	Node *temp1=new Node(45);
	Node *temp2=new Node(56);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;

    head = dubbly_append(head, 86);
    print_ll(head);

    return 0;
}