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

void delete_at_head(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
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

void delete_at_any_position(Node* &head , int pos){
    Node* temp = head;
    
    while(--pos){
        temp = temp->next;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
    
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

void sort_linked_list(Node* head){
    for(Node* i = head; i->next != nullptr; i = i->next){
        for(Node* j = i->next; j != nullptr; j = j->next){
            if(i->val < j->val){
                swap(i->val , j->val);
            }
        }
    }
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;
    insert_at_tail(head , tail , 20);
    insert_at_tail(head , tail , 10);
    insert_at_tail(head , tail , 5);
    insert_at_tail(head , tail , 50);

    cout << "Print Normal : " ;
    print_linked_list(head);

    sort_linked_list(head);    

    cout << "Print Normal : " ;
    print_linked_list(head);
    return 0;
}