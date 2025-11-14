// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int m = n;

//     bool check = true;

//     while(n != 0){
//         int digit = n % 10;
//         if(digit == 7 || digit == 4){
//             n /= 10;
//         } else {
//             check = false;
//             break;
//         }
//     }

//     if(check){
//         cout << "YES" << endl;
//     } else{
//         if(m % 4 == 0 || m % 7 == 0){
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

bool isLucky(int x) {
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (isLucky(i) && n % i == 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
