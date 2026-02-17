#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        int x , y;
        cin >> x >> y; 
        float mustPage = 0;

        if(y > 2){
            mustPage = ceil(y/2.0);
        }

        int icons = x + y*4;
        float page = ceil(icons / 15.0);

        if(page > mustPage){
            cout << page << endl;
        } else {
            cout << mustPage << endl;
        }
    }
    return 0;
}