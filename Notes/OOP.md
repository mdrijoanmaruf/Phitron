# Object-Oriented Programming (OOP) - Complete Notes

## Table of Contents
1. [Basic Concepts](#basic-concepts)
2. [Class and Object](#class-and-object)
3. [Access Modifiers](#access-modifiers)
4. [Constructor](#constructor)
5. [Encapsulation](#encapsulation)
6. [Inheritance](#inheritance)
7. [Polymorphism](#polymorphism)
8. [Function Overloading](#function-overloading)
9. [Operator Overloading](#operator-overloading)
10. [Static Members](#static-members)
11. [Friend Function](#friend-function)
12. [Additional Concepts](#additional-concepts)

---

# Basic Concepts

## What is OOP?
**Object-Oriented Programming is a programming paradigm based on objects and classes**

**Key Principles:**
- **Encapsulation** - Bundling data and methods together
- **Inheritance** - Deriving new classes from existing ones
- **Polymorphism** - Same function behaving differently
- **Abstraction** - Hiding complex implementation details

---

# Class and Object

## 1. Basic Class Definition
**A class is a blueprint for creating objects**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;      // data member
    int roll;         // data member
    float cgpa;       // data member
};

int main() {
    Student s1;       // creating object
    s1.name = "Rijoan";
    s1.roll = 101;
    s1.cgpa = 3.75;
    
    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;
    return 0;
}
```

**Key Points:**
- Class is a user-defined data type
- Object is an instance of a class
- Use dot (.) operator to access members

---

## 2. Array of Objects
**Create multiple objects using array**

```cpp
class Student{
    public:
    string name;
    int roll;
    int marks;
};

int main() {
    int n;
    cin >> n;
    Student arr[n];   // array of objects
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].roll >> arr[i].marks;
    }
    
    for(int i = 0; i < n; i++){
        cout << arr[i].name << " " << arr[i].roll << " " << arr[i].marks << endl;
    }
    return 0;
}
```

---

## 3. Dynamic Object
**Create objects dynamically using pointers**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
};

int main() {
    Student* s1 = new Student();  // dynamic object creation
    
    s1->name = "Rijoan";          // use arrow (->) for pointer
    s1->roll = 101;
    s1->cgpa = 3.75;
    
    cout << s1->name << " " << s1->roll << " " << s1->cgpa << endl;
    
    delete s1;                    // free memory
    return 0;
}
```

**Key Difference:**
- `.` operator for normal objects
- `->` operator for pointer objects

---

# Access Modifiers

## Understanding Access Modifiers
**Control access to class members**

```cpp
class Student{
    private:
    int roll;           // only accessible inside class
    
    protected:
    float cgpa;         // accessible in class and derived classes
    
    public:
    string name;        // accessible everywhere
    
    // public method to access private data
    void setRoll(int r){
        roll = r;
    }
    
    int getRoll(){
        return roll;
    }
};

int main() {
    Student s1;
    s1.name = "Rijoan";       // OK - public
    // s1.roll = 101;         // ERROR - private
    s1.setRoll(101);          // OK - using public method
    
    cout << s1.getRoll() << endl;
    return 0;
}
```

**Access Levels:**

| Modifier | Same Class | Derived Class | Outside Class |
|----------|------------|---------------|---------------|
| **public** | ✓ | ✓ | ✓ |
| **protected** | ✓ | ✓ | ✗ |
| **private** | ✓ | ✗ | ✗ |

---

# Constructor

## 1. Default Constructor
**Constructor that takes no parameters**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
    
    // default constructor
    Student(){
        name = "Unknown";
        roll = 0;
        cgpa = 0.0;
    }
};

int main() {
    Student s1;       // default constructor called automatically
    cout << s1.name << endl;  // Output: Unknown
    return 0;
}
```

**Key Points:**
- Called automatically when object is created
- No return type (not even void)
- Same name as class

---

## 2. Parameterized Constructor
**Constructor that takes parameters to initialize object**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
    
    // parameterized constructor
    Student(string n, int r, float c){
        name = n;
        roll = r;
        cgpa = c;
    }
};

int main() {
    Student s1("Rijoan", 101, 3.75);  // passing values
    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;
    return 0;
}
```

---

## 3. Constructor with 'this' Pointer
**Use 'this' pointer when parameter names match member names**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
    
    // using this pointer
    Student(string name, int roll, float cgpa){
        this->name = name;      // this->name refers to member variable
        this->roll = roll;      // roll (right side) is parameter
        this->cgpa = cgpa;
    }
};

int main() {
    Student s1("Rijoan", 101, 3.75);
    cout << s1.name << endl;
    return 0;
}
```

**this Pointer:**
- Points to the current object
- Useful when parameter names = member names
- Automatically available in member functions

---

## 4. Copy Constructor
**Create a new object as a copy of an existing object**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
    
    Student(string name, int roll, float cgpa){
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
    
    // copy constructor
    Student(const Student &obj){
        name = obj.name;
        roll = obj.roll;
        cgpa = obj.cgpa;
    }
};

int main() {
    Student s1("Rijoan", 101, 3.75);
    Student s2 = s1;              // copy constructor called
    Student s3(s1);               // another way to call copy constructor
    
    cout << s2.name << endl;      // Output: Rijoan
    return 0;
}
```

---

## 5. Constructor with Dynamic Memory
**Constructor for dynamic object creation**

```cpp
class Student{
    public:
    string name;
    int roll;
    float cgpa;
    
    Student(string name, int roll, float cgpa){
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
};

int main() {
    Student* s1 = new Student("Rijoan", 101, 3.75);  // dynamic object
    
    cout << s1->name << " " << s1->roll << endl;
    
    delete s1;  // free memory
    return 0;
}
```

---

# Encapsulation

## Data Hiding and Getter/Setter
**Bundle data and methods, hide data using private access**

```cpp
class BankAccount{
    private:
    string accountNumber;
    double balance;
    
    public:
    BankAccount(string accNo, double bal){
        accountNumber = accNo;
        balance = bal;
    }
    
    // getter methods
    string getAccountNumber(){
        return accountNumber;
    }
    
    double getBalance(){
        return balance;
    }
    
    // setter methods with validation
    void deposit(double amount){
        if(amount > 0){
            balance += amount;
        }
    }
    
    void withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
        }
    }
};

int main() {
    BankAccount acc("12345", 1000.0);
    
    // acc.balance = 5000;     // ERROR - private member
    acc.deposit(500);          // OK - using public method
    
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
```

**Benefits:**
- Data protection and validation
- Controlled access to data
- Easy to maintain and modify

---

# Inheritance

## 1. Single Inheritance
**Derive a class from one base class**

```cpp
// Base class (Parent)
class Person{
    public:
    string name;
    int age;
    
    void display(){
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class (Child)
class Student : public Person{
    public:
    int roll;
    float cgpa;
    
    void displayStudent(){
        cout << "Roll: " << roll << ", CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Rijoan";      // inherited from Person
    s1.age = 20;             // inherited from Person
    s1.roll = 101;
    s1.cgpa = 3.75;
    
    s1.display();            // using base class method
    s1.displayStudent();     // using derived class method
    return 0;
}
```

---

## 2. Multilevel Inheritance
**Chain of inheritance: A → B → C**

```cpp
// Base class
class Person{
    public:
    string name;
    int age;
};

// Derived from Person
class Student : public Person{
    public:
    int roll;
};

// Derived from Student
class GraduateStudent : public Student{
    public:
    string thesis;
};

int main() {
    GraduateStudent gs;
    gs.name = "Rijoan";      // from Person
    gs.age = 24;             // from Person
    gs.roll = 101;           // from Student
    gs.thesis = "AI Research";  // own member
    
    return 0;
}
```

---

## 3. Multiple Inheritance
**Derive from multiple base classes**

```cpp
class Father{
    public:
    string surname;
};

class Mother{
    public:
    string hairColor;
};

// Multiple inheritance
class Child : public Father, public Mother{
    public:
    string name;
};

int main() {
    Child c;
    c.name = "Rijoan";
    c.surname = "Khan";      // from Father
    c.hairColor = "Black";   // from Mother
    
    return 0;
}
```

---

## 4. Hierarchical Inheritance
**Multiple classes derived from one base class**

```cpp
class Shape{
    public:
    string color;
};

class Circle : public Shape{
    public:
    double radius;
};

class Rectangle : public Shape{
    public:
    double length, width;
};

int main() {
    Circle c;
    c.color = "Red";
    c.radius = 5.0;
    
    Rectangle r;
    r.color = "Blue";
    r.length = 10.0;
    r.width = 5.0;
    
    return 0;
}
```

---

## 5. Constructor in Inheritance
**Base class constructor is called first**

```cpp
class Person{
    public:
    string name;
    
    Person(string n){
        name = n;
        cout << "Person constructor called" << endl;
    }
};

class Student : public Person{
    public:
    int roll;
    
    Student(string n, int r) : Person(n){  // calling base constructor
        roll = r;
        cout << "Student constructor called" << endl;
    }
};

int main() {
    Student s1("Rijoan", 101);
    // Output: Person constructor called
    //         Student constructor called
    return 0;
}
```

---

# Polymorphism

## 1. Function Overriding (Runtime Polymorphism)
**Derived class redefines base class function**

```cpp
class Animal{
    public:
    void sound(){
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal{
    public:
    void sound(){           // overriding base class function
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal{
    public:
    void sound(){           // overriding base class function
        cout << "Cat meows" << endl;
    }
};

int main() {
    Dog d;
    d.sound();     // Output: Dog barks
    
    Cat c;
    c.sound();     // Output: Cat meows
    
    return 0;
}
```

---

## 2. Virtual Functions
**Enable runtime polymorphism with base class pointers**

```cpp
class Animal{
    public:
    virtual void sound(){    // virtual keyword
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal{
    public:
    void sound(){
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal{
    public:
    void sound(){
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a;           // base class pointer
    
    Dog d;
    a = &d;
    a->sound();         // Output: Dog barks (runtime binding)
    
    Cat c;
    a = &c;
    a->sound();         // Output: Cat meows (runtime binding)
    
    return 0;
}
```

**Without virtual:** Base class function called  
**With virtual:** Derived class function called

---

# Function Overloading

## Function Overloading (Compile-time Polymorphism)
**Multiple functions with same name but different parameters**

```cpp
class Calculator{
    public:
    // add two integers
    int add(int a, int b){
        return a + b;
    }
    
    // add three integers
    int add(int a, int b, int c){
        return a + b + c;
    }
    
    // add two doubles
    double add(double a, double b){
        return a + b;
    }
};

int main() {
    Calculator calc;
    
    cout << calc.add(5, 10) << endl;           // Output: 15
    cout << calc.add(5, 10, 15) << endl;       // Output: 30
    cout << calc.add(5.5, 10.5) << endl;       // Output: 16.0
    
    return 0;
}
```

**Rules:**
- Different number of parameters, OR
- Different types of parameters, OR
- Different order of parameters

---

# Operator Overloading

## Overloading Operators
**Define custom behavior for operators**

```cpp
class Complex{
    public:
    int real, imag;
    
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }
    
    // overload + operator
    Complex operator + (Complex const &obj){
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }
    
    // overload - operator
    Complex operator - (Complex const &obj){
        Complex result;
        result.real = real - obj.real;
        result.imag = imag - obj.imag;
        return result;
    }
    
    void display(){
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    Complex c3 = c1 + c2;    // using overloaded + operator
    c3.display();            // Output: 4 + 6i
    
    Complex c4 = c1 - c2;    // using overloaded - operator
    c4.display();            // Output: 2 + 2i
    
    return 0;
}
```

**Common Operators to Overload:**
- Arithmetic: `+`, `-`, `*`, `/`
- Comparison: `==`, `!=`, `<`, `>`
- Assignment: `=`
- Stream: `<<`, `>>`

---

# Static Members

## 1. Static Data Members
**Shared by all objects of the class**

```cpp
class Student{
    public:
    string name;
    static int totalStudents;   // static member
    
    Student(string n){
        name = n;
        totalStudents++;        // increment for each object
    }
};

// initialize static member outside class
int Student::totalStudents = 0;

int main() {
    Student s1("Rijoan");
    Student s2("Karim");
    Student s3("Rahim");
    
    cout << "Total Students: " << Student::totalStudents << endl;  // Output: 3
    
    return 0;
}
```

---

## 2. Static Member Functions
**Can be called without creating an object**

```cpp
class Math{
    public:
    static int square(int x){
        return x * x;
    }
    
    static int cube(int x){
        return x * x * x;
    }
};

int main() {
    // call without creating object
    cout << Math::square(5) << endl;    // Output: 25
    cout << Math::cube(3) << endl;      // Output: 27
    
    return 0;
}
```

**Key Points:**
- Static members belong to class, not objects
- Accessed using class name with `::`
- Static functions can only access static members

---

# Friend Function

## Friend Function
**Non-member function that can access private members**

```cpp
class Box{
    private:
    int length;
    int width;
    
    public:
    Box(int l, int w){
        length = l;
        width = w;
    }
    
    // declare friend function
    friend int calculateArea(Box b);
};

// friend function definition
int calculateArea(Box b){
    return b.length * b.width;   // can access private members
}

int main() {
    Box b1(10, 5);
    
    cout << "Area: " << calculateArea(b1) << endl;  // Output: 50
    
    return 0;
}
```

**Friend Class:**
```cpp
class B;   // forward declaration

class A{
    private:
    int data;
    
    public:
    A(int d){ data = d; }
    
    friend class B;   // B can access private members of A
};

class B{
    public:
    void display(A &obj){
        cout << "Data: " << obj.data << endl;  // accessing private member
    }
};
```

---

# Additional Concepts

## 1. Destructor
**Called automatically when object is destroyed**

```cpp
class Student{
    public:
    string name;
    
    Student(string n){
        name = n;
        cout << "Constructor called for " << name << endl;
    }
    
    // destructor
    ~Student(){
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("Rijoan");
    Student s2("Karim");
    // Destructors called automatically in reverse order
    return 0;
}
```

**Key Points:**
- Name: `~ClassName()`
- No parameters, no return type
- Used to free resources (memory, files, etc.)

---

## 2. Function Inside Class
**Member functions defined inside or outside class**

```cpp
class Student{
    public:
    string name;
    int roll;
    
    // function defined inside class
    void displayInside(){
        cout << name << " " << roll << endl;
    }
    
    // function declared inside, defined outside
    void displayOutside();
};

// definition outside class
void Student::displayOutside(){
    cout << "Name: " << name << ", Roll: " << roll << endl;
}

int main() {
    Student s1;
    s1.name = "Rijoan";
    s1.roll = 101;
    
    s1.displayInside();
    s1.displayOutside();
    
    return 0;
}
```

---

## 3. Const Member Functions
**Functions that cannot modify object data**

```cpp
class Student{
    private:
    string name;
    int roll;
    
    public:
    Student(string n, int r){
        name = n;
        roll = r;
    }
    
    // const member function
    void display() const{
        cout << name << " " << roll << endl;
        // name = "New";  // ERROR - cannot modify in const function
    }
    
    string getName() const{
        return name;   // OK - just reading
    }
};
```

---

## Key OOP Concepts Summary

| Concept | Description | Benefit |
|---------|-------------|---------|
| **Encapsulation** | Bundle data and methods | Data hiding, security |
| **Inheritance** | Reuse existing code | Code reusability |
| **Polymorphism** | Many forms of same function | Flexibility |
| **Abstraction** | Hide implementation details | Simplicity |

---

## Types of Polymorphism

| Type | Mechanism | Binding Time | Example |
|------|-----------|--------------|---------|
| **Compile-time** | Function/Operator Overloading | Compile | `add(int, int)` vs `add(double, double)` |
| **Runtime** | Virtual Functions | Runtime | Base pointer calling derived function |

---

## Constructor Types Comparison

| Type | Purpose | Example |
|------|---------|---------|
| **Default** | Initialize with default values | `Student()` |
| **Parameterized** | Initialize with specific values | `Student(string, int)` |
| **Copy** | Create copy of existing object | `Student(const Student&)` |

---

## Access Modifier Best Practices

1. **Make data members private** - Protect data from direct access
2. **Provide public getter/setter** - Controlled access with validation
3. **Use protected for inheritance** - Allow derived class access
4. **Keep implementation private** - Hide complex logic

---

## Common OOP Mistakes to Avoid

1. **Not using access modifiers** - Everything public by default in struct
2. **Forgetting to initialize in constructor** - Leads to garbage values
3. **Not using virtual for polymorphism** - Base function called instead
4. **Memory leaks** - Not deleting dynamically allocated objects
5. **Incorrect use of this pointer** - Using same name without this->
