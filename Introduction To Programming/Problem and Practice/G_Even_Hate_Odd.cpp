#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        int size;
        cin >> size;
        
        if(size % 2 != 0){
            cout << -1 << endl;
            continue;
        }

        vector<int> arr(size);
        int count_even = 0; 
        int count_odd = 0;

        for(int i = 0; i < size; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0){
                count_even++;
            }else{
                count_odd++;
            }
        }

        cout << abs(count_even - count_odd) / 2 << endl;
    }

    return 0;
}
