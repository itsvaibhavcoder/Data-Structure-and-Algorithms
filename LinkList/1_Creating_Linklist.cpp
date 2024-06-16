#include<bits/stdc++.h>
using namespace std;

// Creating user define data type (Structure)
struct Node{
    public:
    int data;
    Node* next;

    // Creating constructor
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int>arr = {2,5,8,7};
    //Creating object of node
    //Node y = Node(arr[1], nullptr);
    // cout<<y.data<<endl;
    // cout<<y.next<<endl;
    Node* y = new Node(arr[0], nullptr);
    cout<<y;
    //cout<<y->data<<endl;
}
