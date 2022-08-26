//AU2140213 Vanaja Agarwal
//12.
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;

    node(int val)
    {
        this->data = val;
        next = NULL;
        prev = NULL;
    }
};

void dubbly_remove(node *dlinked_list, int element)
{
    node *temp = dlinked_list;

    while (temp != NULL)
    {
        if (temp->data == element)
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
            else
            {
                temp->prev->next = NULL;
            }
        }
        temp = temp->next;
    }
    free(temp);
    return;
}

void print_ll(node *head)
{

    node *point = head;
    while (point != NULL)
    {
        cout << point->data << "->";
        point = point->next;
    }
    cout << "NULL";
}

int main()
{

    node *head = new node(11);
    node *second = new node(22);
    node *third = new node(33);
    node *tail = new node(44);

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = tail;
    third->prev = second;

    tail->next = NULL;
    tail->prev = third;

    cout << "Initial doubly linked list: ";
    print_ll(head);
    cout << endl;
    int element = 22;
    
    if (head->data == element)
    {
        head->next->prev = NULL;
        cout << "Doubly linked list after deleting: ";
        print_ll(head->next);
    }
    else
    {
        dubbly_remove(head, element);
        cout << "Doubly linked list after deleting: ";
        print_ll(head);
    }

    return 0;
}