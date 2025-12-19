#include <iostream>
using namespace std;

int main() {
    string s = "Hello World";
    // s+= "world";

    // cout << s << endl;
    // s.pop_back();
    // cout << s << endl;

    // s.assign("Gellow");
    // s = "Gellow";
    s.erase(5);
    cout << s << endl;


    return 0;
}