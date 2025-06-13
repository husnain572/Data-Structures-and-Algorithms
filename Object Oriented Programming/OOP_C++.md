# C++ OOP Notes

## Classes & Objects

- **Object**: Real world entity (e.g., car, teacher, student).
- **Class**: Blueprint/template that defines the structure of an object.

**Example:**  
Toyota is a blueprint (Class), and multiple cars made from it are objects.

---

## Access Modifiers

| Modifier   | Access Allowed In                   |
|------------|-------------------------------------|
| `private`  | Only inside the class               |
| `public`   | Accessible from anywhere            |
| `protected`| Class + derived (child) classes     |

---

## Syntax Example: Class with Constructors and Methods

```cpp
#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name, dept, subject;

    // Non-parameterized constructor
    Teacher() {
        cout << "Hi, I am constructor.\n";
        dept = "Computer Science";
    }

    // Parameterized constructor
    Teacher(string n, string dep, string sub, double sal) {
        name = n;
        dept = dep;
        subject = sub;
        salary = sal;
    }

    // Method
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter
    void setSalary(double s) {
        salary = s;
    }

    // Getter
    double getSalary() {
        return salary;
    }

    // Display Info
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Teacher T1;
    T1.name = "Husnain";
    T1.dept = "IT";
    T1.subject = "CS";
    T1.setSalary(120000);

    cout << "Teacher name is " << T1.name
         << ", department " << T1.dept
         << ", subject is " << T1.subject
         << " and salary is " << T1.getSalary() << endl;

    cout << "\nData printing using parameterized constructor\n";
    Teacher T2("Ali", "IT", "CS", 85000);
    T2.getInfo();

    cout << "\nCopying data using default copy constructor\n";
    Teacher T3(T2);  // Copy constructor
    T3.getInfo();

    return 0;
}
````

---

## OOP ke 4 Pillars

1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

---

## Encapsulation

* **Definition**: Wrapping data + functions into one unit (class).
* **Example**: Private variables with public setters/getters.
* **Benefit**: Data hiding and secure code.

---

## Constructor

**Constructor** is a special function that:

* Automatically calls when an object is created
* Has the same name as the class
* Has no return type
* Allocates memory during object creation

### Types of Constructor:

1. Non-parameterized
2. Parameterized
3. Copy Constructor

**Constructor Overloading**:
Multiple constructors in a class with different parameters (example of Polymorphism).

---

## Copy Constructor

* A special constructor that copies values from one object to another.
* C++ automatically creates a default one, but you can define your own.

```cpp
Teacher T2("Ali", "IT", "CS", 85000);
Teacher T3(T2);  // Copy constructor used
```

---

## This Pointer

* `this` is a special pointer that points to the current object.
* `this->prop` means: this object's property.

**Example:**

```cpp
this->salary = sal;
// Equivalent to:
(*this).salary = sal;
```

---

## Shallow and Deep Copy

* **Shallow Copy**: Copies member values. If there are pointers, both objects share same memory.
* **Deep Copy**: Copies member values and allocates separate memory for dynamic members.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    // Constructor
    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& obj) {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    // Destructor
    ~Student() {
        delete cgpaPtr;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Husnain", 3.33);
    Student s2(s1);  // Deep Copy

    cout << "--- Before modifying s2.cgpaPtr ---" << endl;
    s1.getInfo();
    s2.getInfo();

    *(s2.cgpaPtr) = 3.4;

    cout << "--- After modifying s2.cgpaPtr ---" << endl;
    s1.getInfo();
    s2.getInfo();

    return 0;
}
```

---

## Destructor

* A **destructor** is called automatically when the object goes out of scope or is deleted.
* It releases memory/resources used by the object.

---

## Inheritance

* Allows a class to inherit properties and methods of another class.
* **Benefit**: Code reusability.

```cpp
#include<iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {}
};

class Student : public Person {
public:
    string program;

    void getInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nProgram: " << program;
    }
};

int main() {
    Student s1;
    s1.name = "Husnain";
    s1.age = 23;
    s1.program = "IT";
    s1.getInfo();
    return 0;
}
```

### Types of Inheritance:

1. Single Level
2. Multi-Level
3. Multiple (multiple parents)
4. Hierarchical (multiple children)
5. Hybrid

---

## Polymorphism

* Polymorphism allows different behavior in different contexts.

### 1. Compile-time Polymorphism (Function Overloading)

```cpp
#include<iostream>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "Value of x: " << x;
    }
    void show(char ch) {
        cout << "Value of x: " << ch;
    }
};

int main() {
    Print p1;
    p1.show('H');
    return 0;
}
```

---

### 2. Run-time Polymorphism (Dynamic Polymorphism)

```cpp
#include<iostream>
using namespace std;

class Parent {
public:
    void show() {
        cout << "Parent Constructor";
    }
    virtual void hello() {
        cout << "Hello from parent";
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "Child Constructor";
    }
    void hello() override {
        cout << "Hello from child";
    }
};

int main() {
    Child c1;
    c1.hello();
    return 0;
}
```

---

## Abstraction

* Hides unnecessary details, shows only essential features.
* Done using **abstract classes** (at least one pure virtual function).
* **Abstract classes cannot be instantiated.**

---

## Static Keyword

### Static Variables

* **Inside function**: Remains in memory between function calls.
* **Inside class**: Shared by all objects of the class.

```cpp
#include<iostream>
using namespace std;

void function() {
    int x = 0;
    cout << "Value of x: " << x << "\n";
    x++;
}

void function_two() {
    static int x = 0;
    cout << "Value of x: " << x << "\n";
    x++;
}

int main() {
    function();
    function();
    function();

    cout << endl;

    function_two();
    function_two();
    function_two();

    return 0;
}
```

### Static Objects

* Created only once.
* Retained between function calls.

