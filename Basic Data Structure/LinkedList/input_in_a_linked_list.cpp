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
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head , tail , val);
    }
    


    print_linked_list(head);
    return 0;
}