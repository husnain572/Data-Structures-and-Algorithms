## Inheritance
 
> **When a derived class inherits properties and methods from a base class.**
 
This promotes **code reuse** — you don't rewrite common functionality.
 
```
Base Class ──► Derived Class
```
 
### Access Table in Inheritance
 
| Base Member | Public Inheritance | Protected Inheritance | Private Inheritance |
|-------------|--------------------|-----------------------|---------------------|
| `public` | public | protected | private |
| `protected` | protected | protected | private |
| `private` | ❌ Not accessible | ❌ Not accessible | ❌ Not accessible |
 
### Types of Inheritance
 
```
Single:           Multi-level:        Multiple:
  Animal              Animal           Teacher  Student
    │                   │                  \      /
   Dog               Mammal                 TA
                        │
                       Dog
 
Hierarchical:       Hybrid:
   Animal           A combination of
  / | \             the above types
Bird Fish Mammal
```
 
### Single Inheritance
 
```cpp
#include <iostream>
using namespace std;
 
class Animal {
public:
    void eat()    { cout << "Animal eats\n"; }
    void breath() { cout << "Animal breathes\n"; }
};
 
class Dog : public Animal {  // Dog inherits Animal
public:
    void tailWag() { cout << "Dog wags tail\n"; }
};
 
int main() {
    Dog d1;
    d1.eat();     // inherited from Animal
    d1.breath();  // inherited from Animal
    d1.tailWag(); // Dog's own method
    return 0;
}
```
 
### Multi-level Inheritance
 
```cpp
class Animal { ... };          // Level 1
class Mammal : public Animal { // Level 2
    string bloodType = "warm";
};
class Dog : public Mammal {    // Level 3
    void tailWag() { ... }
};
// Dog has access to Animal + Mammal + its own methods
```
 
### Multiple Inheritance
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Teacher {
public:
    int salary;
    string subject;
};
 
class Student {
public:
    int roll_no;
    float cgpa;
};
 
class TA : public Teacher, public Student {  // inherits both
public:
    string name;
};
 
int main() {
    TA ta1;
    ta1.name    = "Husnain";
    ta1.subject = "C++";
    ta1.cgpa    = 3.33;
 
    cout << ta1.name    << endl;
    cout << ta1.subject << endl;
    cout << ta1.cgpa    << endl;
    return 0;
}
```
 
### Hierarchical Inheritance
 
```cpp
#include <iostream>
using namespace std;
 
class Animal {
public:
    void eat()    { cout << "Eats\n"; }
    void breath() { cout << "Breathes\n"; }
};
 
class Bird : public Animal {
public:
    void fly() { cout << "Flies\n"; }
};
 
class Fish : public Animal {
public:
    void swim() { cout << "Swims\n"; }
};
 
class Mammal : public Animal {
public:
    void walk() { cout << "Walks\n"; }
};
 
int main() {
    Bird b1;
    b1.eat(); b1.breath(); b1.fly();
 
    Fish f1;
    f1.eat(); f1.breath(); f1.swim();
 
    Mammal m1;
    m1.eat(); m1.breath(); m1.walk();
 
    return 0;
}
```
 
---
 
## Practice Problem — User Class
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class User {
    int id;           // private
    string password;  // private
 
public:
    string username;  // public
 
    // Parameterized Constructor
    User(int id) {
        this->id = id;
    }
 
    // Getter
    string getPassword() {
        return password;
    }
 
    // Setter
    void setPassword(string password) {
        this->password = password;
    }
};
 
int main() {
    User u1(100);
    u1.username = "husnainmalikawan";
    u1.setPassword("1234abcd");
 
    cout << "Username : " << u1.username       << "\n";
    cout << "Password : " << u1.getPassword()  << "\n";
 
    return 0;
}
```
 

 
