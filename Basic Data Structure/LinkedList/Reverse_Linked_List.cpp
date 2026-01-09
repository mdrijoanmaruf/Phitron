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

void insert_at_tail(Node* head , Node* &tail, int val){
    Node* newnode = new Node(val);

    if(head == nullptr){
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = tail->next;
}

void print_linked_list(Node* head){

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse_linkedlist(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse_linkedlist(temp->next);
    cout << temp->val << " ";
}

void reverse_linkedlist(Node* &head , Node* &tail ,Node* temp){
    if(temp == NULL){
        return;
    }
    if(temp->next == NULL){
        head = temp;
        return;
    }
    reverse_linkedlist(head ,tail ,temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;
    insert_at_tail(head , tail , 20);
    insert_at_tail(head , tail , 30);
    insert_at_tail(head , tail , 40);
    insert_at_tail(head , tail , 50);


    reverse_linkedlist(head, tail, head);
    print_linked_list(head);
    return 0;
}