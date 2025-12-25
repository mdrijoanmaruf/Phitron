#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int roll;
    float cgpa;

    Student(string name , int roll , float cgpa){
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
};

int main() {
    Student* rijoan = new Student("Rijoan" , 1111, 3.23);
    return 0;
}