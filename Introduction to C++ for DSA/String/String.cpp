#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin , s);

    s.resize(100 , '*');
    cout << s << endl;
    // s.clear();
    // cout << s.size() << endl;
    // cout << s.max_size() << endl;
    // cout << s.capacity() << endl;

    // if(s.empty() == true){
    //     cout << "Empty" << endl;
    // } else {
    //     cout << "Not Empty" << endl;
    // }
    
    return 0;
}