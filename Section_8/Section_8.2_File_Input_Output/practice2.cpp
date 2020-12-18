#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/* FILE MODES

    By default, when we open an ofstream, the contents of th file are discarded. The only way to prevent
    an ofstream from emptying the given file is to specify app:

    // file1 is truncated in each of these cases
    std::ofstream out("file1");                                                     // out and trunc are implicit
    std::ofstream out2("file1", std::ostream::out);                                 // trunc is implicit
    std::ofstream out3("file1", std::ofstream::out | std::ofstream::trunc);          // both are explicit

    // to preserve the file's content, we must explicitly specify app mode
    std::ofstream app("file1", std::ofstream::app);                                 // out is implicit
    std::ofstream app("file1", std::ofstream::out | std::ofstream::app);            // both are explicit

    **NOTE** the only way to preserve the exisiting data in a file opened by an ofstream is to specify app or in mode explicitly
*/



// when we define an empty file stream object, we can subsequently associate that object with a file by calling open.
    ifstream in(ifile);         // construct an ifstream and open the given file;
    ofstream out;               // output file stream that is not associated with any file
    out.open(ifile + ".copy");  // open the specified file

    // if a call to open fails, failbit is set. because a call to open might fail, it is a good idea to verify open succeeded
    if (out) { };               // check the open succeeded, if opened, we can use the file
    // calling open on a file stream already open will fail and set failbit. to associate a file stream with a different file, 
    //  we musrt first close the exisiting file
    in.close();                 // close the file
    in.open(ifile + "2");       // open another file; if succeeded, state is good() = true

int main()
{
    // consider a program whose main function takes a list of files it should process. the loop might look something like this

    // for each file passed to the program
    for (auto p = argv + 1; p != argv; ++p) {
        std::ifstream input(*p);                // create input and open file
        if (input) {                            // if the file is ok, "process" this file
            process(input);
        } else {
            std::cerr << "couldn't open: " << string(*p);
        }   
    }                                           // input goes out of scope and is destroyed on each iteration
    // **NOTE** when an fstream object is destroyed, close is called automatically

    return 0;
}