// AU2140213 VANAJA AGARWAL LAB 4
// Q2.
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top = NULL;

node *createNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
}

void push(int data)
{
    node *ptr = createNode(data);
    if (top == NULL)
    {
        top = ptr;
        return;
    }
    ptr->next = top;
    top = ptr;
}

int pop()
{
    int data;
    struct node *temp;
    if (top == NULL)
        return -1;
    data = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return (data);
}

int main()
{
    string str = "54 8 4 / *";
    int i, data = -1, oper1, oper2, result;
    for (i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {

            if (data == -1)
            {
                data = 0;
            }
            else
            {
                data = data;
            }
            data = (data * 10) + (str[i] - 48);
            continue;
        }

        if (data != -1)
        {
            push(data);
        }

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {

            oper2 = pop();
            oper1 = pop();
            if (oper1 == -1 || oper2 == -1)
                break;
            switch (str[i])
            {
            case '+':
                result = oper1 + oper2;

                push(result);
                break;
            case '-':
                result = oper1 - oper2;
                push(result);
                break;
            case '*':
                result = oper1 * oper2;
                push(result);
                break;
            case '/':
                result = oper1 / oper2;
                push(result);
                break;
            }
        }
        data = -1;
    }
    if (top != NULL && top->next == NULL)
        cout << "Result: " << top->data << endl;
    else
        cout << "Wrong expression" << endl;
    return 0;
}