#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int roll;
    int marks;
};

int main() {
    int n;
    cin >> n;
    Student arr[n];

    for(int i = 0; i < n; i++){
        string name;
        int roll;
        int marks;
        cin >> name >> roll >> marks;

        Student s1;
        s1.name = name;
        s1.roll = roll;
        s1.marks = marks;

        arr[i] = s1;
    }
    return 0;
}