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

void print_level_nodes(Node* root, int target_level){
    if(root == NULL){
        cout << "Invalid" << endl;
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    int current_level = 0;
    bool found = false;
    
    while(!q.empty()){
        int level_size = q.size();
        
        if(current_level == target_level){
            found = true;
            for(int i = 0; i < level_size; i++){
                Node* node = q.front();
                q.pop();
                cout << node->val;
                if(i < level_size - 1){
                    cout << " ";
                }
            }
            cout << endl;
            return;
        }
        
        for(int i = 0; i < level_size; i++){
            Node* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        current_level++;
    }
    
    if(!found){
        cout << "Invalid" << endl;
    }
}

int main() {
    Node* root = input_tree();
    int x;
    cin >> x;
    
    print_level_nodes(root, x);
    
    return 0;
}