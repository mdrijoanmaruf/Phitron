# Linked List - Complete Notes

## Table of Contents
1. [Singly Linked List](#singly-linked-list)
2. [Doubly Linked List](#doubly-linked-list)

---

# Singly Linked List

## 1. Node Structure
**Creates a basic node with value and next pointer**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;          // stores the data value
    Node* next;       // pointer to the next node

    Node(int val){
        this->val = val;
        this->next = NULL;  // initialize next pointer to NULL
    }
};
```

---

## 2. Print Linked List
**Traverse and print all values from head to tail**

```cpp
void print_linked_list(Node* head){
    Node* temp = head;              // temporary pointer to traverse
    while(temp != nullptr){         // loop until end of list
        cout << temp->val << " ";   // print current node value
        temp = temp->next;          // move to next node
    }
    cout << endl;
}
```

---

## 3. Print Linked List in Reverse (Recursion)
**Print values in reverse order using recursion**

```cpp
void print_reverse_linkedlist(Node* temp){
    if(temp == NULL){               // base case: reached end
        return;
    }
    print_reverse_linkedlist(temp->next);  // recursive call for next node
    cout << temp->val << " ";              // print after recursion (reverse order)
}
```

---

## 4. Insert at Head
**Insert a new node at the beginning of the list**

```cpp
void insert_at_head(Node* &head , int val){
    Node* newnode = new Node(val);  // create new node
    newnode->next = head;           // new node points to current head
    head = newnode;                 // update head to new node
}
```

**Time Complexity:** O(1)

---

## 5. Insert at Tail (Not Optimized)
**Insert a new node at the end of the list by traversing to the last node**

```cpp
void insert_at_tail(Node* head , int val){
    Node* newnode = new Node(val);  // create new node

    if(head == nullptr){            // if list is empty
        head = newnode;
        return;
    }
    
    Node* temp = head;              // start from head
    while(temp->next != nullptr){   // traverse to last node
        temp = temp->next;
    }

    temp->next = newnode;           // link last node to new node
}
```

**Time Complexity:** O(n) - needs to traverse entire list

---

## 6. Insert at Tail (Optimized with Tail Pointer)
**Insert a new node at the end using tail pointer**

```cpp
void insert_at_tail(Node* head , Node* &tail, int val){
    Node* newnode = new Node(val);  // create new node

    if(head == nullptr){            // if list is empty
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;           // current tail points to new node
    tail = tail->next;              // update tail to new node
}
```

**Time Complexity:** O(1)

---

## 7. Insert at Any Position
**Insert a new node at a specific position in the list**

```cpp
void insert_at_any_position(Node* &head , int pos , int val){
    Node* newnode = new Node(val);  // create new node
    Node* temp = head;              // start from head
    
    while(--pos){                   // move to position-1
        temp = temp->next;
    }

    newnode->next = temp->next;     // new node points to next node
    temp->next = newnode;           // previous node points to new node
}
```

**Time Complexity:** O(n)  
**Note:** Position is 0-indexed. To insert at position 2, it inserts after the 2nd node.

---

## 8. Delete at Head
**Remove the first node from the list**

```cpp
void delete_at_head(Node* &head){
    Node* deleteNode = head;        // save reference to head
    head = head->next;              // move head to next node
    delete deleteNode;              // free memory
}
```

**Time Complexity:** O(1)

---

## 9. Delete at Any Position
**Remove a node at a specific position in the list**

```cpp
void delete_at_any_position(Node* &head , int pos){
    Node* temp = head;              // start from head
    
    while(--pos){                   // move to position-1
        temp = temp->next;
    }

    Node* deleteNode = temp->next;  // save node to be deleted
    temp->next = deleteNode->next;  // bypass the node to be deleted
    delete deleteNode;              // free memory
}
```

**Time Complexity:** O(n)  
**Note:** Position is 0-indexed.

---

## 10. Input in Linked List
**Take input and create a linked list**

```cpp
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    
    while(cin >> val && val != -1){     // input until -1
        if(head == NULL){               // first node
            head = new Node(val);
            tail = head;
        }
        else{
            insert_at_tail(head, tail, val);  // insert at tail
        }
    }
    
    print_linked_list(head);
    return 0;
}
```

---

# Doubly Linked List

## 1. Node Structure
**Creates a node with value, next pointer, and previous pointer**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;          // stores the data value
    Node* next;       // pointer to the next node
    Node* prev;       // pointer to the previous node

    Node(int val){
        this->val = val;
        this->next = NULL;   // initialize next to NULL
        this->prev = NULL;   // initialize prev to NULL
    }
};
```

---

## 2. Print Forward
**Traverse and print from head to tail**

```cpp
void print_linked_list_forword(Node* head){
    Node* temp = head;              // temporary pointer to traverse
    while(temp != NULL){            // loop until end
        cout << temp->val << " ";   // print current value
        temp = temp->next;          // move to next node
    }
    cout << endl;
}
```

---

## 3. Print Backward
**Traverse and print from tail to head**

```cpp
void print_linked_list_backword(Node* tail){
    Node* temp = tail;              // start from tail
    while(temp != NULL){            // loop until beginning
        cout << temp->val << " ";   // print current value
        temp = temp->prev;          // move to previous node
    }
    cout << endl;
}
```

---

## 4. Insert at Head
**Insert a new node at the beginning of the doubly linked list**

```cpp
void insert_at_head(Node* &head , Node* &tail, int val){
    Node* newNode = new Node(val);  // create new node

    if(head == NULL){               // if list is empty
        head = newNode;
        tail = newNode;
        return;
    }
    
    newNode->next = head;           // new node points to current head
    head->prev = newNode;           // current head's prev points to new node

    head = newNode;                 // update head to new node
}
```

**Time Complexity:** O(1)

---

## 5. Insert at Tail
**Insert a new node at the end of the doubly linked list**

```cpp
void insert_at_tail(Node* &head , Node* &tail , int val){
    Node* newNode = new Node(val);  // create new node

    if(head == NULL){               // if list is empty
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;           // current tail points to new node
    newNode->prev = tail;           // new node's prev points to current tail

    tail = newNode;                 // update tail to new node
}
```

**Time Complexity:** O(1)

---

## 6. Insert at Any Position
**Insert a new node at a specific position in the doubly linked list**

```cpp
void insert_at_any_postion(Node* &head , Node* &tail , int index , int val){
    // treat non-positive index as insert-at-head
    if(index <= 0){
        insert_at_head(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);  // create new node

    // if linked list empty, just set head/tail
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = head;              // start from head
    int i = 0;
    while(i < index-1 && temp->next != NULL){  // move to position-1
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
    newNode->next = temp->next;     // new node points to next node
    temp->next->prev = newNode;     // next node's prev points to new node
    newNode->prev = temp;           // new node's prev points to current node
    temp->next = newNode;           // current node points to new node
}
```

**Time Complexity:** O(n)

---

## 7. Delete at Head
**Remove the first node from the doubly linked list**

```cpp
void delete_at_head(Node* &head, Node* &tail){
    Node* deleteNode = head;        // save reference to head
    
    if(deleteNode->next == NULL){   // if only one node
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }
    
    deleteNode->next->prev = NULL;  // next node's prev becomes NULL
    head = deleteNode->next;        // move head to next node

    delete deleteNode;              // free memory
}
```

**Time Complexity:** O(1)

---

## 8. Delete at Tail
**Remove the last node from the doubly linked list**

```cpp
void delete_at_tail(Node* &head , Node* &tail){
    Node* deleteNode = tail;        // save reference to tail
    
    if(tail->prev == NULL){         // if only one node
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }

    deleteNode->prev->next = NULL;  // previous node's next becomes NULL
    tail = deleteNode->prev;        // move tail to previous node
    
    delete deleteNode;              // free memory
}
```

**Time Complexity:** O(1)

---

## 9. Delete at Any Position
**Remove a node at a specific position in the doubly linked list**

```cpp
void delete_at_any_postion(Node* &head , Node* &tail, int postion){
    Node* temp = head;              // start from head
    
    while(--postion && temp->next != NULL){  // move to position-1
        temp = temp->next;
    }

    Node* deleteNode = temp->next;  // save node to be deleted

    temp->next = deleteNode->next;  // bypass the node
    deleteNode->next->prev = temp;  // update prev pointer

    delete deleteNode;              // free memory
}
```

**Time Complexity:** O(n)  
**Note:** This function assumes the position is valid and not at head or tail.

---

## 10. Input in Doubly Linked List
**Take input and create a doubly linked list**

```cpp
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    while (true)
    {
        int n;
        cin >> n;               // take input
        if(n == -1){            // stop when -1 is entered
            break;
        }
        insert_at_tail(head , tail , n);  // insert at tail
    }

    print_linked_list_forword(head);   // print forward
    print_linked_list_backword(tail);  // print backward

    return 0;
}
```

**Alternative using while condition:**
```cpp
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    
    while(cin >> val && val != -1){     // input until -1
        if(head == NULL){               // first node
            head = new Node(val);
            tail = head;
        }
        else{
            insert_at_tail(head, tail, val);  // insert at tail
        }
    }
    
    print_linked_list_forword(head);
    print_linked_list_backword(tail);
    return 0;
}
```

---

## Key Differences: Singly vs Doubly Linked List

| Feature | Singly Linked List | Doubly Linked List |
|---------|-------------------|-------------------|
| **Pointer** | Only `next` pointer | Both `next` and `prev` pointers |
| **Memory** | Less memory (1 pointer per node) | More memory (2 pointers per node) |
| **Traversal** | Only forward | Both forward and backward |
| **Deletion** | Need previous node reference | Can delete with current node only |
| **Insert at Tail** | O(n) without tail pointer | O(1) with tail pointer |

---

## Common Mistakes to Avoid

1. **Forgetting to update head/tail** when inserting/deleting
2. **Not handling NULL cases** (empty list)
3. **Memory leaks** - always delete nodes when removing
4. **Wrong position calculation** - be careful with 0-indexed vs 1-indexed
5. **In doubly linked list** - forgetting to update both `next` and `prev` pointers

---

## Time Complexity Summary

| Operation | Array | Singly LL | Doubly LL |
|-----------|-------|-----------|-----------|
| Insert at Head | O(n) | O(1) | O(1) |
| Insert at Tail (with tail pointer) | O(1) | O(1) | O(1) |
| Insert at Position | O(n) | O(n) | O(n) |
| Delete at Head | O(n) | O(1) | O(1) |
| Delete at Tail (with tail pointer) | O(1) | O(n) | O(1) |
| Delete at Position | O(n) | O(n) | O(n) |
| Search | O(n) | O(n) | O(n) |
| Access by Index | O(1) | O(n) | O(n) |
| Print | O(n) | O(n) | O(n) |
