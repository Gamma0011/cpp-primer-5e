#ifndef __DEBUG_DELETE_H__
#define __DEBUG_DELETE_H__

#include <iostream>
#include <string>
#include <memory>

class DebugDelete {
public:
    DebugDelete(std::ostream &out = std::cerr) : os(out) { };

    template<typename T> void operator()(T *p) {
        delete p;
        os << "Pointer deleted." << std::endl;
    }

private:
    std::ostream &os;
};

#endif