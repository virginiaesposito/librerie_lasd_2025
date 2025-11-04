
namespace lasd {

/* ************************************************************************** */
  template <typename Data>
  HeapVec<Data>::HeapVec(const TraversableContainer<Data> & struttura) : Vector<Data>(struttura)
  {
    Heapify();
  } // A heap obtained from a TraversableContainer

  template <typename Data>
  HeapVec<Data>::HeapVec(MappableContainer<Data> && struttura) : Vector<Data>(std :: move(struttura))
  {
    Heapify();
  } // A heap obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  template <typename Data>
  HeapVec<Data>::HeapVec(const HeapVec & heap) : Vector<Data>(heap), SortableVector<Data>(heap)
  {

  }

  // Move constructor
  template <typename Data>
  HeapVec<Data>::HeapVec(HeapVec && heap) noexcept : Vector<Data>(std :: move(heap))
  {

  }

  /* ************************************************************************ */

  // Copy assignment
  template <typename Data>
  HeapVec<Data> & HeapVec<Data>::operator=(const HeapVec & vec)
  {
    SortableVector<Data>::operator=(static_cast<const SortableVector<Data>&>(vec));
    return (*this);
  }

  // Move assignment
  template <typename Data>
  HeapVec<Data> & HeapVec<Data>::operator=(HeapVec && vec) noexcept
  {
    SortableVector<Data>::operator=(static_cast<SortableVector<Data>&&>(std::move(vec)));
    return (*this);   
  }

  /* ************************************************************************ */

  // Comparison operators
  template <typename Data>
  bool HeapVec<Data>::operator==(const HeapVec & vec) const noexcept
  {
    return SortableVector<Data>::operator==(static_cast<const SortableVector<Data>&>(vec));
  }

  template <typename Data>
  inline bool HeapVec<Data>::operator!=(const HeapVec & vec) const noexcept
  {
    return !(*this == vec);
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  template <typename Data>
  bool HeapVec<Data>::IsHeap() const noexcept
  {
    if(size<=3)
    {
      for(ulong i=1; i<size; i++)
        if((*this)[0]<(*this)[i])
          return false;
    }
    else
    {
      for(ulong i=0; i<(size/2); i++)
        if( ( (2*i+1) < size && (*this)[i] < (*this)[2*i+1] ) || ( (2*i+2) < size && (*this)[i] < (*this)[2*i+2] ) )
          return false;
    }
    return true;
  } // Override Heap member

  template <typename Data>
  void HeapVec<Data>::Heapify() noexcept
  {
    for(ulong i=(size/2); i>0; i--)
    {
      OrdHeapify(size, i-1);
    }
  } // Override Heap member

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  template <typename Data>
  inline void HeapVec<Data>::Sort() noexcept
  {
    HeapSort();
  } 

  template <typename Data>
  void HeapVec<Data>::OrdHeapify(ulong n, ulong i) noexcept
  {
    ulong m=i;
    ulong j=2*i+1;
    ulong k=2*i+2;

    if(j<n && elements[m]<elements[j])
      m=j;
    if(k<n && elements[m]<elements[k])
      m=k;
    if(m!=i)
    {
      std::swap(elements[i], elements[m]);
      OrdHeapify(n, m);
    }
  }
  
  template <typename Data>
  void HeapVec<Data>::HeapSort() noexcept
  {
    Heapify();
    if(size!=0)
    {
      for(ulong i=(size-1); i>=1; i--)
      {
        std::swap(elements[0], elements[i]);
        OrdHeapify(i, 0);
      }
    }

  }

/* ************************************************************************** */

}
