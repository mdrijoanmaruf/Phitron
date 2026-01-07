#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_linked_list_forword(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_linked_list_backword(Node* tail){
    Node* temp = tail;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insert_at_head(Node* &head , int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;

    head = newNode;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    insert_at_head(head , 999);
    insert_at_head(head , 99);
    insert_at_head(head , 9);

    print_linked_list_forword(head);
    print_linked_list_backword(tail);

    return 0;
}