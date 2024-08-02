#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    //Creating constructor to initialise value
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next !=head){
        temp = temp->next;
    }

    node* delNode = head;
    temp->next = head->next;
    head= head->next;
    delete delNode;
}

void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count !=pos-1){
        temp = temp->next;
        count++;
    }
    node * todelete = temp->next;
    temp->next = todelete->next;
    delete todelete;
}

void insertAtHead(node* &head, int val){
    node *n = new node(val);
    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while(temp->next !=head){
         temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while(temp->next !=head){
           temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void displayLinkedList(node *head)
{
    node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

int main() {
    node* head = NULL;

    // Insert elements at the head
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    // Display the linked list
    cout << "Circular Linked List after inserting at head: ";
    displayLinkedList(head);

    // Insert elements at the tail
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    // Display the linked list
    cout << "Circular Linked List after inserting at tail: ";
    displayLinkedList(head);

    // Delete an element at position 2
    deletion(head, 2);

    // Display the linked list
    cout << "Circular Linked List after deleting at position 2: ";
    displayLinkedList(head);

    // Delete the head
    deleteAtHead(head);

    // Display the linked list
    cout << "Circular Linked List after deleting the head: ";
    displayLinkedList(head);

    return 0;
}
