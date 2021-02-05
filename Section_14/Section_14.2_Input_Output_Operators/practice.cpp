#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"

/*
    || OVERLOADING THE OUTPUT OPERATOR << ||
        The first parameter of an output operator is a reference to a nonconst ostream object: std::ostream&
        Ostream is nonconst because writing to it changes its state and is a reference because we cannot copy an ostream object

        The second parameter ordinarily should be a const& of class type we want to print. This is a const& because we want to avoid
         the overhead of copying and because we don't normally want to change the argument.
        
        To be consistent with other output operators, operator<< normally returns its ostream parameter.
            
            see. std::ostream& operator<<(std::ostream &os, const Sales_data &item);
        
        | OUTPUT OPERATORS USUALLY DO MINIMAL FORMATTING |
            The output operators for the built-in types do little, if any formatting. In particular, they do not print newlines.
             If the operator does print a newline, then users would be unable to print descriptive text along with the object on the same line.
             An output operator that does minimal formatting lets users control the details of their output.
            
            *NOTE* Generally, output operators should print the contents of the object, with minimal formatting. They should not print newlines.

        | IO OPERATORS MUST BE NONMEMBER FUNCTIONS |
            Input and output operators must be ordinary nonmember functions. If they were, the left-hand operand would have to be an 
             object of our class.

             Sales_data data;
             data << cout;          // if operator<< were a member of Sales_data.

            In order for input and output operators to read nonpublic (private) members of class, they must be declared friends.

    || OVERLOADING THE INPUT OPERATOR >> ||
        The first parameter of an input operator is a reference to the stream from which it is to be read: std::istream&
        The second parameter is a reference to the (nonconst) object into which to read.
        The second parameter MUST BE NONCONST and a REFERENCE so that we can read data into this object.

            see. std::istream& operator>>(std::istream &is, Sales_data &item);
        
            Except for the if statement, the definition is similar to out earlier read function. The 'if' statement checks 
            whether the reads were successful. If an IO error occurs, the operator resets its given object to the empty Sales_data.
            This guarantees the object is in a consistent state.

        *NOTE* Input operators MUST deal with the possibility that input might fail; output operators generally don't have to.

        | ERRORS DURING INPUT |
            - A read operator might fail because the stream contains data of an incorrect type. For example, first type assumes string,
              second and third assume numeric (unsigned && double). If nonnumeric data is input, that read and subsequent use of the stream will fail.
            - Any of the reads could hit end-of-file or some other error in input stream.

            Instead of checking after each word, we check once after reading all of the data and before using the data.

            By leaving the object in a valid state, we (somewhat) protect a user that ignores the possibility of an input error. The object will
             be in a useable state - its members all defined. Similarly, the object won't generate misleading results - its data are internally consistent.

            *NOTE* Input operators should decide what, if anything, to do about error recovery.
        
        | INDICATING ERRORS |
            Some input operators need to do additional data verification. For example, our input operator might check that the bookNo we read is 
             in the correct format. In this case, the input operator might need to set the stream's condition state to indicate failure, even
             though technically speaking the IO was successful.
            
            Usually an input operator should set only the 'failbit'. 
            Setting 'eofbit' would imply that the file was exhausted.   -- Best left to library to throw
            Setting 'badbit' would indicate the stream was corrupted.   -- Best left to library to throw

            

*/

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_Sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price;                                   // no need to initialize; we'll read into price before we use it
    is >> item.bookNo >> item.units_Sold >> price;
    if (is) {                                       // check that the input has succeeded
        item.revenue = item.units_Sold * price;
    } else {
        item = Sales_data();                        // input failed: give the object the default state
    }
    return is;
}

int main()
{


    return 0;
}