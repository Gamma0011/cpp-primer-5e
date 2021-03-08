#include <iostream>
#include <vector>
#include <string>
#include "e1515.h"

/*
    e15.15  - Define your own versions of Disc_quote and Bulk_quote
                see. e1515.h

    e15.16  - Rewrite the class representing a limited discount strategy, which you wrote on pg 601, to inherit from Disc_quote
                see. class Limited_discount : public Disc_quote {}; in e1515.h

    e15.17  - Try to define an object of type Disc_quote and see what errors you get from the compiler.
                Return | error: cannot declare variable 'dq' to be of abstract type 'Disc_quote'

*/

int main()
{
    Quote q("9-99-999", 10);
    return 0;
}