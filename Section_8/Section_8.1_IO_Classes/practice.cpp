#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/*  in order to support wide character types, each library defines a set of types and objects that manipulate wchar_t - prefixed with a w
    example. wcin, wcout, wifstream, wofstream, etc.

*/

// we cannot copy of assign objects of the IO types
ofstream out1, out2;
// out1 = out2;                 error: cannot assign stream objects
// ofstream print(ofstream);    error: can't initialize the ofstream parameter
// out2 = print(out2);          error: cannot copy stream objects

istream &process_input(istream &is) { return is; };




/*  MANAGING THE OUTPUT BUFFER

    each output stream manages a bnuffer, which it uses to hold the data that the program reads and write.
        ex. os << "please enter a value: ";
    using a buffer allows the operating system to combine several output operations from our program into a single,
        system-level write. because writing can be time-consuming, letting the operating system
        combine several output operations into a single write can provide an important performance boost


    there are several conditions that cause the buffer to be flushed - to be written - to the actual output device or file

    - the return completes normally. all output buffers are flushed as part of the return from main
    - at some indeterminate time, the buffer can become full, in which case, it will be flushed before writing next value
    - we can flush buffer explicitly using a manipulator such as endl;
    - we can use the unitbuf manipulator to set the stream's internal state to empty the buffer after each output operation
        by default, unitbuf is set for cerr, so that writes to cerr are flushed immediately;
    - an output stream might be tied to another stream. in this case, the bugger of the tied stream is flushed whenever the tied stream is read
        or written. by default, cin and cerr are both tied to cout. hence, reading cin or writting to cerr flushed the buffer in cout


*/

int main()
{
    // remember the current state of cin
    auto old_state = cin.rdstate();         // remember the current state of cin
    cin.clear();                            // make cin valid
    process_input(cin);                     // use cin;
    if (cin.good()) {
        //cout << "True" <<endl;
    } else {
        //cout << "False" <<endl;
    }
    cin.setstate(old_state);                // now reset cin to its old state;

    // the following turns off failbit and badbit, but all other bits unchanged
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);


    // FLUSHING THE OUTPUT BUFFER
    cout << "hello world!" <<endl;              // writes hi and a newline, then flushes the buffer
    cout << "hello world!" <<std::flush;             // writes hi, then flushes the buffer, adds no data
    cout << "hello world!" <<std::ends;               // writes hi and a null, then flushes the buffer

    /*      **NOTE**
        output buffers are NOT flushed if the program terminates abnormally. when a program crashes, 
        it is likely that the data the progrom wrote may be sitting in an output buffer waiting to be printed.

        when you debug a program that has crashed, it is essential to make sure that any output you think should have been written
        was actually flushed. countless hours of programmer time have been wasted tracking through code that appeared not to have
        executed, when in fact the buffer had not been flushed and the output was pending when the program crashed
    */

    // THE UNITBUFFER MANIPULATOR
    cout << std::unitbuf;               // all writes will be flushed immediately.
    cout << std::nounitbuf;             // returns to normal buffering

    /* when an input stream is tied to an output stream, any attempt to read the input stream will 
        first flush the buffer associated with the output stream.

        the library tied cout to cin, so the statement:
            cin >> ival;
        causes the buffer associated with cout to be flushed
    */


   /*   MANUALLY TYING INPUT AND OUTPUT STREAMS TOGETHER

        by default, the library ties cin and cout. But, if we were to manually do it, it'd look like this
        cin.tie(&cout);

        additionally, we can tie cin to cerr, but probably not the best idea.
        cin.tie(&cerr);


        **TO UNTIE SOMETHING, WE PASS A nullptr**
        cin.tie(nullptr);
                            this unties cin and cout from eachother

   */


    return 0;
}
