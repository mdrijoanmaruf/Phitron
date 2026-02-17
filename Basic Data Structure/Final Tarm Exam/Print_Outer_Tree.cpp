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
    if(val == -1) root = NULL;
    else root = new Node(val);
    
    queue<Node*> q;
    if(root) q.push(root);
    
    while(!q.empty()){
        Node* p = q.front();
        q.pop();
        
        int l, r;
        cin >> l >> r;
        
        Node* myLeft;
        Node* myRight;
        
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        
        p->left = myLeft;
        p->right = myRight;
        
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

void buildLeftPath(Node* root, vector<int>& path){
    Node* cur = root;
    while(cur){
        path.push_back(cur->val);
        if(cur->left) cur = cur->left;
        else if(cur->right) cur = cur->right;
        else break;
    }
}

void buildRightPath(Node* root, vector<int>& path){
    Node* cur = root;
    while(cur){
        path.push_back(cur->val);
        if(cur->right) cur = cur->right;
        else if(cur->left) cur = cur->left;
        else break;
    }
}

int main() {
    Node* root = input_tree();
    
    if(root == NULL) return 0;
    
    vector<int> leftPath;
    vector<int> rightPath;

    buildLeftPath(root, leftPath);
    buildRightPath(root, rightPath);

    vector<int> result;

    if(root->left == NULL && root->right == NULL){
        result.push_back(root->val);
    } else if(root->left == NULL){
        result = rightPath;
    } else if(root->right == NULL){
        for(int i = (int)leftPath.size() - 1; i >= 0; i--){
            result.push_back(leftPath[i]);
        }
    } else {
        for(int i = (int)leftPath.size() - 1; i >= 0; i--){
            result.push_back(leftPath[i]);
        }
        for(size_t i = 1; i < rightPath.size(); i++){
            result.push_back(rightPath[i]);
        }
    }

    for(size_t i = 0; i < result.size(); i++){
        if(i) cout << " ";
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}