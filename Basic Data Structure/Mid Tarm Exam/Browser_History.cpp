#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

Node* nextLL(Node* c) {
    if (c && c->next) {
        cout << c->next->val << endl;
        return c->next;
    }
    cout << "Not Available" << endl;
    return c;
}

Node* prevLL(Node* c) {
    if (c && c->prev) {
        cout << c->prev->val << endl;
        return c->prev;
    }
    cout << "Not Available" << endl;
    return c;
}

Node* visit(Node* head, string s2 , Node* c) {
    Node* temp = head;
    while (temp->val != s2 && temp != NULL) {
        temp = temp->next;
        if(temp == NULL){
            cout << "Not Available" << endl;
            return c;
        }
    }

    if (temp != NULL) {
        cout << temp->val << endl;
    }
    return temp;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    while (true) {
        string s;
        cin >> s;
        if (s == "end") break;
        insert_at_tail(head, tail, s);
    }

    int n;
    cin >> n;

    Node* c = NULL;  

    while (n--) {
        string s, s2;
        cin >> s;

        if (s == "visit") {
            cin >> s2;
            c = visit(head, s2 , c);
        } 
        else if (s == "next") {
            if (c){
                c = nextLL(c);
            }
        } 
        else if (s == "prev") {
            if (c){
                c = prevLL(c);
            }
        }
    }

    return 0;
}
