#include <iostream>
#include <vector>
#include <string>

/*
    OPERATOR OVERLOADING lets us define the meaning of an operator when applied to operand(s) of class type. 
     Use of operator overloading can make our programs easier to write and read.

    || BASIC CONCEPTS ||
        Overloaded operators are functions with special names: the keyword OPERATOR, followed by the symbol for which the operator is being defined.
         An overloaded operator has a return type, a parameter list, and a body.
        Except for the overloaded function-call operator operator(), an overloaded operator may not have any default arguments.

        If an operator function is a member function, the first (left-hand) operand is bound to the implicit *this. Because of this, a member
         operator function has one less (explicit) parameter than the operator has operands.

        An operator function must either be:
            - A member of a class
            - Have at least one parameter of class type

            // error:
            int operator+(int, int);
        
        This restriction prevents us from changing the meaning of an operator of built-in type. All but :: .* . ?: can be overloaded.
        Additionally, we cannot invent new operator symbols.

        An overloaded operator has the same precedence and associativity as the corresponding built-in operator.

        | CALLING AN OVERLOADED OPERATOR FUNCTION DIRECTLY |
            Ordinarily, we "call" an overloaded operator function directly by using the operator on arguments of the appropriate type.
             We can also call an overloaded operator function directly in the same way we can an ordinary function.

             // equivalent calls to a nonmember operator function
             data1 + data2;                 // normal expression
             data1.operator=(data1, data2); // equivalent function call

             data1 += data2;                // expression-based "call"
             data1.operator+(data2);        // equivalent call to a member operator function

        | SOME OPERATORS SHOULDN'T BE OVERLOADED |
            Operand-evaluation guarantees of logical AND, logical OR, and comma operators are not preserved. Overloaded versions of && or || 
            do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated. 
            Therefore, it is a bad idea to overload them.
        
        | USE DEFINTIIONS THAT ARE CONSISTENT WITH THE BUILT-IN MEANING |
            When you design a class, you should always think first about what operations the class will provide. Only after you know what operators
            are needed should you think about whether to define each operation as an ordinary function or an overloaded operator.

            Considerations:
                - If class does IO, define the shift operators to be consistent with how IO is done for built-in types.
                - If class has operation to test for equality, define operator==. If operator== is define, operator!= should be too
                - If class has a single, natural ordering operation, define operator<. If one relational operator is defined. The others should be as well
                - The return type of an overloaded operator usually is compatible with the return from the built-in version of the operator:
                    Logical and relational operators return BOOL. Arithmetic operators return a VALUE of CLASS TYPE. Assignment returns & to Left-Hand operand.
                
            CAUTION: USE OPERATOR OVERLOADED JUDICIOUSLY
                Operator overloaded is useful when there is a logical mapping of a built-in operator to an operation on our type. Using overloaded operators, 
                rather than inventing named operations can make our program more natural and intuitive. However, overuse or poor implementation will make 
                classes incomprehensible.
                Operators should be used for operations that are likely to be unambiguous.
            
        | CHOOSING MEMBER OR NONMEMBER IMPLEMENTATION |
            Use these guidelines when deciding whether an overloaded operator is a member of a class:
                - The assignment =, subscript [], call () and member access arrow -> MUST BE MEMBERS
                - Compound-assignment operators OUGHT TO BE MEMBERS, but not required.
                - Operators that change state of object (increment, decremenet, dereference), SHOULD BE MEMBERS.
                - Symmetric operators, those that might convert either operand such as arithmetic, equality, relational, and bitwise,
                    should be DEFINED AS NONMEMBER FUNCTIONS

            Programmers expect to be able to use symmetic operators in expressions with mixed type (for example, int + double)
            
            When we define an operator as a member function, then the left-hand operand must be an object of the class of which
             that operator is a member

                string s = "world";   
                string t = s + "!";     // ok: we can add a const char* to a string
                string u = "hi" + s;    // would be error if + were a member of string

                string u = "hi" + s;    Same as "hi".operator+(s); However "hi" is const char* and a built-in type. It does not even have member functions.

                Because string defines + as an ordinary nonmember function, "hi" + s is the same as operator+("hi",s); The only requirement is that at least one
                of the operands has a class type, and both can be converted to string.


*/


int main()
{


    return 0;
}