#include <iostream>
#include <vector>
#include <string>
#include <set>

/*
    | A COPY-CONTROL EXAMPLE |
        Resource management is not the only reason why a class might need to define copy-control members. Some classes have bookkeeping
         or other actions that the copy-control members must perform.

         In this section, we'll build two classes that might be used in a mail-handling application
         
         **BEST PRACTICES** The copy-assignment operator often does the same work as is needed in the copy constructor and destructor.
            In such cases, the common work should be put in private utility functions.

*/

class Message {
    friend class Folder;
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) { };

    // copy control to manage pointers to this message
    Message(const Message&);                            // copy constructor
    Message& operator=(const Message&);                 // copy-assignment operator
    ~Message();                                         // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;               // actual message text
    std::set<Folder*>folders;           // Folders that have this message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);    
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class Folder {
public:
    Folder() = default;         // temp
    Folder& addMsg(Message*);
private:
};

void Message::save(Folder &f) {
    folders.insert(&f);     // add the given Folder to our list of Folders
    f.addMsg(this);         // add this Message to f's set of Messages
}
void Message::remove(Folder &f) {
    folders.erase(&f);      // take the given Folder out of our list of Folders
    f.addMsg(this);         // remove this Messsage to f's set of Messages
}


int main()
{


    return 0;
}