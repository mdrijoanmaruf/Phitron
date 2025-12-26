#include <iostream>
using namespace std;

int main() {
    int n;
    int arr1[n];
    int arr2[n];

    for(int i = 0; i < n; i++){
        cin >> arr1[i] >> arr2[i];
    }
    for(int i = 0; i < n; i++){
        if(arr1[i] == arr2[i]){
            cout << "Square" << endl;
        } else {
            cout << "Rectangle" << endl;
        }
    }
    return 0;
}