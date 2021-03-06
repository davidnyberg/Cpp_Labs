#include <algorithm>
#include <iostream>

#include "list.h"

template<typename T>
void List<T>::insert(T const& d)
{
  first = new Link(d, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff
template<typename T>
typename List<T>::Link* List<T>::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

template<typename T>
List<T>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template<typename T>
List<T>::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template<typename T>
List<T>::List(List&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template<typename T>
List<T>& List<T>::operator=(List const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}

/*-------new methods------*/


template<typename T>
typename List<T>::Iterator List<T>::begin() const {
  //Returns an iterator to the beginning of the given container
    return Iterator{first};
}

template<typename T>
typename List<T>::Iterator List<T>::end() const {
  //Returns an iterator to the end after last element (nullptr)
    return Iterator{nullptr};
}
template<typename T>
bool List<T>::Iterator::operator!=(Iterator const& it) const {
  return current_position != it.current_position;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    if (current_position != nullptr)
      this->current_position = {current_position->next};
    return *this;
}

template<typename T>
T& List<T>::Iterator::operator*() const {
    return current_position->data;
}

//lists ostream operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
  for (auto it{list.begin()}; it != list.end(); ++it)
          os << *it << " ";
  return os;
}