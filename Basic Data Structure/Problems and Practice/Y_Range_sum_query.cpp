#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , q;
    cin >> n >> q;

    vector<long long> arr(n);


    for(long long &i : arr){
        cin >> i;
    }

    vector<long long> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    while(q--){
        int l , r;
        cin >> l >> r;

        if(l == 1){
            cout << prefixSum[r-1] << endl;
        } else{
            cout << prefixSum[r-1] - prefixSum[l-1-1] << endl ;
        }
    }
    return 0;
}