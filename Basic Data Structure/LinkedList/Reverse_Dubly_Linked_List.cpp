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

void insert_at_head(Node* &head ,Node* &tail, int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;

    head = newNode;
}

void insert_at_tail(Node* &head ,Node* &tail , int val){
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

void insert_at_any_postion(Node* &head , Node* &tail , int index , int val){
    // treat non-positive index as insert-at-head
    if(index <= 0){
        insert_at_head(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);

    // if linked list empty, just set head/tail
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = head;
    int i = 0;
    while(i < index-1 && temp->next != NULL){
        temp = temp->next;
        i++;
    }

    // if we're at the tail, append
    if(temp->next == NULL){
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    // insert between temp and temp->next
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void delete_at_head(Node* &head, Node* &tail){
    Node* deleteNode = head;
    if(deleteNode->next == NULL){
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }
    deleteNode->next->prev = NULL;
    head = deleteNode->next;

    delete deleteNode;
}

void delete_at_tail(Node* &head , Node* &tail){
    Node* deleteNode = tail;
    if(tail->prev == NULL){
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }

    deleteNode->prev->next = NULL;
    tail = deleteNode->prev;
    delete deleteNode;
}

void delete_at_any_postion(Node* &head , Node* &tail, int postion){
    Node* temp = head;
    
    while(--postion && temp->next != NULL){
        temp = temp->next;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;
    deleteNode->next->prev = temp;

    delete deleteNode;
}

void reverse_linked_list(Node* head, Node* tail){
    if(head == NULL) return;
    Node* i = head;
    Node* j = tail;
    while(i != j && i->prev != j){
        swap(i->val, j->val);
        i = i->next;
        j = j->prev;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    while (true)
    {
        int n;
        cin >> n;
        if(n == -1){
            break;
        }
        insert_at_tail(head , tail , n);
    }

    reverse_linked_list(head, tail);
    print_linked_list_forword(head);

    return 0;
}