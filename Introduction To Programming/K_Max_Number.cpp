#include <iostream>
using namespace std;

long long arrMax(long long arr[] , int n ,long long max, int i = 0 ){

    if(i == n){
        return max;
    }

    if(arr[i] > max){
        max = arr[i];
    }

   arrMax(arr , n , max , i+1);

}

int main() {
    int n;
    cin >> n;

    long long arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout <<  arrMax(arr , n , arr[0]);


    return 0;
}