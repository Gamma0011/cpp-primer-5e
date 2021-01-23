#include <iostream>
#include <vector>
#include <string>

/*
    e13.33  - Why is the parameter to the save and remove members of Message a Folder&? Why not Folder or const Folder&?
                Not Folder because we don't want to copy the object of Folder and not const Folder& because since we're
                calling save and remove, we want to modify the data members within that object. const Folder& prevents
                manipulation. Folder& is correct - allows us to avoid copying the object as well as modify its data.
    
    e13.34  - Write the Message class as described in this section.
                see practice.cpp
    
    e13.35  - What would happen if Message used the synthesized version of copy-control members?
                The synthesized version would not add/remove the messages from the respective 
                pointers within the Message object's Folder* set.

    e13.36  - Design and implement the corresponding Folder class. That class should hold a set that points to the
                Messages in that Folder

                see class Folder (practice.cpp)

    e13.37  - Add members to the Message class to insert or remove a given Folder* into folders. These members are analogous to Folder's
                addMsg and remMsg operations.

                see practice.cpp

    e13.38  - Why did we not use copy and swap to define the Message assignment operator? Why do you suppose this is so?
                There's no real performance gain in doing so since using swap(*this, rhs) would require the operator= to call
                 the constructor and destructor functions. It's possible that doing this would cause a slight performance hit
                 since, as it's currently defined, everything is inline. Additionally, in its current form, the swap function 
                 is valuelike while the way we'd build it using (*this, rhs) would require a pointerlike swap 

*/


int main()
{


    return 0;
}