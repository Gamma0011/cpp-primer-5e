#include <iostream>

size_t factorial(size_t i) {
    size_t ret = 1;
    while (i > 0){
        ret *= i--;
    }

    return ret;
}
