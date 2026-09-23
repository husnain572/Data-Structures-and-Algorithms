## Getters and Setters
 
Used when we want **controlled access** to private data — instead of making everything public, we provide specific methods to read (get) or modify (set) values.
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Student {
    string name;   // private by default
    float cgpa;    // private by default
 
public:
    // --- Setters ---
    void setName(string nameVal) {
        name = nameVal;
    }
    void setCgpa(float cgpaVal) {
        cgpa = cgpaVal;
    }
 
    // --- Getters ---
    string getName() {
        return name;
    }
    float getCgpa() {
        return cgpa;
    }
 
    // Method using private data
    void getPercentage() {
        cout << (cgpa * 10) << "%" << endl;
    }
};
 
int main() {
    Student s1;
    s1.setName("Husnain");
    s1.setCgpa(3.3);
 
    cout << "Name: " << s1.getName() << endl;
    cout << "CGPA: " << s1.getCgpa() << endl;
    s1.getPercentage();
 
    return 0;
}
```
 
**Output:**
```
Name: Husnain
CGPA: 3.3
33%
```
 
---
## The Four Pillars of OOP
 
```
┌─────────────────────────────────────────────┐
│              Four Pillars of OOP            │
├───────────────┬───────────────┬─────────────┤
│ Encapsulation │  Inheritance  │ Abstraction │
├───────────────┴───────────────┴─────────────┤
│              Polymorphism                   │
└─────────────────────────────────────────────┘
```
 