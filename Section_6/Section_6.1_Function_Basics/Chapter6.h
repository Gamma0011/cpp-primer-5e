#ifndef CHAPTER6_H
#define CHAPTER6_H


int absolute(int i) {
    return i > 0 ? i : -i;
}

size_t factorial(size_t i) {
    size_t ret = 1;
    while (i > 0){
        ret *= i--;
    }

    return ret;
}

#endif