#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <string>

class Sorted_List {
    private:
    int num_of_links{0};
    class Link {
        public:
            int value{};
            //pointer to next link;
            Link* next{};
    };
    //first link is simply a pointer to the first link with a value
    Link* first_link{};
    Link* copy(Link const* n) const;
public:
    Sorted_List();
    Sorted_List(std::initializer_list<int> list); //constructor
    ~Sorted_List(); //destructor
    Sorted_List(Sorted_List const& other); //copy constructor
    Sorted_List(Sorted_List&& other); //move constructor

    Sorted_List& operator=(Sorted_List const& other); //copy assignment operator
    Sorted_List& operator=(Sorted_List&& other); //move assignment operator

    bool is_empty();
    int size();
    std::string print_list();
    //void remove();
    void remove(int value);
    void insert(int value);
    void insert_helper(Link* l, int value);


};

#endif