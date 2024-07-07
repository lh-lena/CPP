### C++ - Module 08
## Templated containers, iterators, algorithms


#### Containers in C++ STL (Standard Template Library)
https://www.geeksforgeeks.org/containers-cpp-stl/?ref=lbp 

### An Introduction to "Iterator Traits"
https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits

## Sequence Containers (vector, deque, list) -   store objects of the same type in a linear arrangement
https://en.cppreference.com/w/cpp/named_req/SequenceContainer


* A Container is an object used to store other objects and taking care of the management of the memory used by the objects it contains.

- ex00 You don’t have to handle associative containers.
- Associative containers 

Associative containers in C++98 are a group of standard template library (STL) containers that store elements in a way that allows fast retrieval using keys. They are based on the associative array abstract data type and use different underlying data structures to provide efficient lookup, insertion, and deletion operations.

The four main associative containers in C++98 are:

1. **`std::set`**: 
   - Stores unique elements in a sorted order.
   - Allows fast lookup, insertion, and deletion of elements.
   - Underlying data structure: typically a balanced binary search tree (like a red-black tree).

2. **`std::multiset`**:
   - Similar to `std::set`, but allows duplicate elements.
   - Elements are stored in a sorted order.
   - Underlying data structure: typically a balanced binary search tree.

3. **`std::map`**:
   - Stores key-value pairs (associative array) with unique keys in a sorted order.
   - Allows fast lookup, insertion, and deletion by key.
   - Underlying data structure: typically a balanced binary search tree.

4. **`std::multimap`**:
   - Similar to `std::map`, but allows multiple elements with the same key.
   - Key-value pairs are stored in a sorted order.
   - Underlying data structure: typically a balanced binary search tree.

### Characteristics of Associative Containers

- **Ordered**: Elements are stored in a specific order defined by a comparison function. By default, this is the `<` operator for the element type or key type.
- **Fast Lookup**: They provide logarithmic time complexity (O(log n)) for search, insertion, and deletion operations.
- **Iterator Validity**: Iterators to elements in associative containers remain valid even after insertions and deletions, except for the element being erased.

### Common Operations

- **Insertion**: `insert()`, `emplace()`
- **Deletion**: `erase()`
- **Lookup**: `find()`, `count()`
- **Traversal**: Iterators (begin, end)

### Example Usage

Here's a simple example demonstrating the usage of `std::set` and `std::map`:

```cpp
#include <iostream>
#include <set>
#include <map>

int main() {
    // Example of std::set
    std::set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(20); // Duplicate, will not be added

    std::cout << "Elements in set: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example of std::map
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    std::cout << "Elements in map: ";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, the `std::set` ensures that all elements are unique and stored in sorted order, while the `std::map` associates integer keys with string values, also maintaining sorted order of the keys.



- https://cplusplus.com/reference/algorithm/generate/
- https://cplusplus.com/reference/vector/vector/assign/


