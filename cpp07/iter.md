
##### CPP Modul 07
#### C++ templates

### Requirements

1. **Template Function `iter`**:
   - Takes an array of elements of type `T`.
   - Takes a length of the array.
   - Takes a function that operates on elements of type `T`.

### Solution

Instead of trying to pass a template function directly, you can use one of the following methods:

1. **Use Function Pointers for Specific Instantiations**
2. **Use `std::function` for Flexibility**
3. **Use Functors (Function Objects)**

#### Method 1: Function Pointers for Specific Instantiations

You can pass a function pointer to a specific instantiation of the function.

```cpp
#include <iostream>

// A sample function to be passed
template <typename T>
void printElement(T element) {
    std::cout << element << std::endl;
}

// The template function `iter`
template <typename T>
void iter(T* arr, T length, void (*function)(T)) {
    for (T i = 0; i < length; ++i) {
        function(arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printElement<int>);
    return 0;
}
```

#### Method 2: Using `std::function`

You can use `std::function` to pass any callable object, including specific instantiations of template functions.

```cpp
#include <iostream>
#include <functional>

// A sample function to be passed
template <typename T>
void printElement(T element) {
    std::cout << element << std::endl;
}

// The template function `iter`
template <typename T>
void iter(T* arr, T length, std::function<void(T)> function) {
    for (T i = 0; i < length; ++i) {
        function(arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printElement<int>);
    return 0;
}
```

#### Method 3: Using Functors (Function Objects)

You can create a functor (a class with an `operator()` method) to encapsulate the template function.

```cpp
#include <iostream>

// A functor that wraps the template function
template <typename T>
struct PrintElement {
    void operator()(T element) const {
        std::cout << element << std::endl;
    }
};

// The template function `iter`
template <typename T, typename Func>
void iter(T* arr, T length, Func function) {
    for (T i = 0; i < length; ++i) {
        function(arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, PrintElement<int>());
    return 0;
}
```

### Summary

To pass a template function as a parameter to another template function in C++, you need to use specific instantiations, `std::function`, or functors. The provided examples show how to use these methods to achieve the desired functionality in a clean and efficient manner.