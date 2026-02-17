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

void print_linked_list(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_duplicate_value(Node* &head , Node* &tail){
    Node* i = head;
    Node* j;

    while(i != nullptr){ 
        j = i;
        while(j->next != nullptr){
            if(j->next->val == i->val){
                // Delete Node
                Node* deleteNode = j->next;

                // if deleteNode is tail
                if(deleteNode == tail){
                    j->next = nullptr;
                    tail = j;
                    delete deleteNode;
                    break;
                }
                j->next = deleteNode->next;
                delete deleteNode;
                continue;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    while(true){
        int n; 
        cin >> n;
        
        if(n == -1){
            break;
        }

        insert_at_tail(head , tail ,n);
    }

    delete_duplicate_value(head , tail);
    print_linked_list(head);
    return 0;
}