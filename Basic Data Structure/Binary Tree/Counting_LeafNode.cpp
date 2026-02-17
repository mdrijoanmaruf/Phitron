#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int count_leaf_node(Node* root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int left = count_leaf_node(root->left);
    int right = count_leaf_node(root->right);
    return left + right;
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << count_leaf_node(root) << endl;
    return 0;
}