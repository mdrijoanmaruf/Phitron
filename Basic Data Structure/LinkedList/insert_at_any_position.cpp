#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node* &head , int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insert_at_any_position(Node* &head , int pos , int val){
    Node* newnode = new Node(val);
    Node* temp = head;
    
    while(--pos){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_at_tail(Node* head , int val){
    Node* newnode = new Node(val);

    if(head == nullptr){
        head = newnode;
        return;
    }
    Node* temp = head;
    
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newnode;
}

void print_linked_list(Node* head){

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next  = a;
    head->next->next = b;

    insert_at_any_position(head , 1 , 999);


    print_linked_list(head);
    return 0;
}