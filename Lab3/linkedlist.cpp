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

//destructor, deep deallocation
Sorted_List::~Sorted_List() {
    while(!is_empty()) {
        remove(first_link->value);
    }
}

//copy constructor, //deep copy using copy function to avoid memory leaks
Sorted_List::Sorted_List(Sorted_List const& other) : first_link{copy(other.first_link)}, num_of_links{other.num_of_links} {
    std::cout << "Called copy constructor" << std::endl;
    }


//copy assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List const& other) {
    std::cout << "Called copy assignment" << std::endl;

    first_link = copy(other.first_link);
    num_of_links = other.num_of_links;

    return *this; //derefence this pointer to return the current object
}

// move constructor
Sorted_List::Sorted_List(Sorted_List&& other) : first_link{other.first_link}, num_of_links{other.num_of_links} {
    std::cout << "Called move constructor" << std::endl;
    //perform move by changing the pointers
    
    other.first_link = nullptr;
}

//move assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List&& other) {

    std::cout << "Called move assignment" << std::endl;
    //move content from other to this object

    swap(other.first_link, first_link);
    swap(other.num_of_links, num_of_links);

    return *this;
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

//return the size of the linked list
int Sorted_List::size() {
    return num_of_links;
}

//Note: returning string is mostly for testing, can be void
std::string Sorted_List::print_list() {
    std::string result = "";
    if(is_empty()) {
        return result;
    }
    //temp linkptr variable to not modify first_link
    Link* tmp{first_link};
    while(tmp != nullptr){
        result += to_string(tmp->value);
        tmp = tmp->next;
    }
    return result;

}

//rm specific element
void Sorted_List::remove(int value) {
    if(is_empty()) {
        throw std::logic_error{"Can't remove from an empty linked list"};
    }

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
        
        if (next_link->next == nullptr || first->next == nullptr){
            //cout << "Not in list" << endl;
            break;
        }
        //moving all links one step forward
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
    //end of the list because there is no next link, simply add new link to end
    if (l->next == nullptr) {
        Link* new_link{new Link{value, nullptr}};
        l->next = new_link;
        //new end of list

        num_of_links++;
    }
    //case where the value is in the middle of two links,
    //first create newlink and make the previous links point to the newlink, and 
    //the new link should point to the previous links next link.
    else if (value <= l_next->value) {   
        Link* new_link{new Link{value, nullptr}};
    
        //previous node points to new link
        l->next = new_link;
        //the new inserted link points to l's old link
        new_link->next = l_next;
        num_of_links++;
    
    //else move the two pointers one step forward and re try insert
    } else {
        insert(l_next, value);
    }
}

//recursive sorted insert
void Sorted_List::insert(int value) {

    //if list is empty, simply create new link and make it the first_link
    if(is_empty() == true) {
        Link* new_link{new Link{value, nullptr}};

        first_link = new_link;
        num_of_links++;
    }

    //if insert value is less than the first link, create new link,
    //then make first_link the new link, and make it point to the old first_link
    else if (value < first_link->value) {
        Link* new_link{new Link{value, nullptr}};

        new_link->next = first_link;
        first_link = new_link;
        num_of_links++;
    }
    //else recursively call the overloaded insert function to check rest of list
    else {
        insert(first_link, value);
    }
}