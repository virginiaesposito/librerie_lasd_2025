#include <cmath>
namespace lasd {

/* ************************************************************************** */

  template <typename Data>
  PQHeap<Data>::PQHeap(const TraversableContainer<Data> & struttura) : Vector<Data>(struttura), HeapVec<Data>(struttura)
  {
    capacity=size;
    if(size<2)
      Resize(2);
  }// A priority queue obtained from a TraversableContainer

  template <typename Data>
  PQHeap<Data>::PQHeap(MappableContainer<Data> && struttura) : Vector<Data>(std::move(struttura))
  {
    capacity=size;
    if(size<2)
      Resize(2);
    Heapify();
  } // A priority queue obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  template <typename Data>
  PQHeap<Data>::PQHeap(const PQHeap<Data> & heap) : Vector<Data>(heap), SortableVector<Data>(heap), HeapVec<Data>(heap)
  {
    capacity=size;
  }

  // Move constructor
  template <typename Data>
  PQHeap<Data>::PQHeap(PQHeap<Data> && heap) noexcept: Vector<Data>(std :: move(heap))
  {
    std::swap(capacity, heap.capacity);
  }

  /* ************************************************************************ */

  // Copy assignment
  template <typename Data>
  PQHeap<Data> & PQHeap<Data>::operator=(const PQHeap & heap)
  {
    PQHeap<Data> * theap = new PQHeap<Data>(heap);
    std :: swap(*theap, *this);
    delete theap;
    return *this;
  }

  // Move assignment
  template <typename Data>
  PQHeap<Data> & PQHeap<Data>::operator=(PQHeap && heap) noexcept
  {
    std :: swap(size, heap.size);
    std :: swap(elements, heap.elements);
    std :: swap(capacity,heap.capacity);
    return *this;
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from PQ)

  template <typename Data>
  const Data & PQHeap<Data>::Tip() const
  {
    if(size==0)
        throw std::length_error("Heap vuoto");
    else
        return (*this)[0];
  } // Override PQ member (must throw std::length_error when empty)

  template <typename Data>
  void PQHeap<Data>::RemoveTip()
  {
    if(size==0)
        throw std::length_error("Heap vuoto");
    else    
    {
        (*this)[0]=(*this)[size-1];
        size--;
        OrdHeapify(size, 0);   
        DecidiResize();        
    }
  } // Override PQ member (must throw std::length_error when empty)

  template <typename Data>
  Data PQHeap<Data>::TipNRemove()
  {
    if(size==0)
        throw std::length_error("Heap vuoto");
    else
    {
        Data res=std::move((*this)[0]);
        (*this)[0]=(*this)[size-1];        
        size--;
        OrdHeapify(size, 0);
        DecidiResize();        
        return res;        
    }
  }   // Override PQ member (must throw std::length_error when empty)

  template <typename Data>
  void PQHeap<Data>::Insert(const Data & dato)
  {
    DecidiResize();
    size++;
    (*this)[size-1]= dato;    
    HeapifyUp(size-1);
  } // Override PQ member (Copy of the value)

  template <typename Data>
  void PQHeap<Data>::Insert(Data && dato)
  {
    DecidiResize();
    size++;
    (*this)[size-1]=std::move(dato);    
    HeapifyUp(size-1);
  } // Override PQ member (Move of the value)

  template <typename Data>
  void PQHeap<Data>::Change(ulong pos, const Data & dato)
  {
    (*this)[pos]=dato;
    if(pos>0 && (*this)[(pos-1)/2]<dato)
      HeapifyUp(pos);
    else
      OrdHeapify(size, pos);  
  } // Override PQ member (Copy of the value)

  template <typename Data>
  void PQHeap<Data>::Change(ulong pos, Data && dato)
  {
    (*this)[pos]=std::move(dato);
    if(pos>0 && (*this)[(pos-1)/2]<dato)
        OrdHeapify(size, pos);
    else
        HeapifyUp(pos);
  } // Override PQ member (Move of the value)

  template <typename Data>
  void PQHeap<Data>:: DecidiResize()
  {
    double perc=static_cast<double>(100)/capacity;
    if(static_cast<double>(size+1)*perc>=90)
    {
        Resize(capacity*2);
    }
    else if(static_cast<double>(size)*perc<=25 && capacity>2)
    {
        Resize(ceil(static_cast<double>(capacity)/2));
    }
  }

  template <typename Data>
  void PQHeap<Data>::HeapifyUp(ulong pos)
  {
    ulong i=(pos-1)/2;
    while(pos>0)
    {
      if((*this)[i]<(*this)[pos])
      {
        std::swap((*this)[i], (*this)[pos]);
        pos=i;
        i=(i-1)/2;
      }
      else  
        pos=0; //mi fermo se non verificata la condizione
    }
  }


  template <typename Data>
  void PQHeap<Data>::Resize(ulong dim)
  {
    Data * tmelements = new Data[dim]{};
    for(ulong i=0; i<size; i++)
    {
      tmelements[i]=(*this)[i];
    }

    capacity= dim;
    std :: swap(elements, tmelements);

    delete[] tmelements;
    tmelements=nullptr;

  }

  template<typename Data>
  void PQHeap<Data>:: Clear()
  {
      delete[] elements;
      elements = new Data[2]{};
      size = 0;
      capacity=2;
  } 

  
/* ************************************************************************** */

}
