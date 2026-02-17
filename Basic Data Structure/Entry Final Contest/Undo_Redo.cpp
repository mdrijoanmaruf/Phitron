#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string text = "";
    stack<char> redo_stack;
    
    for(int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if(operation == "TYPE") {
            char x;
            cin >> x;
            text += x;
            while(!redo_stack.empty()) {
                redo_stack.pop();
            }
        }
        else if(operation == "UNDO") {
            if(!text.empty()) {
                char last = text.back();
                text.pop_back();
                redo_stack.push(last);
            }
        }
        else if(operation == "REDO") {
            if(!redo_stack.empty()) {
                char ch = redo_stack.top();
                redo_stack.pop();
                text += ch;
            }
        }
    }
    
    cout << text << '\n';
    
    return 0;
}