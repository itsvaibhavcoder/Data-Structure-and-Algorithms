#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    
    // Constructor
    public:
    Node(int data1, Node* ptr){
        data = data1;
        next = ptr;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 1) Deletion at head
// 12-->4-->5-->1-->nullptr
// Delete head
// 4-->5-->1-->nullptr

Node * deleteHead(Node* head){
    if(head==NULL) return head;
    Node *temp = head; 
    head = head->next;
    delete temp;
    return head;
}

// 2) Deletion at tail
// 12-->4-->5-->1-->nullptr
// delete tail 
// 12-->4-->5-->nullptr

Node * deleteTail(Node *head){
    // If the list is empty, return nullptr
    if(head== nullptr) return nullptr;
    // If there's only one element in the list
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node* current = head;
    while(current->next->next !=nullptr){
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

// Deleting kth node
Node * deleteKthNode(Node * head, int k){
    if(head==nullptr) return nullptr; // Empty list case

    //If the head to be deleted
    if(k==1){
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
    }

    Node *current = head;
    for(int i=1; i<k-1 && current!=nullptr; i++){
        current = current->next;
    }

    //If k is out of bounds ( current is nullptr or current ->next is nullptr)

    if(current ==nullptr || current->next ==nullptr){
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

// Deleting given value node from linklist

Node* deleteNodeWithValue(Node* head, int value){
    if(head== nullptr) return nullptr;

    if(head->data == value){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while(current->next != nullptr && current->next->data != value){
        current = current->next;
    }

    // If the value was not found in the list

    if(current->next == nullptr){
        return head;
    }
    // Delete the node with the given value

    Node * temp = current->next;
    current->next = current->next->next;

    delete temp;
    return head;
}


int main(){
    vector<int> arr = {12,4,5,1};
    Node* head = convertArr2LL(arr);
    //Node *temp = head;
    Node* newHead = deleteNodeWithValue(head,4);
    
    Node * temp = newHead;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

