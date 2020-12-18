#include <iostream>

int main()
{
    int ival = 1024;
    int &refVal = ival;     // refVal refers to (is another name for) ival
                            // by setting refVal = ival, we copy the value of ival to refVal
                            // however, by by defining a reference, we bind the reference to the initalizer and remain bound
                            // this is why references must be initialized

    //int &refVal2;           // error: references MUST be initalized at declaration

    /* A reference is not an object, rather just another name for an already existing object
     */

    refVal = 2;             // assigns 2 to the object to which refVal refers, i.e. ival
    int ii = refVal;        // same as ii = ival

    std::cout << ii <<std::endl;


    // ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
    int &refVal3 = refVal;

    // initializes i from the value in the object to which refVal is bound
    int i = refVal;         // initalizes i to the same value as ival

    // references cannot be bound to references

    return 0;
}