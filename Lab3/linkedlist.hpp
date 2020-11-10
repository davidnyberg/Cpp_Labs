#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <string>

//TODO: Complementary work needed, 6-6: Declare member functions not
//changing the state of the object as constant.
//DONE

//TODO: Complementary work needed, 8-8: A Link should not be exposed
//to the public interface.
//DONE, made the member function exposing link to public into a hidden member function
// (AKA put into private scope)

class Sorted_List {
    private:
    int num_of_links{0};
    class Link {
        public:
            int value{};
            //pointer to next link;
            Link* next{};
    };
    Link* first_link{nullptr};
    Link* copy(Link const* n) const;
    void hidden_insert(Link* l, int value);
public:
    Sorted_List();
    Sorted_List(std::initializer_list<int> list); //constructor
    ~Sorted_List(); //destructor
    Sorted_List(Sorted_List const& other); //copy constructor
    Sorted_List(Sorted_List&& other); //move constructor

    Sorted_List& operator=(Sorted_List const& other); //copy assignment operator
    Sorted_List& operator=(Sorted_List&& other); //move assignment operator

    bool is_empty() const;
    int size() const;
    std::string print_list() const;
    void remove(int value);
    void insert(int value);
};

#endif
