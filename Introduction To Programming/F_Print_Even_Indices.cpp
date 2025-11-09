#include <iostream>
using namespace std;

void printEven(int arr[] , int n, int c = 0){

    if(c == n){
        return ;
    }

    printEven(arr , n , c+1);
    if(c % 2 == 0){
        cout << arr[c] << " ";
    }
}

int main() {
    int n;

    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    printEven(arr , n);
    return 0;
}