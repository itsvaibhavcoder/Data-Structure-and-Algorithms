#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = nullptr;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

bool searchInLL(Node *head, int target){
    Node* temp = head;
    while(temp){
        if(temp->data== target) return true;
        temp = temp->next;
    }
    return false;
}

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

int main(){
    vector<int>arr = {2,5,8,7};
    Node *head = convertArr2LL(arr);
    bool found = searchInLL(head,8);

    if(found) cout<<"Element is present"<<endl;
    else cout<<"Element is not present"<<endl;
}
