#include <iostream>
using namespace std;

int main() {
    int arr[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }

    // Find the index of 1
    int pi = 0 , pj = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] != 0){
                pi = i;
                pj = j;
                break;
            }
        }
    }

    int count = abs(2 - pi) + abs(2 - pj);
    cout << count << endl;

    return 0;
}