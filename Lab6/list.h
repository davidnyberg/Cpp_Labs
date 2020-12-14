#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>


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

  // Suitable place to add things...
  class Iterator {
    public:
      friend class List;

      Iterator (Link* link) : current_position(link) {}

      bool const operator!=(Iterator const it);
      Iterator& operator++();
      T& operator*() const;


    private:
      Link* current_position{nullptr};

  };

    
      Iterator const begin();
      Iterator const end();

};

#include "list.cc"
#endif
