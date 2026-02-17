#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

bool insertAtAnyPostion(Node* &head, Node* &tail, int val, int index) {
    // count length
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (index > count) return false;

    Node* newNode = new Node(val);

    // insert at head
    if (index == 0) {
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }

    // insert at middle or tail
    temp = head;
    while (--index) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }

    temp->next = newNode;
    return true;
}

void printF(Node* head) {
    cout << "L -> ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printR(Node* tail) {
    cout << "R -> ";
    while (tail) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    while (n--) {
        int index, value;
        cin >> index >> value;

        if (insertAtAnyPostion(head, tail, value, index)) {
            printF(head);
            printR(tail);
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
