#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <memory>
#include <new>

/*
    e12.23  - write a program to concatentate two string literals, putting the result in a dynamically allocated array of char. write a program to concatentate two library
                strings that have the same value as the literals used in the first program

    e12.24  - write a program that rads a string from the std::cin into a dynamically allocated character array. Describe how your program handles varying size inputs. Test
                by giving it a string of data that is longer than the array size allocated.

                    The program handles varying size inputs without too much an issue since it's calculating the length and incrementing both the position for the dynamically-allocated
                     array and the character position in the string properly. Inputting more characters than allotted won't write any more inputs to the array since the cnt is
                     past the element amount. However, one thing that is weird, is that characters go missing sometimes (print out only 16-18 instead of 20). Entering exactly 20 characters
                     doesn't cause much of an issue.
    
    e12.25  - Given the following new expression, how would you delete pa?
                    int *pa = new int[10];
                    
                    delete [] pa;

    e12.26  - rewrite the program on pg 481 using an allocator

*/

void e1223sl() {
    const char* a = "Hello";
    const char* b = "World";
    char s[std::strlen(a) + std::strlen(b)];
    std::strcpy(s, a);
    std::strcat(s, b);

    std::unique_ptr<char[]> c(new char[std::strlen(s)]);

    for (std::size_t i = 0, sz = std::strlen(s); i != sz ; ++i ) { c[i] = s[i]; }      // add char to dynamically-allocated array c
    for (std::size_t i = 0, sz = std::strlen(s); i != sz ; ++i ) { std::cout << c[i];}
    c.release();                                                                // released allocated memory
    std::cout << "\nReleased from memory." <<std::endl;
}

void e1223ls() {
    std::string a("Hello"), b("World");
    std::string s = a + b;

    std::unique_ptr<char[]> c(new char[s.length()]);
    for (std::size_t i = 0, sz = s.length() ; i != sz ; ++i) { c[i] = s[i]; }               // write char elements to c
    for (std::size_t i = 0, sz = s.length() ; i != sz ; ++i) { std::cout << c[i];}          // read char elements from c

    c.release();                                                                            // deallocate memory
    std::cout << "\nMemory Released." <<std::endl;
}

void e1224() {
    std::size_t cnt = 0;
    std::unique_ptr<char[]> cptr(new char[20]);

    for (std::string s ; std::cin >> s && s != "@q"; ++cnt) {
        for (std::size_t length = s.length(), i = 0; i != length ; ++cnt, ++i) { cptr[cnt] = s[i]; }
    }

    for (std::size_t i = 0 ; i != 20 ; ++i) { std::cout << cptr[i]; }
    
    cptr.release();
    std::cout << "\nPointer Released." << std::endl;

}

void e1226(int n) {
    std::allocator<std::string> salloc;
    auto const p = salloc.allocate(n);
    auto q = p;                         // iterator

    for (std::string s ; std::cin >> s && q != (p + n) ; ++q) { salloc.construct(q, s); }

    while (q != p) {
        std::cout << *--q <<std::endl;   // dereference and iterate backwards through memory
        salloc.destroy(q);               // destroy object to which iterator q points
    }

    salloc.deallocate(p, n);            // deallocate memory used by p
}

int main()
{
    //e1223sl();
    //e1223ls();
    //e1224();
    e1226(10);

    return 0;
}