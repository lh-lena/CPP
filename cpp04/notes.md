
CPP Module 04

Subtype polymorphism, abstract classes, interfaces


 * https://www.geeksforgeeks.org/cpp-polymorphism/?ref=lbp
 * 
 * Base Class: The class from which other classes inherit.
 * Derived Class: A class that inherits from the base class.
 * Virtual Functions: Functions in the base class that can be overridden
 *  in derived classes to provide specific implementations.
 * Pure Virtual Functions: Virtual functions with no implementation in the base class,
 *  making the base class abstract.
 * Virtual Destructors: Ensure that the destructor of the derived class is called 
 * when an object is deleted through a base class pointer.
 * 
 * virtual void makeSound() const = 0; // Pure virtual function | in class Animal
 * 
Types of Polymorphism:
- Compile-time Polymorphism
    -- This type of polymorphism is achieved by function overloading or operator overloading.
- Runtime Polymorphism
    -- Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
 * 
 * 
 
class GFG_Child : public GFG_Base
// Create a reference of class GFG_Base
    GFG_Base* base;
 
    GFG_Child child;
 
    base = &child;
 
    // This will call the virtual function
    base->GFG_Base::display();
 
    // this will call the non-virtual function
    base->print();
