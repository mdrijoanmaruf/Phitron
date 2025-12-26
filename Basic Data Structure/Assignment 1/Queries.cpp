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

void insert_at_tail(Node* &head , Node* &tail , int val){
    Node* newNode = new Node(val);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void insert_at_head(Node* &head , Node* &tail , int val){
    Node* newNode = new Node(val);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insert_at_any_postion(Node* &head , Node* &tail , int index , int val){
    if(index == 0){
        insert_at_head(head , tail , val);
    }

    Node* newNode = new Node(val);

    Node* temp = head;
    while(--index){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_at_any_postion(Node* &head , Node* &tail , int index ){

    if(head == nullptr){
        return;
    }

    Node* temp = head;
    if(index == 0){
        Node* deleteNode = head;
        head = head->next;
        if(head == nullptr){
            tail == nullptr;
        }
        delete deleteNode;
        return;
    }
    while(--index && temp != nullptr){
        temp = temp->next;
    }

    if(temp == nullptr || temp->next == nullptr){
        return;
    }

    Node* deleteNode = temp->next;
    if(deleteNode == tail){
        tail = temp;
    }
    temp->next = deleteNode->next;
    delete deleteNode;

}

void print_linked_list(Node* head){

    if(head == nullptr){
        cout << endl;
        return;
    }
    Node* temp = head;

    if(temp->next == nullptr){
        cout << temp->val << " ";
        cout << endl;
        return;
    }

    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cin >> n;
    while(n--){
        int x , v;
        cin >> x >> v;

        if(x == 0){
            insert_at_head(head , tail , v);
        } else if(x == 1){
            insert_at_tail(head , tail , v);
        } else if(x == 2){
            delete_at_any_postion(head , tail , v);
        }
        print_linked_list(head);
    }

    


    return 0;
}