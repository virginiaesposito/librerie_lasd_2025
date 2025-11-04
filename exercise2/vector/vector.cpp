
namespace lasd {

/* ************************************************************************** */
// Specific constructors

template <typename Data>
Vector<Data> :: Vector(ulong dim) 
{
    size=dim;
    elements = new Data [size]{};
}

//from traversable constructor
template <typename Data>
Vector<Data> :: Vector(const TraversableContainer<Data> & struttura) : Vector(struttura.Size())
{
    ulong i=0;
    struttura.Traverse([this, &i] (const Data & curr) {elements[i++]=curr;});

}

//from mappable constructor
template <typename Data>
Vector<Data> :: Vector(MappableContainer<Data> && struttura) : Vector(struttura.Size())
{
    ulong i=0;
    struttura.Map([this, &i] (Data & curr) {elements[i++]=std::move(curr);});
}

//copy constructor
template <typename Data>
Vector<Data> :: Vector(const Vector & struttura) : Vector(struttura.Size())
{
    ulong i=0;
    for(i=0; i<size; i++)
    {
        elements[i]=struttura[i];
    }
}

// Move constructor
template <typename Data>
Vector<Data> :: Vector(Vector&& struttura) noexcept
{
    std :: swap(size, struttura.size);
    std :: swap(elements, struttura.elements);
}


template <typename Data>
Vector<Data> :: ~Vector()
{
    delete[] elements;
}

// Copy assignment
template <typename Data>
Vector<Data>& Vector<Data> :: operator=(const Vector & struttura) 
{
    Vector<Data> * tvett = new Vector<Data>(struttura);
    std :: swap(*tvett, *this);
    delete tvett;
    return *this;
}

// Move assignment
template <typename Data>
Vector<Data> &  Vector<Data> :: operator=(Vector && struttura) noexcept
{
    std :: swap(size, struttura.size);
    std :: swap(elements, struttura.elements);

    return *this;
}

// Comparison operators
template <typename Data>
bool Vector<Data> :: operator==(const Vector & struttura) const noexcept 
{
    if(size == struttura.size)
    {
        for(ulong i=0; i<size; i++)
        {
            if(elements[i]!=struttura[i])
                return false;
        }
        return true;
    }
    return false;
}

template <typename Data>
inline bool Vector<Data> :: operator!=(const Vector & struttura) const noexcept
{
     return !(*this==struttura);
}

// Specific member functions (inherited from MutableLinearContainer)
template <typename Data>
inline Data &   Vector<Data> :: operator[](ulong elem)
{
    if(elem<size)
    {
        return elements[elem];
    }
    else   
        throw std::out_of_range("Indice non contenuto");
}

template <typename Data>
inline Data & Vector<Data> :: Front()
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return elements[0];
}


template <typename Data>
inline Data &  Vector<Data> ::Back()
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return elements[size-1];

}

// Specific member functions (inherited from LinearContainer)
template <typename Data>
inline const Data & Vector<Data> :: operator[](ulong elem) const 
{
    if(elem<size)
    {
        return elements[elem];
    }
    else   
        throw std::out_of_range("Indice non contenuto");
}

template <typename Data>
inline const Data & Vector<Data> :: Front() const 
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return elements[0];
}

template <typename Data>
inline const Data & Vector<Data> :: Back() const 
{
    if (size==0)
    {
        throw std::length_error("Container vuoto");
    }
    else
        return elements[size-1];
}

// Specific member function (inherited from ResizableContainer)
template <typename Data>
void Vector<Data> :: Resize(ulong dim)
{
    if(dim==0)
        Clear();
    else if(size!=dim)
    {
        if(dim>size)
        {
            Data * tmelements = new Data[dim]{};
            for(ulong i=0; i<size; i++)
            {
                tmelements[i]=elements[i];
            }

            size= dim;
            std :: swap(elements, tmelements);

            delete[] tmelements;

        }
        else
        {

            Data * tmelements = new Data[dim]{};
            for(ulong i=0; i<dim; i++)
            {
                tmelements[i]=elements[i];
            }

            size= dim;
            std :: swap(elements, tmelements);

            delete[] tmelements;

        }
    }

}

// Specific member function (inherited from ClearableContainer)
template <typename Data>
void Vector<Data> :: Clear()
{
    delete[] elements;
    elements = nullptr;
    size = 0;
}
/* ************************************************************************** */

//specific constructor

template <typename Data>
SortableVector<Data> :: SortableVector(ulong dim) : Vector<Data>(dim)
{

}

//from traversable container
template <typename Data>
SortableVector<Data> :: SortableVector(const TraversableContainer<Data> & struttura) : Vector<Data>(struttura)
{
    
}

//from mappable container
template <typename Data>
SortableVector<Data> :: SortableVector(MappableContainer<Data> && struttura) : Vector<Data>(std :: move(struttura))
{
    
}

//copy constructor
template <typename Data>
SortableVector<Data> :: SortableVector(const SortableVector & struttura) : Vector<Data>(struttura)
{
    
}

//move constructor
template <typename Data>
SortableVector<Data> :: SortableVector(SortableVector && struttura) : Vector<Data>(std :: move(struttura))
{
    
}

//copy assignment
template <typename Data>
SortableVector<Data> & SortableVector<Data> :: operator=(const SortableVector & struttura)
{
    Vector<Data> :: operator=(struttura);
    return *this;
}

//move assigment
template <typename Data>
SortableVector<Data> & SortableVector<Data> :: operator=(SortableVector && struttura)noexcept
{
    Vector<Data>:: operator=(std :: move(struttura));
    return *this;
}

/* ************************************************************************** */

}
