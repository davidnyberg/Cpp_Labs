/*
how to implement this whole lab is basically in the slides le4
https://www.ida.liu.se/~TDDE18/current/slides/slides/TDDE18.726G77.le4.pdf

*/

class Sorted_List {

public:

    //constructor
    Sorted_List() : first{nullptr} {}
    //destructor
    ~Sorted_List() {
        //delete every node
    }
    //copy constructor
    Sorted_List(Sorted_List const& other) {
        //deep copy of lists
    }

    //move constructor
    Sorted_List(Sorted_List&& other) {
        //perform move by changing the pointers
    }

    //copy constructor
    Sorted_List& operator=(Sorted_List const& other) {
        //removes previous lists and deep copy the other one

        return *this; //derefence this pointer to return the current object
    }
    
    //move constructor
    Sorted_List& operator=(Sorted_List&& other) {
        //remove old content of list
        //move content from other to this object
    }


    void remove();
    void insert(int value) {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }

private:
    struct Node {
        int value{};
        //pointer to next node;
        Node* next;
    };
    Node* first{};

};