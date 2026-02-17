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

Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1){
        root = NULL;
    }else {
        root = new Node(val);
    }

    queue<Node*> q;
    if(root != NULL){
        q.push(root);
    }

    while(!q.empty()){
        // 1. Bring Out
        Node* p = q.front();
        q.pop();

        // 2. Work with this node
        int l, r;
        cin >> l >> r;
        Node* myLeft, *myRight;
        if(l == -1){
            myLeft = NULL;
        } else {
            myLeft = new Node(l);
        }

        if(r == -1){
            myRight = NULL;
        } else {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        // 3. Push Children
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }
    return root;
}

int sum_without_leaf(Node* root){
    if(root == NULL) return 0;
    
    // If it's a leaf node (no children), return 0
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    
    // If it's not a leaf node, add current value and recurse
    int left_sum = sum_without_leaf(root->left);
    int right_sum = sum_without_leaf(root->right);
    
    return root->val + left_sum + right_sum;
}

int main() {
    Node* root = input_tree();
    cout << sum_without_leaf(root) << endl;
    return 0;
}