
###                        CPP Module 06


# conversions using the new C++ casting operators introduced in C++98: 
- static_cast, 
- dynamic_cast, 
- const_cast, 
- reinterpret_cast. 

Each of these casts serves a specific purpose and provides better type safety and clarity compared to C-style casting.

## 1. static_cast

static_cast is used for conversions between related types, such as converting between pointers to base and derived classes, or performing well-defined type conversions like int to float.

Example: Base to Derived Class Conversion


    int main() {
        Base* b = new Derived;
        Derived* d = static_cast<Derived*>(b); // static_cast from Base* to Derived*

        d->show(); // Calls Derived class show()

        delete b;
        return 0;
    }

Explanation: static_cast is used to cast a Base* to a Derived*. This cast is safe because b actually points to a Derived object.

## 2. dynamic_cast

dynamic_cast is used for safe downcasting in polymorphic hierarchies. It performs a runtime check to ensure the cast is valid and returns nullptr if it isn't.

Example: Safe Downcasting with Polymorphism

    int main() {
        Base* b = new Derived;
        Derived* d = dynamic_cast<Derived*>(b); // dynamic_cast from Base* to Derived*

        if (d) {
            d->show(); // Calls Derived class show()
        } else {
            std::cout << "Invalid cast" << std::endl;
        }

        delete b;
        return 0;
    }

Explanation: dynamic_cast performs a runtime check to ensure b can be safely cast to a Derived*. If the cast is invalid, d is set to nullptr.

dynamic_cast is specifically used for safely downcasting pointers or references to polymorphic classes (i.e., classes with virtual functions) in C++.

## 3. const_cast
const_cast is used to add or remove the const qualifier from a variable. This is useful when interfacing with legacy code or APIs that don't use const correctly.

Example: Removing const Qualifier

    void printNonConst(int* p) {
        *p = 10;
        std::cout << *p << std::endl;
    }

    int main() {
        const int i = 42;
        int* p = const_cast<int*>(&i); // const_cast to remove const qualifier

        printNonConst(p); // Modifies the value of i

        std::cout << "Modified i: " << i << std::endl;

        return 0;
    }

Explanation: const_cast is used to remove the const qualifier from i. This allows printNonConst to modify i, although this is generally unsafe and should be avoided.

## 4. reinterpret_cast

reinterpret_cast is used for low-level, potentially unsafe conversions, such as converting between unrelated pointer types or casting between pointer and integer types.

Example: Converting Pointer to Integer
    #include <cstdint>
    int main() {
        int i = 42;
        int* p = &i;
        std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(p); // reinterpret_cast from int* to uintptr_t

        std::cout << "Address: " << addr << std::endl;

        int* p2 = reinterpret_cast<int*>(addr); // reinterpret_cast from uintptr_t back to int*
        std::cout << "Value: " << *p2 << std::endl;

        return 0;
    }

Explanation: reinterpret_cast is used to convert a pointer to an integer type (uintptr_t), and then back to the original pointer type without losing information. 
- Useful in low-level programming tasks, such as implementing memory allocators or when dealing with hardware-related programming.
- Helps in type-safe pointer manipulations where converting between pointers and integers is necessary.
# Characteristics uintptr_t:
- It's an unsigned integer type, which means it can only hold non-negative values.
- Its size is platform-dependent but guaranteed to be at least as large as the size of a pointer.
- Often used in systems programming, such as writing device drivers, where direct memory access and manipulation are common.


## Summary
    - static_cast is used for well-defined conversions between related types.
    - dynamic_cast is used for safe downcasting in polymorphic class hierarchies.
    - const_cast is used to add or remove the const qualifier.
    - reinterpret_cast is used for low-level, potentially unsafe conversions between unrelated types.

    These casting operators provide more control and type safety compared to C-style casts, making them preferable in most situations.

* stringstream 
- https://www.geeksforgeeks.org/stringstream-c-applications/
Examples:
1. Count the number of words in a string
2. Print frequencies of individual words in a string
3. Convert Integer to string

* limits:
https://en.cppreference.com/w/cpp/language/floating_literal
https://en.cppreference.com/w/cpp/language/integer_literal
https://en.cppreference.com/w/cpp/types/numeric_limits
https://www.geeksforgeeks.org/stdnumeric_limitsmax-and-stdnumeric_limitsmin-in-c/

