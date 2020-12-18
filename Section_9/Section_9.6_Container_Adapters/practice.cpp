#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

/* 
    In addition to the sequential containers, the library also defines 3 sequential container adaptors: stack, queue, and priority_queue.
     An adaptor is a general concept library. There are container, iterator, and function adaptors.
     Essentially, an adaptor is a mechanism for making one thing act like another.

     For example, the STACK adaptor takes a sequential container (other than array or forward_list) and makes it operate as if it were a stack.

    OPERATIONS AND TYPES COMMON TO THE CONTAINER ADAPTORS
    size_type               type large enough to hold the size of the largest object of this type
    value_type              element type
    container_type          type of the underlying container on which the adaptor is implemeneted
    A a;                    create a new empty adaptor named a
    A a(c);                 create a new adaptor named a with a copy of the container c
    relational operators    each adaptor supports all the relational operators == != <= >= < >
    a.empty()               false if a has any elements, true otherwise
    a.size()                number of elements in a
    swap(a,b)               swamps contents of a and b. a & b must have same type, including the container on which they were implemented
    a.swap(b)


    DEFINING AN ADAPTOR
    
    We can initialize a new stack as follows:
        std::deque<int> deq;
        stack<int> stk(deq);            // copies elements from deq into stk

    By default, both stack and queue are implemented in terms of deque. priority_queue is implemented on a vector

    Stack is defined in the stack header

    ADDITIONAL STACK OPERATIONS
    s.pop()                 Removes, but does not return, the top element from the stack
    s.push(item)            Creates a new top element on the stack by copying or moving item, 
    s.emplace(args)         ...or by constructing the elements from args
    s.top()                 Returns, but does not remove the top element in the stack

    Queue and priority_queue adaptors are defined in the queue header

    QUEUE AND PRIORITY QUEUE OPERATIONS
    q.pop()                 Removes, but does not return, the front element or highest-priority from the queue or priority_queue
    q.front()               Returns, but does not remove, the front element of q
    q.back()                ONLY VALID FOR QUEUE
    q.top()                 Returns, but does not remove, the highest-priority element. VALID ONLY FOR PRIORITY_QUEUE
    q.push(item)            Create an element with value item or constructed from args at the end of queue
    q.emplace(args)         ...or in its appropriate position in priority_queue

*/

void stack_practice() {
    std::stack<int> intStack;       // empty stack
    // fill stack
    for (size_t ix = 0; ix != 10; ++ix) {
        intStack.push(ix);                  // intStack holds 0-9 inclusive
    }
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();                 // pop the top element, repear
    }
}

int main()
{

    return 0;
}
