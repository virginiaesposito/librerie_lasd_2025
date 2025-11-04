#include <cmath>
namespace lasd 
{

    /* ************************************************************************ */

    // Specific constructors
    template<typename Data>
    SetVec<Data>:: SetVec(const TraversableContainer<Data> & struttura): Vector<Data>(struttura.Size())
    {
        capacity=size;
        size=0;
        struttura.Traverse([this] (const Data & curr) {Insert(curr);});
    } // A set obtained from a TraversableContainer

    template<typename Data>
    SetVec<Data>:: SetVec(MappableContainer<Data> && struttura): Vector<Data>(struttura.Size())
    {
        capacity=size;
        size=0;        
        struttura.Map([this] (Data & curr) {Insert(std::move(curr));});
    } // A set obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    template<typename Data>
    SetVec<Data>:: SetVec(const SetVec & set): Vector<Data>(set.capacity)
    {
        capacity=size;
        testa=set.testa;
        size=set.size;
        for(ulong i=0; i<size; i++)
        {
            (*this)[i]=set[i];
        }
    }

    // Move constructor
    template<typename Data>
    SetVec<Data>:: SetVec(SetVec&& set) noexcept
    {
        std :: swap(testa, set.testa);
        std :: swap(capacity, set.capacity);
        std :: swap(size, set.size);
        std :: swap(elements, set.elements);
    }

    /* ************************************************************************ */
    // Copy assignment
    template<typename Data>
    SetVec<Data> & SetVec<Data>:: operator=(const SetVec & set)
    {
        SetVec<Data> * tset = new SetVec<Data>(set);
        std :: swap(*tset, *this);
        delete tset;
        return *this;
    }

    // Move assignment
    template<typename Data>
    SetVec<Data> &  SetVec<Data>:: operator=(SetVec && set) noexcept
    {
        std :: swap(size, set.size);
        std :: swap(elements, set.elements);
        std :: swap(testa, set.testa);
        std :: swap(capacity, set.capacity);

        return *this;
    }

    /* ************************************************************************ */

