#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string arr[n];

    for(int i = 0; i <  n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i <  n; i++){
        int size = arr[i].length();

        if(size < 10){
            cout << arr[i] << endl;
        }
        else{
            string s = arr[i];
            cout << s[0] << size - 2 <<  s[size-1] << endl;
        }
    }

    
    return 0;
}