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
    
    sort(arr, arr + n);

    int first = arr[0];
    int count = 0;

    for(int i = 0; i < n; i++){
        if(first == arr[i]){
            count ++;
        } else {
            break;
        }
    }

    if(count % 2 == 0){
        cout << "Unlucky";
    } else {
        cout << "Lucky";
    }
    
    return 0;
}
