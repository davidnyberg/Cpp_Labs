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
        remove(first_link->value);
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
    swap(first_link, tmp.first_link);

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
/*
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
*/
//rm specific element
void Sorted_List::remove(int value) {
    if(is_empty()) {
        throw std::logic_error{"Can't remove from an empty linked list"};
    }
    // todo: check if in list

    Link* first{first_link};
    Link* next_link{first->next};

    if (first_link->value == value) {
        first->next = nullptr;
        delete first;
        //move the first link to next link
        first_link = next_link;
        num_of_links--;
    }
    //if not the first node, check rest of the list
    //for (int i{1}; i < num_of_links; i++) {
    while(next_link != nullptr) {
        if (next_link->value == value) {
            //move the first link to nexts next, skip over one link - drawing
            first->next = next_link->next;
            next_link->next = nullptr;
            delete next_link;
            num_of_links--;
        }
        //moving all links one step forward
        if (next_link->next == nullptr || first->next == nullptr) break;
        first = first->next;
        next_link = next_link->next;
    }
}
//Sources:
//https://stackoverflow.com/questions/16632174/linked-list-insert-function-recursively-c
//http://www.cs.bu.edu/~snyder/cs112/CourseMaterials/LinkedListNotes.html
void Sorted_List::insert(Link * l, int value) {
    //l should be the current node
    Link* l_next{l->next};
    //end of the list
    if (l->next == nullptr) {
        Link* new_link{new Link{value, nullptr}};
        //new_link->value = value;
        //new_link->next = nullptr;

        l->next = new_link;
        //new end of list
        new_link->next = nullptr;
        num_of_links++;
    }
    else if (value <= l_next->value) {   
        Link* new_link{new Link{value, nullptr}};
        //new_link->value = value;
        //new_link->next = nullptr;
    
        //previous node points to new link
        l->next = new_link;
        //the new inserted link points to l's old link
        new_link->next = l_next;
        num_of_links++;
    } else {
        insert(l_next, value);
    }
}

//recursive helper function, sorts
void Sorted_List::insert(int value) {

    if(is_empty() == true) {
        Link* new_link{new Link{value, nullptr}};
        //new_link->value = value;
        //new_link->next = nullptr;
        first_link = new_link;
        num_of_links++;
    }

    else if (value < first_link->value) {
        Link* new_link{new Link{value, nullptr}};
       // new_link->value = value;
       // new_link->next = nullptr;

        new_link->next = first_link;
        first_link = new_link;
        num_of_links++;
    }
    else {
        insert(first_link, value);
    }
}