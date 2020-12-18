#include <iostream>
#include <stack>
#include <queue>

/*  
    e952 - Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see
            a close paranthesis after an open one, pop elements down to and including the open paranthesis off the stack.
            Push a value onto the stack to indicate that a parenthesized expressions was replaced.

            Steps:
                Create stack
                Find  ( )
                Pop / remove elements between ( )
                Note in stack that value was replaced

*/

std::string e951(std::string &s) {
    std::stack<char> cstk;
    std::string newS;

    bool seen = false;

    for (const auto &c : s) {
        if (c == '(') {             // if ( seen, start writing to stack;
            seen = true;
            continue;
        } else if (c == ')') {      // if ) seen, stop writing to stack;
            seen = false;
        }

        if (seen) {
            cstk.push(c);
        }
    }

    while (!cstk.empty()) {
        newS += cstk.top();
        std::cout << cstk.top() <<std::endl;
        cstk.pop();
    }

    s.replace(s.find("(")+1, newS.size(), newS);

    return s;

}

int main()
{
    std::string s("This is a (test) string.");

    std::cout << e951(s) <<std::endl;
    

    return 0;
}