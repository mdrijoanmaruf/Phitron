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

int linked_list_size(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}


class myStack{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    
    void push(int val){
        insert_at_tail(head, tail , val);
    }

    void pop(){
        delete_at_tail(head , tail);
    }

    int top(){
        return tail->val;
    }

    int size(){
        return linked_list_size(head);
    }

    bool empty(){
        return linked_list_size(head) == 0;
    }
};

int main() {
    myStack st;

    int n;
    cin >>  n;

    while(n--){
        int x;
        cin >> x;
        st.push(x);
    }

    while(true){
        if(st.empty()){
            break;
        }
        cout << st.top() << endl;
        st.pop();
        
    }
    return 0;
}