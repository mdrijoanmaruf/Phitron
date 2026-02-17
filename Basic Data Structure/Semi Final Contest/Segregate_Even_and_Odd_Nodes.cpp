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

void insert_at_tail(Node* &head , Node* &tail , long long val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printForword(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int n;
    cin >> n;
    while(n--){
        long long x;
        cin >> x;

        if(x % 2 == 0){
            insert_at_tail(head1 , tail1 , x);
        } else {
            insert_at_tail(head2, tail2 , x);
        }
    }

    if(head1 == NULL){
        printForword(head2);
        return 0;
    }

    if(head2 == NULL){
        printForword(head1);
        return 0;
    }

    tail1->next = head2;
    head2->prev = tail1;

    printForword(head1);
    return 0;
}