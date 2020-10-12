/*
Some questions:
Where are we supposed to use random?
Recursive insert, is it supposed to take in mutliple ints?
When we remove a link should it return a value?
*/

#include "linkedlist.hpp"
#include <initializer_list>
#include <iostream>

using namespace std;

//constructors
Sorted_List::Sorted_List() : first_link{nullptr} {}
Sorted_List::Sorted_List(initializer_list<int> list) {
    for (int i : list) {
        //for every item in the initializer list, call the insert function
        //to correctly insert the values.
        insert(i);
    }
}

//destructor
Sorted_List::~Sorted_List() {
    while(!is_empty()) {
        remove();
    }
}

//copy constructor
Sorted_List::Sorted_List(Sorted_List const& other) : first_link{copy(other.first_link)} {}
//deep copy using copy function to avoid memory leaks

// move constructor
Sorted_List::Sorted_List(Sorted_List&& other) : first_link{other.first_link} {
    //perform move by changing the pointers
    other.first_link = nullptr;
}

//copy assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List const& other) {
    //removes previous lists and deep copy the other one
    return *this; //derefence this pointer to return the current object
}

//move assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List&& other) {
    //remove old content of list
    //move content from other to this object
}

Sorted_List::Link* Sorted_List::copy(Sorted_List::Link const* n) const {
    if (n == nullptr){
        return nullptr;
    }
    return new Link{n->value, copy(n->next)};
}

bool Sorted_List::is_empty() {
    //linked list is empty if first_link points to nullptr
    return first_link == nullptr;
}

int Sorted_List::size() {
    //return the size of the linked list
    //the number of links
    return num_of_links;
}

//print list
/*
void Sorted_List::print_list(Link* node) {
        if(node->next){
            cout << "Node val: " << node->value << endl;
            //name(node->next);
        }
    }
*/

//should be iterative
void Sorted_List::remove() {
    if(is_empty()) {
        throw std::logic_error{"Can't remove from an empty linked list"};
    }
    //create tmp Link pointer copying all from first_link
    Link* tmp{first_link};
    //set the first link to the next one because we remove the first
    first_link = first_link->next;
    delete tmp;

    //remove 1 from the num_of_links
    --num_of_links;
}

//should be recursive, and should sort the inserted values
void Sorted_List::insert(int value) {

    //create a new Link object with the value set as value
    //then create a tmp Link pointer that points to this new Link object
    Link* tmp{new Link{value}};

    //set the new Link objects pointer to next node to nullptr
    tmp->next = nullptr;

    //sets the pointer of first_link to be the same as tmp, aka they are both pointing to the same object now
    first_link = tmp;
    
    //we have first_link and tmp pointing to this new link with value

    //add 1 to the num_of_links to keep track of size
    ++num_of_links;
}