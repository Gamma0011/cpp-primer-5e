#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
    e949 - a letter has an ascender if, as with d or f, part of the letter extends above the middle of the line. A letter has a descender if,
            as with p or g, part of the letter extends below the line. Write a program that reads a file containing words and reports the
            longest word that contains neither ascenders nor descenders.

    Steps:
        open file
        read words from file into program
        check if words have ascenders or descenders
        if detected, continue
        else check agains .size() of current saved word. if >, overwrite, else ignore
*/

int main(int argi, char **filePath)
{
    std::ifstream open(filePath[1]);
    std::string ascenders("bdfhiklt");
    std::string descenders("gjpqy");
    std::string exclude = ascenders + descenders;

    std::string temp;           // store temp word
    std::string word;           // word matching parameters and greatest numnber of characters

    if(open) {          // if file can be opened
        while(open >> temp) {           // while there are words to read
            if(temp.find_first_of(exclude) == std::string::npos) {
                if (word.size() == 0 || temp.size() >= word.size()) {
                    word = temp;
                }
            }
        }
    } else {
        std::cerr << "ERROR: No File." <<std::endl;
        return -1;
    }

    std::cout << "The longest word without ascenders and descenders was: " << word <<std::endl;



    return 0;
}