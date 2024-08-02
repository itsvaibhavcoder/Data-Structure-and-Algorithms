// head -- Store the address of first node
//  tail --> always has null to it next pointer
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Creating constructor to initialise value
    node(int val)
    {
        data = val;
        next = NULL;
    }
};


void insertAtTail(node *&head, int val)
{
    // If in linkedlist no node is present
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    // create the node with this val
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void displayLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// for deleting node we must point to node next before it
void deleteNode(node *head, int pos)
{
    if (head == NULL)
        return; // Empty list case

    // If the head to be deleted
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    node *current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    // If pos is out of bounds ( current is nullptr or current ->next is nullptr)
    // if (current == NULL || current->next == NULL)
    // {
    //     return;
    // }
    node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}
bool search(node *head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    //displayLinkedList(head);
    insertAtHead(head, 6);
    displayLinkedList(head);
    cout<<endl;
    //cout << search(head, 9) << endl;
    deleteNode(head, 2);
    displayLinkedList(head);
    return 0;
}