    // Comparison operators
    template<typename Data>
    bool SetVec<Data>:: operator==(const SetVec & set) const noexcept
    {
        if(size==set.size)
        {
            for(ulong i=0; i<size; i++)
            {
                if((*this)[i]!=set[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    template<typename Data>
    inline bool SetVec<Data>:: operator!=(const SetVec & set) const noexcept
    {
        return !(*this==set);
    }

    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    template<typename Data>
    const Data & SetVec<Data>:: Min() const
    {
        if(size==0)
        {
            throw std::length_error("insieme vuoto");
        }
        else
        {
            return (*this)[0];
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    Data SetVec<Data>:: MinNRemove()
    {
        if(size==0)
        {
            throw std::length_error("insieme vuoto");
        }
        else
        {
            Data res=std::move((*this)[0]);
            testa=(testa+1)% capacity;
            size--;
            decidiResize();
            return res;
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    void SetVec<Data>:: RemoveMin()
    {
        if(size==0)
        {
            throw std::length_error("vettore vuoto");
        }
        else
        {
            testa=(testa+1)% capacity;
            size--;
            decidiResize();           
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    const Data & SetVec<Data>:: Max() const
    {
        if(size==0)
        {
            throw std::length_error("vettore vuoto");
        }
        else
        {
            return (*this)[size-1]; 
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    Data SetVec<Data>:: MaxNRemove()
    {
        if(size==0)
        {
            throw std::length_error("vettore vuoto");
        }
        else
        {
            Data res=std::move((*this)[size-1]);
            if(size==1)
            {
                testa=0;
            }
            size--;
            decidiResize();
            return res;
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    void SetVec<Data>:: RemoveMax()
    {
        if(size==0)
        {
            throw std::length_error("vettore vuoto");
        }
        else
        {
            if(size==1)  
            {
                testa=0;
            }
            size--;
            decidiResize(); 
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

    template<typename Data>
    const Data & SetVec<Data>:: Predecessor(const Data & dato) const
    {            
        ulong pos = BSearch(dato);
        if(pos==0)
        {
            throw std::length_error("non c'è predecessore");
        }
        else
        {
            return (*this)[pos-1];
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    template<typename Data>
    Data SetVec<Data>:: PredecessorNRemove(const Data & dato)
    {
        ulong pos = BSearch(dato);
        if(pos==0)
        {
            throw std::length_error("non c'è predecessore");
        }
        else
        {
            Data res=std::move((*this)[pos-1]);
            if(pos-1==0) 
            { 
                testa=(testa+1)% capacity; 
                size--;
            }
            else
            {
                removeIndex(pos-1);
            }
            decidiResize();
            return res;
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    template<typename Data>
    void SetVec<Data>:: RemovePredecessor(const Data & dato)
    {
        ulong pos = BSearch(dato);
        if(pos==0)
        {
            throw std::length_error("non c'è predecessore");
        }
        else
        {
            if(pos-1==0) 
            { 
                testa=(testa+1)% capacity; 
                size--;
            }
            else
            {
                removeIndex(pos-1);
            }
            decidiResize();
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    template<typename Data>
    const Data & SetVec<Data>:: Successor(const Data & dato) const
    {
        ulong pos = BSearch(dato);
        if(pos==size||((*this)[pos]==dato && pos==size-1))
        {
            throw std::length_error("non c'è successore");
        }
        else
        {
            if((*this)[pos]==dato)
            {
                return (*this)[pos+1];
            }
            else
            {
                return (*this)[pos];
            }
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    template<typename Data>
    Data SetVec<Data>:: SuccessorNRemove(const Data & dato)
    {
        ulong pos = BSearch(dato);
        if(pos==size||((*this)[pos]==dato && pos==size-1))
        {
            throw std::length_error("non c'è successore");
        }
        else
        {
            if((*this)[pos]==dato)
            {
                Data res=std::move((*this)[pos+1]);
                removeIndex(pos+1);
                decidiResize();
                return res;
            }
            else
            {
                Data res=std::move((*this)[pos]);
                if(pos==0)
                {
                    testa=(testa+1)% capacity;
                    size--;
                }
                else
                {
                    removeIndex(pos);
                } 
                decidiResize();
                return res;
            } 
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    template<typename Data>
    void SetVec<Data>:: RemoveSuccessor(const Data & dato)
    {
        ulong pos = BSearch(dato);
        if(pos==size||((*this)[pos]==dato && pos==size-1))
        {
            throw std::length_error("vettore vuoto");
        }
        else
        {
            if((*this)[pos]==dato)
            {
                removeIndex(pos+1);
                decidiResize();
            }
            else
            {
                if(pos==0)
                {
                    testa=(testa+1)% capacity;
                    size--;
                }
                else
                {
                    removeIndex(pos);
                    
                }
                decidiResize();
            }
        }
    } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    template<typename Data>
    bool SetVec<Data>:: Insert(const Data & dato)
    {

        ulong pos = BSearch(dato);
        if (pos!=size && (*this)[pos]==dato)
        {
            return false;
        }
        else
        {
            if(pos==0)
            {
                testa=(testa+capacity-1)%capacity;
                elements[testa]=dato;
                size++;
                decidiResize();
                return true;
            }
            else if(pos==size)
            {
                size++;
                (*this)[size-1]=dato;
                decidiResize();
                return true;                
            }
            ulong fisicalpos= (testa+pos)%capacity;
            if(pos>=(size/2))
            {
                shiftdx(pos, size);
                elements[fisicalpos]=dato;
            }
            else
            {
                shiftsx(0,pos-1);
                elements[(fisicalpos+capacity-1)%capacity]=dato;
            }              
            size++;
            decidiResize();
            return true;
        }

    } // Override DictionaryContainer member (copy of the value)

    template<typename Data>
    bool SetVec<Data>:: Insert(Data && dato)
    {
        ulong pos = BSearch(dato);
        if (pos!=size && (*this)[pos]==dato)
        {
            return false;
        }
        else
        {
            if(pos==0)
            {
                testa=(testa+capacity-1)%capacity;
                elements[testa]=std :: move(dato);
                size++;
                decidiResize();
                return true;
            }
            else if(pos==size)
            {
                size++;
                (*this)[size-1]=std :: move(dato);
                decidiResize();
                return true;                
            }
          
            ulong fisicalpos= (testa+pos)%capacity;
            if(pos>=(size/2))
            {
                shiftdx(pos, size);
                elements[fisicalpos]=std :: move(dato);
            }
            else
            {
                shiftsx(0,pos-1);
                elements[(fisicalpos+capacity-1)%capacity]=std :: move(dato);

            }  
            size++;
            decidiResize();
            return true;
        }
    } // Override DictionaryContainer member (move of the value)

    template<typename Data>
    bool SetVec<Data>:: Remove(const Data & dato)
    {
        if(size==0)
        {
            return false;
        }
        ulong pos = BSearch(dato);
        if (pos==size || (*this)[pos]!=dato )
        {
            return false;
        }
        else
        {
            removeIndex(pos);
            decidiResize();
            return true;
        }        
    } // Override DictionaryContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    template<typename Data>
    inline const Data & SetVec<Data>:: operator[](const ulong elem) const
    {
        if(elem<size)
        {
            return elements[(elem+testa)%capacity];
        }
        else   
            throw std::out_of_range("Indice non contenuto");
    } // Override LinearContainer member (must throw std::out_of_range when out of range)


    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    template<typename Data>
    bool SetVec<Data>:: Exists(const Data & dato) const noexcept
    {
        ulong pos = BSearch(dato);
        if(pos==size)
            return false;
            
        if((*this)[pos]==dato)
        {
            return true;
        }
        else
        {
            return false;
        }
    } // Override TestableContainer member

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    template<typename Data>
    void SetVec<Data>:: Clear()
    {
        delete[] elements;
        elements = new Data[2]{};
        size = 0;
        capacity=2;
        testa=0;
    } // Override ClearableContainer member

    // Auxiliary functions, if necessary!
    //SetVec(const ulong);

    template<typename Data>
    void SetVec<Data>:: decidiResize()
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

    template<typename Data>
    void SetVec<Data>:: Resize(ulong numelem)
    {
        Data * tmelements = new Data[numelem]{};
        for(ulong i=0; i<size; i++)
        {
            tmelements[i]=(*this)[i];
        }
        testa=0;

        capacity= numelem;
        std :: swap(elements, tmelements);

        delete[] tmelements;
        tmelements=nullptr;
    }

    template<typename Data>
    void SetVec<Data>:: removeIndex(ulong pos)
    {
        //se pos=size-1 devo solo diminuire la size
        if(pos!=0 && pos!=size-1)
        {
            if(pos>=(size/2))
            {
                shiftsx(pos+1, size-1);               
            }
            else
            {
                shiftdx(0, pos);
            }
        }
        else if(pos==0)
        {
            testa=(testa+1)%capacity;
        }
        size--;
    }
    template<typename Data>
    void SetVec<Data>:: decidiShift(ulong pos)
    {
        if(pos>=(size/2))
        {
            shiftdx(pos, size);
        }
        else
        {
            shiftsx(0,pos-1);
        }
    }

    template<typename Data>
    void SetVec<Data>:: shiftdx(ulong part, ulong arr)
    {
        ulong i=arr;
        if(arr==size)
        {
            elements[(testa+size)%capacity]=(*this)[size-1];
            i--;            
        }
        for(; i>part; i--)
        {
            (*this)[i]=(*this)[i-1];
        }
        if(part==0)
        {
            testa= (testa+1)%capacity;
        }
    }

    template<typename Data>
    void SetVec<Data>:: shiftsx(ulong part, ulong arr)
    {
        ulong i=part;
        if(part==0)
        {
            elements[(testa+capacity-1)%capacity]=(*this)[0];
            i++;            
        }
        for(; i<=arr; i++)
        {
            (*this)[i-1]=(*this)[i];
        }
        if(part==0)
        {
            testa= (testa+capacity-1)%capacity;
        } 
    }

    template<typename Data>
    ulong SetVec<Data>:: BSearch(const Data & dato) const
    {
        ulong i=0;
        ulong j=size;
        ulong q;

        while(i<j)
        {
            q=i+(j-i)/2;
            if((*this)[q]==dato)
            {
                return q;
            }
            else if ((*this)[q] <dato)
            {
                i=q+1;
            }
            else
            {
                j=q;
            }
        }
        return j;
    }

    template<typename Data>
    inline Data & SetVec<Data>:: operator[](const ulong elem)
    {
        if(elem<size)
        {
            return elements[(elem+testa)%capacity];
        }
        else   
            throw std::out_of_range("Indice non contenuto");    
    }



    /* ************************************************************************** */

}
