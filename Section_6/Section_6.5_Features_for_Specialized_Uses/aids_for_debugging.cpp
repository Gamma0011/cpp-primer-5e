#include <iostream>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// the assert Preprocessor Macro
/* a preprocessor macro is a preprocessor variable that acts somewhat like an inline function
   the assert macro takes a single expression, which is uses as a condition: assert(expr);

    If the expression is false == 0, then assert writes a message and terminates the program.
    If the expression is true == 1, then assert does nothing

    the assert macro is defined in the cassert header #include <cassert>
    ** since assert is handled by the preprocessor, no library or using declaration is required.
        using std::assert (NOT NEEDED)
        std::assert (WRONG) | assert (RIGHT)


    The assert macro is often used to check for conditions that "cannot happen". For example, a program that does some manipulation
    of input text might know that all the words it is given are always longer than the threshold.
    As a result, the program might contain a startment such as: assert(word.size() > threshold);
*/

// the NDEBUG Preprocessor Variable
/* the behavior of assert depends on the status of the preprocessor variable named NDEBIG. 
    if NDEBUG is defined, assert does nothing. By default, NDEBUG is not defined, so, by default, assert performs a run-time check

    we can turn off debugging by providing a #define to define NDEBUG. alternatively, most compiles provide a command-line option
    that lets us define pre-processor variables

    $ CC -D NDEBUG main.cpp #use /D with the Microsoft compiler
    the command-line option has the same effect as writing #define NDEBUG
*/

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
    // __func__ is a local static defined by the compiler that holds the function's name
    std::cerr << __func__ << ": array size is " << size <<endl;
    #endif
}

/* the C++ compiler defines __func__ standard in every function. __func__ is saved as a static char array -- static char[];

    the preprocessor also defines 3 other names that can be useful in debugging

    __FILE__        string literal containing the name of the file
    __LINE__        integer literal containing the current line number
    __TIME__        string literal containing the time the file was compiler
    __DATE__        string literal containing the date the file was compiled  
*/

// we might use these constants to report additional info in error messages
void preproPractice(const string &word)
{
    int threshold = 10;
    if (word.size() < threshold) {
        std::cerr << "Error: " << __FILE__
                  << " : in the function " << __func__
                  << "       Compiled on " << __DATE__
                  << " at " << __TIME__ <<endl
                  << "        Word read was \"" << word
                  << "\": Length was too short" <<endl;
    } else {
        cout << "Success!" <<endl;
    }


}


int main()
{
    int iarr[] = {0,1,2,3};
    print(iarr, 3);

    preproPractice("test");

    return 0;
}
