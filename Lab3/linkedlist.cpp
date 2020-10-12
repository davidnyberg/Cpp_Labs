/*
how to implement this whole lab is basically in the slides le4
https://www.ida.liu.se/~TDDE18/current/slides/slides/TDDE18.726G77.le4.pdf

*/
#include "linkedlist.hpp"
#include <initializer_list>
#include <iostream>

using namespace std;

//constructor
Sorted_List::Sorted_List(initializer_list<int> list) {
    for (int i : list) {
        //for every item in the initialzied list, call the insert function
        //to correctly insert the values.
        insert(i);
    }
}
//destructor
Sorted_List::~Sorted_List() {
    //probably call remove on every node
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

bool Sorted_List::is_empty() {
    //check if there are any links
    return true;
}

int Sorted_List::size() {
    //return the size of the linked list
    //the number of links
    return 1;
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
    //create tmp pointer to first_link
    Link* tmp{first_link};
    //set the first link to the next one because we remove the first
    first_link = first_link->next;
    delete tmp;
}

//should be recursive
void Sorted_List::insert(int value) {
    Link* tmp{new Link{value}};
    tmp->next = first_link;
    first_link = tmp;
    //free memory of tmp Link object
    delete tmp;
}