
## Constructors
 
A **constructor** is a special method that is:
- Automatically called when an object is created
- Has the **same name** as the class
- Has **no return type** (not even `void`)
- Used to **initialize** object properties
### Non-Parameterized Constructor (Default)
 
```cpp
class Car {
public:
    Car() {
        cout << "Car object created!\n";
    }
};
 
int main() {
    Car c1; // Constructor called automatically
    return 0;
}
```
 
### Parameterized Constructor
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Car {
    string name;
    string color;
 
public:
    // Parameterized Constructor
    Car(string name, string color) {
        this->name = name;   // 'this' points to current object
        this->color = color;
    }
 
    string getName()  { return name; }
    string getColor() { return color; }
 
    void start() { cout << name << " has started.\n"; }
    void stop()  { cout << name << " has stopped.\n"; }
};
 
int main() {
    Car c1("Suzuki", "White");
    Car c2("Toyota", "Black");
 
    cout << c1.getName() << " - " << c1.getColor() << endl;
    cout << c2.getName() << " - " << c2.getColor() << endl;
 
    c1.start();
    c2.stop();
 
    return 0;
}
```
 
**Output:**
```
Suzuki - White
Toyota - Black
Suzuki has started.
Toyota has stopped.
```
 
### The `this` Pointer
 
`this` is a special pointer in C++ that always points to the **current object**.
 
```cpp
this->name = name;
// is equivalent to:
(*this).name = name;
```
 
It's used to disambiguate when a parameter name is the same as a member variable.
 
### Constructor Overloading
 
You can have **multiple constructors** with the same name but different parameters.
 
```cpp
class Car {
public:
    string name;
    string color;
 
    Car() {                           // Default
        name = "Unknown";
        color = "Unknown";
    }
 
    Car(string name, string color) {  // Parameterized
        this->name = name;
        this->color = color;
    }
};
```