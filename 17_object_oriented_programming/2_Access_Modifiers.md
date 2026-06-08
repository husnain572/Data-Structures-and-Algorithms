
## Access Modifiers
 
Control who can access data and methods inside a class.
 
| Modifier | Accessible Inside Class | Accessible in Derived Class | Accessible Outside (main) |
|----------|-------------------------|-----------------------------|---------------------------|
| `private` | ✅ Yes | ❌ No | ❌ No |
| `protected` | ✅ Yes | ✅ Yes | ❌ No |
| `public` | ✅ Yes | ✅ Yes | ✅ Yes |
 
> **Note:** By default, members of a `class` are `private`, and members of a `struct` are `public`.
 
---