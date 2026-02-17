#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long arr[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<long long> fixedRows; 

    for(int i = 0; i < n; i++){
        long long sum = 0;
        bool hasZero = false;

        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                hasZero = true;
            }
            sum += arr[i][j];
        }

        if(!hasZero){
            fixedRows.push_back(sum);
        }
    }

    for(int i = 1; i < fixedRows.size(); i++){
        if(fixedRows[i] != fixedRows[0]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
