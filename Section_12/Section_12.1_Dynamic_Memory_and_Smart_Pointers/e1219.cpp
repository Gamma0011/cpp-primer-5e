#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "strblobs.h"

// e12.19   - Define your own version of StrBlobPtr and update your StrBlob class with the appropriate friend declartion and begin and end members
//              redefined as strblobs.h

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

int main()
{


    return 0;
}