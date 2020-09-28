

/*
how to implement this whole lab is basically in the slides le4
https://www.ida.liu.se/~TDDE18/current/slides/slides/TDDE18.726G77.le4.pdf
*/

class Sorted_List {

public:
    Sorted_List(); //constructor
    ~Sorted_List(); //destructor
    Sorted_List(Sorted_List const& other); //copy constructor
    Sorted_List(Sorted_List&& other); //move constructor

    Sorted_List& operator=(Sorted_List const& other); //copy assignment operator
    Sorted_List operator=(Sorted_List&& other); //move assignment operator

    void remove();
    void insert();

private:
    struct Node {
        int value{};
        //pointer to next node;
        Node * next;
    };

};