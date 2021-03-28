#ifndef __PAL_H__
#define __PAL_H__

#include <iostream>

template<typename T> class Pal;

class C {       // c is nontemplate class
    friend class Pal<C>;

    // all instances of Pal2 are friends to C
    // no forward declaration required when we befriend all instantiations
    template<typename T> friend class Pal2;
};

template<typename T> class C2 {
    // each instantiation of C2 has same Pal as a friend
    friend class Pal<T>;

    // all instances of Pal2 are friends of each instances of C2 ; forward declaration needed
    template<typename X> friend class Pal2;

    // Pal3 is a nontemplate class that is a friend of every instance of C2
    friend class Pal3;
};

#endif