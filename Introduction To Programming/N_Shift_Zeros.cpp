#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n ;

    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == 0){
            for(int j = i; j < n - 1; j++){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
