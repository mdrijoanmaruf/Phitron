#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        int liftA , LiftB , bToC;
        cin >> liftA >> LiftB >> bToC;

        int liftBTime = abs(bToC - LiftB) + abs(bToC);
        int liftATime = abs(liftA);

        if(liftATime < liftBTime){
            cout << 1 << endl;
        } else if(liftBTime < liftATime){
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
    return 0;
}