## Encapsulation
 
> **Wrapping data (attributes) and methods together inside a class, while hiding internal implementation details.**
 
The process of creating a class and writing methods & attributes inside it IS encapsulation. It also enforces **data hiding** (private members can't be accessed directly from outside).
 
```cpp
class User {
    int id;           // hidden from outside
    string password;  // hidden from outside
public:
    string username;  // publicly accessible
 
    // Controlled access via getter/setter
    string getPassword() { return password; }
    void setPassword(string pwd) { password = pwd; }
    void deactivate() { cout << "Account deactivated!\n"; }
};
```
 