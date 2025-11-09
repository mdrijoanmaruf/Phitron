
#include <iostream>
using namespace std;

void sorting(int arr[] , int n){
  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    swap(arr[i] , arr[min]);
  }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    sorting(arr , n);

    for(int i = 0; i < n; i++){
      cout << arr[i] << endl;
    } cout << endl;
    return 0;
}