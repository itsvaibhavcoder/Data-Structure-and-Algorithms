#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void deleteAtHead(node*& head) {
    if (head == NULL) return; // Check if the list is empty
    node* delNode = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete delNode;
}

void deleteNode(node*& head, int pos) {
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) return; // If the position is out of bounds

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void insertAtHead(node*& head, int val) {
    node* n = new node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

void InsertAtTail(node*& head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void displayLinkedList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Added a newline for better readability
}

int main() {
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    displayLinkedList(head);
    deleteNode(head, 2);
    displayLinkedList(head);
    InsertAtTail(head, 4);
    displayLinkedList(head);
    return 0;
}
