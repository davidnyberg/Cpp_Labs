#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//template<typename T>
//class List; //forward declaration

//template<typename T> // declaration
//std::ostream& operator<<(std::ostream&, const List<T>&);

template<typename T>
class List
{
public:
  List();
  ~List() { delete first; }

  void insert(T const& d);
  
  List(List const&);
  List(List&&);
  List& operator=(List const&);
  List& operator=(List&&);

  //source: https://en.cppreference.com/w/cpp/language/friend
  template<typename T2>
  friend std::ostream& operator<<(std::ostream& os, const List&);

private:

  class Link
  {
  public:
    Link(T const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }
    
    friend class List;

    static Link* clone(Link const*);
    
  private:
    T data;
    Link* next;
  };
  
  Link* first;
  
public:

  using value_type = T;

  class Iterator {
    public:
      //lets List class access private member variables
      friend class List;

      bool operator!=(Iterator const& it) const;
      Iterator& operator++();
      T& operator*() const;


    private:
      //private constructor so only friend class(List) can create a list iterator
      Iterator (Link* link) : current_position(link) {}
      Link* current_position{nullptr};

  };

    Iterator begin() const;
    Iterator end() const;

};

#include "list.tcc"
#endif
