#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*
    Passing a function to an Algorithm

    || Callable Object ||
    An object or expression is callable if we can apply the call operator to it. ex. e(args)
        - Functions
        - Function Pointers
        - Classes that overload the function call operator
        - Lambda Expressions

        || PREDICATE ||
        Is an expression that can be called and that returns a value that can be used as a condition.  Predicates used by library algorithms are either:

            Unary Predicates - they have a single parameter
            Binary Predicates - they have two parameters
        
        || STABLE_SORT ||
        Maintains the original order among equal elements. By calling stable_sort, we can maintain alphabetical order
        among those elements that have the same length

        || LAMBDAS ||
        Lambdas may not have default parameters

        Syntax:     [capture list](parameter list) -> return type { function body }
                    Capture List - is an (often empty) list of local variables defined in enclosing function
                    Return type, parameter list and function body are the same as any function. 

                    The Capture List and Function Body must ALWAYS be included, but parameter list and return type can be omitted

            **NOTE** Unlike normal functions, lambda functions must use a trailing return to specify its return type
                    Lambdas with function bodies that contain anything other than a single return statement that do not specify a return type return void

*/

// predicate practice
// comparison function to be used to sort by word length
bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words) {
    // sort words alphabetically so we can find the duplicates
    std::sort(words.begin(), words.end());
    // unique reorders the input range so that each word appears once in the 
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// lambda function
// f is a callable object that takes no args and returns 42
auto f = [] { return 42; };

std::string make_plural(std::size_t c, const std::string &s, const std::string &e) { return c >=2 ? s + e : s; }

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) { 
    elimDups(words);            // put words in alphabetical order and remove duplicates
    // re-sort by length, maintaining alphabetical order among words of the same length
                                                // using lambda over function
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){ return a.size() < b.size(); });
    // get an iterator to the first element whose size() is >= sz
    // compute the number of elements with size >= sz
    // print words of the given size or longer, each one followed by a space

    // find_if -- get iterator to the first element whose size() is >= 5
    auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a){ return a.size() >= sz; });

    // compute the number of elements with size >= sz
    auto count = words.end() - wc;      
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." <<std::endl;
    // for_each -- calls object on each elements in input range
    // print words of given size or longer, each one followed by a space
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; }); 
    std::cout <<std::endl;

}

int main()
{   
    std::vector<std::string> words = {"this", "is", "the", "end", "fictional", "testing"};
    // sort() uses isShorter in place of default < to compare elements
    //std::sort(words.begin(), words.end(), isShorter);


    //elimDups(words);        // put words in alphabetical order and remove duplicates
    // re-sort by length, maintaining alphabetical order among words of same length
    //std::stable_sort(words.begin(), words.end(), isShorter);

    // stable_sort && isShorter rewritten with a lambda
    //std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() > b.size(); });

    /*
    for (const auto &s : words) { std::cout << s << " ";}
    std::cout <<std::endl;
    */

    // calling a lambda
    //std::cout << f() <<std::endl;

    biggies(words, 5);

    
    return 0;
}