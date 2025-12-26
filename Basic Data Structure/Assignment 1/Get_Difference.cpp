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
    Node* newnode = new Node(val);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_linked_list(Node* head){
    Node* temp = head;

    if(temp->next == nullptr){
        cout << temp->val << " ";
        cout << "Inside" << endl;
        return;
    }

    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int find_max_min_diff_in_linked_list(Node* head){
    if(head->next == nullptr){
        
        return 0;
    }
    Node* temp = head;

    int max = temp->val;
    int min = temp->val;
    

    while(temp != nullptr){
        if(temp->val > max){
            max = temp->val;
    
        } else if(temp->val < min){
            min = temp->val;
        }
        temp = temp->next;

    }
    return max - min;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;

    while(true){
        cin >> value;
        if(value == -1){
            break;
        }
        insert_at_tail(head ,  tail , value);
    }

    // print_linked_list(head);

    cout << find_max_min_diff_in_linked_list(head);
    return 0;
}