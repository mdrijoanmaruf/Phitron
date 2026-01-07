#include <bits/stdc++.h>
using namespace std;

void printChar(int x, char ch){
    for(int i = 0; i < x; i++){
        cout << ch << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    while(n--){
        int x;
        char ch;
        cin >> x >> ch;
        
        printChar(x, ch); 
    }
    
    return 0;
}
