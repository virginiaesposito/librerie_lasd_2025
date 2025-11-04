
namespace lasd {

/* ************************************************************************** */

// Comparison operators
template <typename Data>
bool LinearContainer<Data>::operator== (const LinearContainer & struttura) const noexcept
{
    if(size==struttura.size)
    {
        for(ulong i=0; i<size; i++)
        {
            if((*this)[i]!=struttura[i])
                return false;
        }
        return true;
    }
    return false;
}

template <typename Data>
inline bool LinearContainer<Data>::operator!= (const LinearContainer & struttura) const noexcept
{
    return !(*this==struttura);
}

// Specific member functions
template <typename Data>
inline const Data & LinearContainer<Data>::Front() const
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return (*this)[0];
}

template <typename Data>
inline const Data & LinearContainer<Data>::Back() const
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return (*this)[size-1];
}

// Specific member function (inherited from TraversableContainer)
template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun funzione) const
{
    PreOrderTraverse(funzione);
}

// Specific member function (inherited from PreOrderTraversableContainer)
template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun funzione) const
{
    for(ulong i=0; i<size; i++)
    {
        funzione((*this)[i]);
    }
}

// Specific member function (inherited from PostOrderTraversableContainer)
template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun funzione) const
{
    for(ulong i=0; i<size; i++)
    {
        funzione((*this)[size-i-1]);
    }
}

/* ************************************************************************** */

// Specific member functions
template <typename Data>
inline Data & MutableLinearContainer<Data>::Front()
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return (*this)[0];
}

template <typename Data>
inline Data & MutableLinearContainer<Data>::Back()
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return (*this)[size-1];
}

// Specific member function (inherited from MappableContainer)
template <typename Data>
inline void MutableLinearContainer<Data>::Map(MapFun funzione)
{
    PreOrderMap(funzione);
}

// Specific member function (inherited from PreOrderMappableContainer)
template <typename Data>
inline void MutableLinearContainer<Data>::PreOrderMap(MapFun funzione)
{
    for(ulong i=0; i<size; i++)
    {
        funzione((*this)[i]);
    }
}

// Specific member function (inherited from PostOrderMappableContainer)
template <typename Data>
inline void MutableLinearContainer<Data>::PostOrderMap(MapFun funzione)
{
    for(ulong i=0; i<size; i++)
    {
        funzione((*this)[size-i-1]);
    }
}
/* ************************************************************************** */

// Specific member function
template <typename Data>
inline void SortableLinearContainer<Data>::Sort() noexcept
{
    InsertionSort();
}

// Auxiliary member functions
template <typename Data>
void SortableLinearContainer<Data>::InsertionSort() noexcept
{
    for (ulong i = 1; i < size; i++) {
        Data chiave = (*this)[i];
        ulong j = i;

        while (j > 0 && (*this)[j-1] > chiave) {
            (*this)[j] = (*this)[j-1];
            j--;
        }
        (*this)[j] = chiave;
    }
}


/* ************************************************************************** */
}

