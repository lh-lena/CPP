
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


** abstract classes
    https://www.geeksforgeeks.org/abstraction-in-cpp/?ref=lbp
    https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c

    An abstract class is a class that is designed to be specifically used as a base class. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier (= 0) in the declaration of a virtual member function in the class declaration.

    class AB {
public:
  virtual void f() = 0;
};

An abstract class inherited the pure virtual function from base class.

Note that you can derive an abstract class from a nonabstract class, and you can override a non-pure virtual function with a pure virtual function.

You can call member functions from a constructor or destructor of an abstract class. However, the results of calling (directly or indirectly) a pure virtual function from its constructor are undefined. The following example demonstrates this:

struct A {
  A() {
    direct();
    indirect();
  }
  virtual void direct() = 0;
  virtual void indirect() { direct(); }
};

   - https://en.cppreference.com/w/cpp/language/abstract_class

A pure virtual function is a virtual function whose declarator has the following syntax:

declarator virt-specifier ﻿(optional) = 0		
Here the sequence = 0 is known as pure-specifier, and appears either immediately after the declarator or after the optional virt-specifier (override or final).

pure-specifier cannot appear in a member function definition or friend declaration.

example 01
struct Base
{
    virtual int g();
    virtual ~Base() {}
};

struct A : Base
{
    // OK: declares three member virtual functions, two of them pure
    virtual int f() = 0, g() override = 0, h();
 
    // OK: destructor can be pure too
    ~A() = 0;
 
    // Error: pure-specifier on a function definition
    virtual int b() = 0 {}
};

An abstract class is a class that either defines or inherits at least one function for which the final overrider is pure virtual.

example 02
struct Abstract
{
    virtual void f() = 0;  // pure virtual
}; // "Abstract" is abstract
 
struct Concrete : Abstract
{
    void f() override {}   // non-pure virtual
    virtual void g();      // non-pure virtual
}; // "Concrete" is non-abstract
 
struct Abstract2 : Concrete
{
    void g() override = 0; // pure virtual overrider
}; // "Abstract2" is abstract
 
int main()
{
    // Abstract a;   // Error: abstract class
    Concrete b;      // OK
    Abstract& a = b; // OK to reference abstract base
    a.f();           // virtual dispatch to Concrete::f()
    // Abstract2 a2; // Error: abstract class (final overrider of g() is pure)
}

the default Animal class should not be instantiable:
 - https://stackoverflow.com/questions/19090328/protected-constructor-to-make-base-class-not-instantiable

 ** Exercise 03: Interface & recap
 
 In C++98, interfaces can be implemented using pure abstract classes. These classes contain only pure virtual functions and no data members or non-virtual member functions. They define a contract that derived classes must fulfill, similar to interfaces in other programming languages. Below is an explanation and an example of how to implement and use pure abstract classes as interfaces in C++98.

 In other programming languages, interfaces are a way to define a contract that classes must follow. An interface specifies what methods a class must implement, but it does not provide the method implementations. This ensures that any class that implements the interface will have certain methods available, promoting consistency and enabling polymorphism.