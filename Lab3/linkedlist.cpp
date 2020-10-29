#include "linkedlist.hpp"
#include <initializer_list>
#include <iostream>
#include <string>

using namespace std;

//constructors
Sorted_List::Sorted_List() : first_link{nullptr} {}
Sorted_List::Sorted_List(initializer_list<int> list) : first_link{nullptr} {
    for (int i : list) {
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
    Sorted_List tmp{other};
    swap(first_link, tmp.first_link);
    return *this; //derefence this pointer to return the current object
}

//move assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List&& other) {
    //remove old content of list
    Sorted_List tmp{other};
    //move(first_link, tmp.first_link);
    return *this;
    //move content from other to this object
}

//return type of link pointer, 
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
    return num_of_links;
}

//Note: returning string is mostly for testing, can be void
std::string Sorted_List::print_list() {
    std::string result = "";
    if(is_empty()) {
        //cout << "List is empty" << endl;
        return result;
    }
    //temp linkptr variable to not modify first_link
    Link* tmp{first_link};
    while(tmp != nullptr){
        cout << tmp->value;
        result += to_string(tmp->value);
        tmp = tmp->next;
    }
    cout << endl;
    return result;

}
//remove with no parameters
void Sorted_List::remove() {
    if(is_empty()) {
        throw std::logic_error{"Can't remove from an empty linked list"};
    }
    //create tmp Link pointer copying all from first_link
    Link* tmp{first_link};
    //set the first link to the next one because we remove the first
    first_link = tmp->next;
    delete tmp;

    //remove 1 from the num_of_links
    --num_of_links;
}
//rm specific element
void Sorted_List::remove(int value) {
    if(is_empty()) {
        throw std::logic_error{"Can't remove from an empty linked list"};
    }
    //create tmp Link pointer copying all from first_link
    Link* tmp{first_link};
    //set the first link to the next one because we remove the first
    first_link = tmp->next;
    delete tmp;

    //remove 1 from the num_of_links
    --num_of_links;
}

//should be recursive, and should sort the inserted values
void Sorted_List::insert(int value) {
    //points to first link
    Link* tmp1{first_link};

    //create a new link object with the value set as value
    //then create a tmp Link pointer that points to this new link object
    Link* tmp{new Link{}};
    tmp->value = {value};

    //check if first_link or the new link has a greater value
    
    //works for sorting the first place, now need to sort the
    //rest of the list
    if(tmp1 != nullptr){
        bool test = {tmp1->value < tmp->value};
        //cout << test << endl;
        if (test) {
            swap(tmp1->value, tmp->value);
        }
    }
    

    //if the first_link pointer already points to something, go to the next link
    tmp->next = first_link;
    
    //sets the pointer of first_link to be the same as tmp, aka they are both pointing to the same object now
    first_link = tmp;
    
    //we have first_link and tmp pointing to this new link with value

    //add 1 to the num_of_links to keep track of size
    ++num_of_links;
}