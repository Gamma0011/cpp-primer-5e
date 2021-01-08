#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <new>
#include <map>
#include <set>


/*
    | DESIGN OF THE QUERY PROGRAM |
        A good way to start the design of a program is to list the program's operations. Knowing what operations we need can help us see what data structures we'll need.
         Our tasks for the text-query program:
            - When it reads the input, the program must remember the line(s) in which each word appears. The program will need to read the input a line at a time
                and break up the lines from the input into separate words
            - When it generators the output:
                - The program must be able to fetch the line numbers associated with the given word.
                - The line numbers must appear in ascending order with no duplicates
                - The program must be able to print the text appearing in the input file at a given line number.
            
            - These requirements can be met neatly by using various library facilities:
                - Vector<string> to store a copy of input file. Each line in the input file will be an element in the vector.
                    When we want to print a line, we can fetch the line using its line number as an index.
                - istringstream to break each line into words
                - set to hold line numbers on which each word in the input appears. Using set guarantees that each line will appear only
                    once and that the line numbers will be stored in ascending order
                - We'll use a map to associate each word with the set of line numbers on which the word appears. Using a map will let us fetch the
                    set for any given word.
                - Shared_ptrs will also be used.

*/

int main()
{


    return 0;
}