#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
    || WRITING OVERLOADED TEMPLATES ||
        Function templates can be overloaded by other templates, or by ordinary, nontemplate functions. As usual, functions with the same name must differ by parameters.

        Function matching is affected by the presence of function templates in the following ways:
            - Candidate functions for call include any function-template instantiation for which argument deduction succeeds.
            - Candidate function templates always viable, b/c template argument deduction will have eliminated non-viable templates.
            - Viable functions (all) are ranked by conversions, if any, needed. 
            - If exactly one function provides a better match, that one is selected. If more than one matches:
                - Only one nontemplate good? Nontemplate called.
                - No nontemplates in set, but multiple templates? More specialized function template called.
                - Otherwise, call ambiguous.

        *WARNING* Correctly defining a set of overloaded function templates requires good understanding of relationship among types and restricted conversions.

        We'll build a template called debug_rep. see template<T> debug_ref




*/

template <typename T>
std::string debug_ref(const T& t) {
    std::ostringstream ret;
    ret << t;                   // uses T's output operator to print representation of t
    return ret.str();           // return copy of string to which ret bound.
}


int main()
{


    return 0;
}