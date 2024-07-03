
#include "whatever.hpp"
#include <iostream>
// using namespace std;

// int main( void )
// {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }

/**
 * Using ::swap(a, b); in template functions
 *  is a way to manage function lookup explicitly, 
 * ensuring that the intended swap function is called, 
 * avoiding potential issues with ADL, 
 * and providing a clear and unambiguous 
 * resolution path for the swap function.
 * 
*/