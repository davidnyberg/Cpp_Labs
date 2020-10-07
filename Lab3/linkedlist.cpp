/*
how to implement this whole lab is basically in the slides le4
https://www.ida.liu.se/~TDDE18/current/slides/slides/TDDE18.726G77.le4.pdf

*/
#include "linkedlist.hpp"


//constructor
    Sorted_List::Sorted_List() : first_link{nullptr} {}
//destructor
Sorted_List::~Sorted_List() {
    //delete every node
}
//copy constructor
Sorted_List::Sorted_List(Sorted_List const& other) {
    //deep copy of lists
}

//move constructor
Sorted_List::Sorted_List(Sorted_List&& other) {
    //perform move by changing the pointers
}

//copy constructor
Sorted_List& Sorted_List::operator=(Sorted_List const& other) {
    //removes previous lists and deep copy the other one

    //return *this; //derefence this pointer to return the current object
}

//move constructor
Sorted_List& Sorted_List::operator=(Sorted_List&& other) {
    //remove old content of list
    //move content from other to this object
}

//print list
void Sorted_List::print_list(Link* node){
        if(node->next){
            cout << "Node val: " << node->val << endl;
            name(node->next)
        }
        //don't need return??
    }


void Sorted_List::remove() {
    //create tmp pointer to first_link
    Link* tmp{first_link};
    //set the first link to the next one because we remove the first
    first_link = first_link->next;
    delete tmp;
}
void Sorted_List::insert(int value) {
    
    Link* tmp{new Link{value}};
    tmp->next = first_link;
    first_link = tmp;
    //free memory of tmp Link object
    delete tmp;
}