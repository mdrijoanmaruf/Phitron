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

int count_nodes(Node* root){
    if(root == NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int max_depth(Node* root){
    if(root == NULL) return -1;
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    return max(left_depth, right_depth) + 1;
}

bool is_perfect(Node* root){
    if(root == NULL) return true;
    
    int total_nodes = count_nodes(root);
    int depth = max_depth(root);
    
    // Formula: Total nodes = 2^(depth+1) - 1
    int expected_nodes = pow(2, depth + 1) - 1;
    
    return total_nodes == expected_nodes;
}

int main() {
    Node* root = input_tree();
    
    if(is_perfect(root)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}