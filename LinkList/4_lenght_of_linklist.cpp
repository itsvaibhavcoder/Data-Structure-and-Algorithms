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

int lengthOfLL(Node *head){
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
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
    int len = lengthOfLL(head);
    cout<<len<<endl;
}