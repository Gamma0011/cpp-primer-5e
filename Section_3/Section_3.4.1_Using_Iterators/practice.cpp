#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// *iter                returns a reference to the element denoted bu the iterator iter
// iter->mem            dereferences iter and fetches the member named mem from the underling element. Equal to (*iter).mem
// ++iter               increments iter to refer to the next element in the container
// --iter               decremenets iter to refer to the previous element in the container
// iter1 == iter2       compares two iterators for equality
// iter1 != iter2       compares for inequality


// NOTE: Because .end() does not denote an element, it cannot be incremented or decremented



void iterator_ops(){
    string s("some string");
    if(s.begin() != s.end()){               // make sure s isn't empty
        auto it = s.begin();                // it denotes the first character in s;
        *it = toupper(*it);                 // make that character uppercase;
    }
    cout << s <<endl;
}

void iterator_ops2(){
    string s("some string");
    // process characters in s until we run out of characters, or hit whitespace
    for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
        *it = toupper(*it);                                             // capitalize the current character
    }
    cout << s <<endl;
}

int main()
{
    //iterator_ops();
    iterator_ops2();

    return 0;
}
