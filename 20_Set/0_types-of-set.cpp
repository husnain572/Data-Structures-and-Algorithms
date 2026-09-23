/*
Unordered Set (unordered_set):
- Stores values in an unordered fashion.
- Stores unique values.
- Values cannot be modified once inserted.
- Time complexity (on average) for insertion, deletion, and search is O(1) due to hashing.

Member Functions of unordered_set
1. insert()
   - Single element: O(1) (average case), O(N) (worst case).
   - Multiple elements: O(N) (average case, where N is the number of elements being inserted), O(n * (N + 1)) (worst case).

2. Deletion (erase())
   - erase(value)
   - erase(iterator)
   - erase(start_iterator, end_iterator)
   - Time complexity:
     - O(1) (average case).
     - O(N) (worst case).

3. find(value)
   - O(1) (average case).
   - O(N) (worst case).

4. count(value)
   - O(1) (average case).
   - O(N) (worst case).
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> set1 = {3, 1, 5, 2};
    
    for (auto itr : set1) {
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}


/*
Multiset (multiset)
- Stores duplicate values.
- Stores values in a sorted order (ascending by default).
- Values cannot be modified after insertion.

Member Functions of multiset
1. insert()
   - O(log N) time complexity.

2. Deletion (erase())
   - erase(value) → O(log N)
   - erase(position)
   - erase(start_iterator, end_iterator) → O(N)

3. find(value)
   - O(log N)
   - Returns an iterator pointing to the element if found, else returns end().

4. count(value)
   - Returns the number of occurrences.
   - O(K + log N), where K is the number of occurrences.

5. lower_bound(value)
   - Returns an iterator pointing to the first occurrence of the value.
   - If not found, returns the iterator to the next greater value.
   - O(log N) time complexity.

6. upper_bound(value)
   - Returns an iterator pointing to the next greater value.
   - O(log N) time complexity.
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> set1 = {3, 1, 5, 2, 2};
    
    for (auto itr : set1) {
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}
/*
Unordered Multiset (unordered_multiset)
- Stores duplicate values.
- Stores values in an unordered manner.
- Values cannot be modified after insertion.

Member Functions of unordered_multiset
1. insert()
   - Single element: O(1) (average case), O(N) (worst case).
   - Multiple elements: O(n) (average case), O(n * (N + 1)) (worst case).

2. Deletion (erase())
   - erase(value)
   - erase(iterator)
   - erase(start_iterator, end_iterator)
   - Time complexity:
     - O(1) (average case).
     - O(N) (worst case).

3. find(value)
   - O(1) (average case).
   - O(N) (worst case).

4. count(value)
   - O(n) (average case), where n is the number of occurrences.
   - O(N) (worst case), where N is the total size.

Example Code
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> set1 = {3, 1, 5, 2, 2};
    
    for (auto itr : set1) {
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}
