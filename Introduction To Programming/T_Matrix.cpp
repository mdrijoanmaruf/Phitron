#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int primary = 0 , secondary = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                primary+=arr[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == n-j-1){
                secondary+=arr[i][j];
            }
        }
    }

    cout << abs(primary - secondary) << endl;
    return 0;
}