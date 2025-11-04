
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HeapVec : virtual public Heap<Data>, virtual protected SortableVector<Data>
{
  // Must extend Heap<Data>,
  // Could extend Vector<Data>

private:

  // ...

protected:

  using Container::size;
  using SortableVector<Data>::elements;

public:

  using SortableVector<Data>::Clear;
  using SortableVector<Data>::Front;
  using SortableVector<Data>::Back;
  using SortableVector<Data>::operator[];
  // Default constructor
  HeapVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  HeapVec(const TraversableContainer<Data> &); // A heap obtained from a TraversableContainer
  HeapVec(MappableContainer<Data> &&); // A heap obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HeapVec(const HeapVec &);

  // Move constructor
  HeapVec(HeapVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HeapVec()=default;

  /* ************************************************************************ */

  // Copy assignment
  HeapVec & operator=(const HeapVec &);

  // Move assignment
  HeapVec & operator=(HeapVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HeapVec &) const noexcept;
  inline bool operator!=(const HeapVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  bool IsHeap() const noexcept override; // Override Heap member

  void Heapify() noexcept override; // Override Heap member

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  inline void Sort() noexcept override; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!
  void OrdHeapify(ulong , ulong) noexcept;

  void HeapSort() noexcept;

};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
