#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e59()
{
    // write a program using series of if statements to count # of vowels in text read from cin

    unsigned int vowelcounter = 0;
    char ch;

    while (cin >> ch) {
        if (ch == 'a') {
            ++vowelcounter;
        }
        if (ch == 'e') {
            ++vowelcounter;
        }
        if (ch == 'i') {
            ++vowelcounter;
        }
        if (ch == 'o') {
            ++vowelcounter;
        }
        if (ch == 'u') {
            ++vowelcounter;
        } else
        {
            ;               // do nothing
        }
    }

    cout << "Vowels: " << vowelcounter <<endl;
}

void e510()
{
    // one problem with vowel-counting program: cannot count capitals
    //  make a program that can do that

    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;

    while (cin >> ch) {
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'A':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'E':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'I':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'O':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            case 'U':
                ++uCnt;
                break;
            default:
                break;
        }
    }

    cout << "A: " << aCnt << '\n' <<
            "E: " << eCnt << '\n' <<
            "I: " << iCnt << '\n' <<
            "O: " << oCnt << '\n' <<
            "U: " << uCnt << '\n' <<endl;
}

void e511()
{
    // modify our vowel counter so that it also counts number of blank spaces, tabs and newlines

    unsigned int vowelCnt = 0, spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch;

    while (cin >> std::noskipws >> ch) {
        switch(ch) {
            case 'a' : case 'A' :
            case 'e' : case 'E' :
            case 'i' : case 'I' :
            case 'o' : case 'O' :
            case 'u' : case 'U' :
                ++vowelCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }
    }

    cout << "Vowels: " << vowelCnt << '\n' <<
            "Spaces: " << spaceCnt << '\n' <<
            "Tabs: " << tabCnt << '\n' <<
            "Newlines: " << newlineCnt <<endl;
}

void e512()
{
    // modify vowel-counting program so that it counts number of occurrences of the following two-character sequence, ff, fl, fi;

    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prechar = '\0';

    while (cin >> std::noskipws >> ch) {
        switch(ch) {
            case 'f': 
                if (prechar == 'f')
                    ++ffCnt;
                    break;
            case 'l':
                if (prechar == 'f')
                    ++flCnt;
                    break;
            case 'i':
                if (prechar == 'f')
                    ++fiCnt;
                    break;
            default:
                break;
        }
        prechar = ch;
    }

    cout << "ff occurrences: " << ffCnt << '\n' <<
            "fl occurrences: " << flCnt << '\n' <<
            "fi occurrences: " << fiCnt << '\n' <<endl;
}

void e513()
{
    // each program on 184 has a common programming error, identify and correct

    /*      a)
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
            case 'a' : aCnt++;
            case 'e' : eCnt++;
            default  : iouCnt++;
    }

    ** forgot break statement
    unsigned int aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
            case 'a' : 
                aCnt++; 
                break;   
            case 'e' : 
                eCnt++; 
                break;
            default : 
                iouCnt++; 
                break;
    }

    */


   /*       b)
    unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ix] = index;
            break;  
        default:
            ix = ivec.size() - 1;
            ivec[ix] = index;
        }
    
    // error: ix not in default case scope, needs to be declared before switch

    unsigned index = some_value();
    int ix;

    switch (index) {
        case 1:
            ix = get_value();
            ivec[ix] = index;
            break;  
        default:
            ix = ivec.size() - 1;
            ivec[ix] = index;
        }
   */



  /*        c)
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;

  switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break:
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
  }

  // case label syntax error, also no possible way remainder == 10; missing capitalization on evenCnt and oddCnt;
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;

  switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        oddCnt++;
        break:
    case 2: case 4: case 6: case 8: case 0:
        evenCnt++;
        break;
  }
  */


 /*     d)
 unsigned ival=512, jval=1024, kval=4096;
 unsigned bufsize;
 unsigned swt = get_bufCnt();

 switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = ival * sizeof(int);
        break;
    case kval:
        bufsize = ival * sizeof(int);
        break;
 }
    // case labels must be const expressions

 const unsigned ival=512, jval=1024, kval=4096;
 unsigned bufsize;
 unsigned swt = get_bufCnt();

 switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
 }

 */
}

int main()
{
    //e59();
    //e510();
    //e511();
    //e512();

    return 0;
}
