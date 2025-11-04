
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQHeap : virtual public PQ<Data>, virtual protected HeapVec<Data>{
  // Must extend PQ<Data>,
  // Could extend HeapVec<Data>

private:

  // ...

protected:

  using Container::size;
  using HeapVec<Data>::elements;
  ulong capacity=0;
  using HeapVec<Data>::Heapify;
  using HeapVec<Data>::OrdHeapify;
  
  // ...

public:

  using HeapVec<Data>::operator[];
  using HeapVec<Data>::Front;
  using HeapVec<Data>::Back;

  // Default constructor
  PQHeap() : Vector<Data>(2){capacity=size; size=0;};

  /* ************************************************************************ */

  // Specific constructors
  PQHeap(const TraversableContainer<Data> &); // A priority queue obtained from a TraversableContainer
  PQHeap(MappableContainer<Data> &&); // A priority queue obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  PQHeap(const PQHeap<Data> &);

  // Move constructor
  PQHeap(PQHeap<Data> &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~PQHeap() = default;

  /* ************************************************************************ */

  // Copy assignment
  PQHeap & operator=(const PQHeap &);

  // Move assignment
  PQHeap & operator=(PQHeap &&) noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from PQ)

  const Data & Tip() const override; // Override PQ member (must throw std::length_error when empty)
  void RemoveTip() override; // Override PQ member (must throw std::length_error when empty)
  Data TipNRemove() override; // Override PQ member (must throw std::length_error when empty)

  void Insert(const Data &) override; // Override PQ member (Copy of the value)
  void Insert(Data &&) override; // Override PQ member (Move of the value)

  void Change(ulong, const Data &) override; // Override PQ member (Copy of the value)
  void Change(ulong, Data &&) override; // Override PQ member (Move of the value)

  void Clear() override;

protected:

  void DecidiResize();
  
  void HeapifyUp(ulong);
  void Resize(ulong) override;
  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
