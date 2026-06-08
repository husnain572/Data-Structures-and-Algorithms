
## Shallow Copy vs Deep Copy
 
### The Problem
 
When a class has a **pointer** to dynamically allocated memory, the compiler's default copy copies the **pointer address** — not the data it points to. Both objects then share the same memory (shallow copy), which causes bugs.
 
```
Shallow Copy:          Deep Copy:
c1.mileage ──┐         c1.mileage ──► [12]
             ▼                         
            [12]        c2.mileage ──► [12]  ← separate memory
             ▲
c3.mileage ──┘  ← same address! Dangerous!
```
 
### Deep Copy Example
 
```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Car {
public:
    string name;
    string color;
    int* mileage;   // pointer to dynamic memory
 
    // Constructor
    Car(string name, string color, int mil = 12) {
        this->name  = name;
        this->color = color;
        mileage     = new int;  // allocate on heap
        *mileage    = mil;
    }
 
    // Deep Copy Constructor — allocates NEW memory
    Car(const Car& original) {
        cout << "Deep Copy Constructor Called\n";
        name    = original.name;
        color   = original.color;
        mileage = new int;           // NEW allocation
        *mileage = *original.mileage; // copy VALUE, not address
    }
 
    // Shallow Copy (manual static method for demonstration)
    static Car shallowCopy(const Car& original) {
        Car temp(original.name, original.color);
        delete temp.mileage;           // free temp's own memory
        temp.mileage = original.mileage; // point to SAME address
        return temp;
    }
 
    // Destructor — frees heap memory when object is destroyed
    ~Car() {
        if (mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};
 
int main() {
    Car c1("Suzuki", "White", 12);
    Car c2(c1);                      // Deep copy
    Car c3 = Car::shallowCopy(c1);   // Shallow copy
 
    cout << "\nBefore any change:\n";
    cout << "c1: " << *c1.mileage << ", c2: " << *c2.mileage
         << ", c3: " << *c3.mileage << endl;
 
    *c2.mileage = 20;
    cout << "\nAfter changing c2 (Deep Copy — only c2 changes):\n";
    cout << "c1: " << *c1.mileage << ", c2: " << *c2.mileage
         << ", c3: " << *c3.mileage << endl;
 
    *c3.mileage = 30;
    cout << "\nAfter changing c3 (Shallow Copy — c1 also changes!):\n";
    cout << "c1: " << *c1.mileage << ", c2: " << *c2.mileage
         << ", c3: " << *c3.mileage << endl;
 
    return 0;
}
```
 
**Output:**
```
Deep Copy Constructor Called
 
Before any change:
c1: 12, c2: 12, c3: 12
 
After changing c2 (Deep Copy — only c2 changes):
c1: 12, c2: 20, c3: 12
 
After changing c3 (Shallow Copy — c1 also changes!):
c1: 30, c2: 20, c3: 30
```
 
| | Shallow Copy | Deep Copy |
|--|--|--|
| Memory | Shares same address | New memory allocated |
| Independence | Changes in one affect the other | Fully independent |
| Default behavior | Compiler default | Must define manually |
| When to use | Simple types (int, string) | When class has pointer members |
 