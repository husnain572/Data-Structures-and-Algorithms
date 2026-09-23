## Copy Constructor
 
A **copy constructor** creates a new object as a copy of an existing object.
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Car {
public:
    string name;
    string color;
 
    // Parameterized Constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
    }
 
    // Copy Constructor
    Car(const Car& original) {
        cout << "Copy constructor called!\n";
        name  = original.name;
        color = original.color;
    }
};
 
int main() {
    Car c1("Suzuki", "White");
    Car c2(c1);   // Copy constructor invoked
 
    cout << c2.name << " - " << c2.color << endl;
    return 0;
}
```
 
**Output:**
```
Copy constructor called!
Suzuki - White
```
 
