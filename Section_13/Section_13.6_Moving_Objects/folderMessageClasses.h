#ifndef FOLDERMESSAGE_CLASSES
#define FOLDERMESSAGE_CLASSES

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) { };          // default constructor
    Message(const Message&);                            // copy constructor
    Message& operator=(const Message&);                 // copy-assignment operator
    Message(Message&&);                                 // move constructor
    Message& operator=(Message &&);                     // move-assignment operator
    ~Message();                                         // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);

    void addFolder(Folder*);            // add pointer to folder
    void remFolder(Folder*);            // remove pointer to folder

    void move_Folders(Message*);

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
    friend void swap(Folder&, Folder&);

    Folder() = default;                 // default constructor
    Folder(const Folder&);              // copy constructor
    Folder& operator=(const Folder&);   // copy-assignment operator
    ~Folder();                          // destructor

    void addMsg(Message*);   // add pointer to given Message
    void remMsg(Message*);   // remove pointer to given Message

    void add_to_Messages(const Folder&);     
    void rem_from_Messages();

private:
    std::set<Message*>messages;
};

/************ MESSAGES COPY CONTROL ************/

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);              // add this Message to the Folders that point to m
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();          // update existing Folders
    contents = rhs.contents;        // copy message contents
    folders = rhs.folders;          // copy Folder pointers
    add_to_Folders(rhs);            // add this Message to those Folders
    return *this;
} 

/************ MESSAGES MOVE CONTROL ************/

Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);               // moves folders and updates the Folder pointers
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {                     // direct check for self-assignment
        remove_from_Folders();              // destroy old state of lhs operand (Message&)
        contents = std::move(rhs.contents); // execute move command
        move_Folders(&rhs);                 // reset the Folders to point to this Message
    }
    return *this;
}

/************ DESTRUCTOR ************/

Message::~Message() { remove_from_Folders(); }

/************ MESSAGES MEMBER FUNCTIONS ************/

void Message::save(Folder &f) {
    folders.insert(&f);     // add the given Folder to our list of Folders
    f.addMsg(this);         // add this Message to f's set of Messages
}
void Message::remove(Folder &f) {
    folders.erase(&f);      // take the given Folder out of our list of Folders
    f.remMsg(this);         // remove this Messsage to f's set of Messages
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders); // set move assignment used

    for (auto f : folders) {    // for each Folder
        f->remMsg(m);           // remove the old Message from the folder
        f->addMsg(this);        // add this Message to that folder
    }
    m->folders.clear();         // ensure that destroying m is harmless
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders) {      // for each Folder that holds m
        f->addMsg(this);            // add a pointer to this Message to that Folder
    }
}

void Message::remove_from_Folders() {
    for (auto f : folders) {    // for each pointer in folders
        f->remMsg(this);        // remove this Message from that Folder
    }   
    folders.clear();              // no Folder points to this Message
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    // remove pointers to each Message from their (original) respective Folders
    for (auto f : lhs.folders) { f->remMsg(&lhs); }
    for (auto f : rhs.folders) { f->remMsg(&rhs); }

    // swap contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);             // use swap(set&, set&)
    swap(lhs.contents, rhs.contents);           // use swap(string&, string&)

    // add pointers to each Message to their (new) respective Folders
    for (auto f : lhs.folders) { f->addMsg(&lhs); }
    for (auto f : rhs.folders) { f->addMsg(&rhs); }

}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}

/************ FOLDER COPY CONTROL ************/
Folder::Folder(const Folder &f) : messages(f.messages) {
    add_to_Messages(f);
};

Folder& Folder::operator=(const Folder &rhs) {
    rem_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder() {
    rem_from_Messages();
}

/************ FOLDER MEMBER FUNCTIONS ************/

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

void Folder::add_to_Messages(const Folder &f) {
    for (auto m : f.messages) {
        //m->save(*this);
        m->addFolder(this);
    }
}

void Folder::rem_from_Messages() {
    for (auto m : messages) {
        //m->remove(*this);
        m->remFolder(this);
    }
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.rem_from_Messages();
    rhs.rem_from_Messages();

    swap(lhs.messages, rhs.messages);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}



#endif