
namespace lasd {

    /* ************************************************************************** */
    // Specific constructors
    template<typename Data>
    inline List<Data>:: Node::Node(const Data & val)
    {
        dato=val;
    }


    template <typename Data>
    inline List<Data>:: Node::Node(Data && val) noexcept
    {
        dato = std::move(val);
    }

    /* ********************************************************************** */

    // Copy constructor
    template <typename Data>
    inline List<Data>:: Node::Node(const Node & nodo)
    {
        dato=nodo.dato;
    }

    //move constructor
    template <typename Data>
    inline List<Data>:: Node::Node(Node && nodo) noexcept
    {
        std::swap(dato, nodo.dato);
        std::swap(next, nodo.next);
    }

    //destructor
    template <typename Data>
    List<Data>:: Node:: ~Node()
    {
        delete next;
    }

    //comparison operator
    template <typename Data>
    bool List<Data>:: Node:: operator==(const Node & nodo) const noexcept
    {
        if((nodo.next ==nullptr && next==nullptr && nodo.dato==dato )||( nodo.next!=nullptr && next!=nullptr && nodo.dato==dato && *nodo.next==*next))
            return true;
        else
            return false;
    }


    template <typename Data>
    inline bool List<Data>:: Node:: operator!=(const Node & nodo) const noexcept
    {
        return !(*this==nodo);
    }

    /* ********************************************************************** */

    //List

    //From TraversableContainer costructor

    //constructor from Traversble container
    template <typename Data>
    List<Data>:: List(const TraversableContainer<Data> & struttura)
    {
        struttura.Traverse([this](const Data & curr){InsertAtBack(curr);});
    }

    //constructor from Mappable container
    template <typename Data>
    List<Data>:: List(MappableContainer<Data> && struttura)
    {
        struttura.Map([this](Data & curr){InsertAtBack(std::move(curr));});
    }

    // Copy constructor
    template <typename Data>
    List<Data>:: List(const List & lista)
    {
        if(lista.testa!=nullptr)
        {
            Node* tmp=lista.testa;
            while(tmp!=nullptr)
            {
                InsertAtBack(tmp->dato);
                tmp=tmp->next;
            }
        }
        size=lista.size;
    }

    // Move constructor
    template <typename Data>
    List<Data>:: List(List && lista) noexcept
    {
        std::swap(testa, lista.testa);
        std::swap(coda, lista.coda);
        std::swap(size, lista.size);
    }

    // Destructor
    template <typename Data>
    List<Data>:: ~List()
    {
        delete testa;
    }

    //Copy assignment
    template <typename Data>
    List<Data> & List<Data>:: operator=(const List & lista)
    {
        if(lista.testa!=nullptr)
        {
            if(lista.size>=size)
            {
                Node* tmp1=lista.testa;
                Node* tmp2=testa;
                ulong i=0;
                for(i=0; i<size; i++)
                {
                    tmp2->dato=tmp1->dato;
                    tmp1=tmp1->next;
                    tmp2=tmp2->next;
                }
                while(tmp1!=nullptr)
                {
                    InsertAtBack(tmp1->dato);
                    tmp1=tmp1->next;
                }
            }
            else
            {
                Node* tmp1=lista.testa;
                Node* tmp2=testa;
                while(tmp1!=nullptr)
                {
                    tmp2->dato=tmp1->dato;
                    if(tmp1->next==nullptr)
                        coda=tmp2;
                    tmp1=tmp1->next;            
                    tmp2=tmp2->next;
                }       
                delete tmp2;
                coda->next=nullptr;
            }

            size=lista.size;
        }
        else
        Clear();
        return *this;
    }

    // Move assignment
    template <typename Data>
    List<Data> & List<Data>:: operator=(List && lista)noexcept
    {
        std::swap(size, lista.size);
        std::swap(testa, lista.testa);
        std::swap(coda, lista.coda);

        return *this;
    }

    // Comparison operators
    template <typename Data>
    bool List<Data>:: operator==(const List & lista) const noexcept
    {
        if(size != lista.size)
        {
            return false;
        }
        else
        {
            if(testa==nullptr)
                return true;
            return (*testa==*lista.testa);
        }

    }


    template <typename Data>
    inline bool List<Data>:: operator!=(const List & lista) const noexcept
    {
        return !(*this==lista);
    }

    // Specific member functions

    // Copy of the value
    template <typename Data>
    void List<Data>:: InsertAtFront(const Data & val)
    {
        Node* nodo = new Node(val);
        if(coda==nullptr)
        {
            coda=nodo;
        }
        nodo->next=testa;
        testa=nodo;

        size++;
    } 


    // Move of the value
    template <typename Data>
    void List<Data>:: InsertAtFront(Data && val)
    {
        Node* nodo = new Node(std::move(val));
        if(coda==nullptr)
        {
        coda=nodo;
        }
        nodo->next=testa;
        testa=nodo;
        size++;
    }

    template <typename Data>
    void List<Data>:: RemoveFromFront()
    {
        if(testa==nullptr)
        {
            throw std::length_error("Lista vuota");
        }

        Node* tmp= testa;
        if (testa!=coda)
        {   
            testa = testa->next;
            tmp->next=nullptr;
        }
        else
        {
            testa=nullptr;
            coda=nullptr;
        }
        size--;      
        delete tmp;   
    } // (must throw std::length_error when empty)



    template <typename Data>
    Data List<Data>:: FrontNRemove()
    {
        if(testa==nullptr)
        {
            throw std::length_error("Lista vuota");
        }

        Node* tmp=testa;
        Data res= std::move(testa->dato);
        if (testa!=coda)
        {   
            testa = testa->next;
            tmp->next=nullptr;
        }
        else
        {
            testa=nullptr;
            coda=nullptr;
        }
        delete tmp;
        size--;      
        return res;   
    } // (must throw std::length_error when empty)



    // Copy of the value
    template <typename Data>
    void List<Data>:: InsertAtBack(const Data & val)
    {
        Node* nodo = new Node(val);
        if(testa!=nullptr)
        {
            coda->next=nodo;
            coda=nodo;
        }
        else
        {
            testa=nodo;
            coda=nodo;
        }
        size++;
    } 

    // Move of the value
    template <typename Data>
    void List<Data>:: InsertAtBack(Data && val)
    {
        Node* nodo = new Node(std::move(val));
        if(testa!=nullptr)
        {
            coda->next=nodo;
            coda=nodo;
        }
        else
        {
            testa=nodo;
            coda=nodo;
        }
        size++;
    } 

    //RemoveFromBack
    template <typename Data>
    void List<Data>:: RemoveFromBack()
    {
        if(testa==nullptr)
        {
            throw std::length_error("Lista vuota");
        }

        Node* tmp= testa;
        if (testa!=coda)
        {   
            while(tmp->next!=coda)
            {
                tmp=tmp->next;
            }
            coda=tmp;
            tmp=tmp->next;
            coda->next=nullptr;        
        }
        else
        {
            testa=nullptr;
            coda=nullptr;
        }
        size--;      
        delete tmp;   
    } // (must throw std::length_error when empty)

    template <typename Data>
    Data List<Data>:: BackNRemove()
    {
        if(testa==nullptr)
        {
            throw std::length_error("Lista vuota");
        }

        Data res=std::move(coda->dato);
        RemoveFromBack();     
        return res;   
    } // (must throw std::length_error when empty)


    // Specific member functions (inherited from MutableLinearContainer)

    template <typename Data>
    Data & List<Data>:: operator[](const ulong elem)
    {
        Node* tmp=testa;
        ulong i=0;
        while(tmp!=nullptr)
        {
            if(i==elem)
            {
                return tmp->dato;
            }
            else
            {
                i++;
                tmp=tmp->next;
            }
        }
        throw std::out_of_range("Numero inserito più grande della dimensione della lista");
    }

    template <typename Data>
    inline Data & List<Data>:: Front()
    {
        if(testa!=nullptr)
        {
            return testa->dato;
        }
        throw std::length_error("Lista vuota");
    }

    template <typename Data>
    inline Data & List<Data>:: Back()
    {
        if(coda!=nullptr)
        {
            return coda->dato;
        }
        throw std::length_error("Lista vuota");

    }

    // Specific member functions (inherited from LinearContainer)

    template <typename Data>
    const Data & List<Data>:: operator[](const ulong elem) const
    {
        Node* tmp=testa;
        ulong i=0;
        while(tmp!=nullptr)
        {
            if(i==elem)
            {
                return tmp->dato;
            }
            else
            {
                i++;
                tmp=tmp->next;
            }
        }
        throw std::out_of_range("Numero inserito più grande della dimensione della lista");
    }

    template <typename Data>
    inline const Data & List<Data>:: Front() const
    {
        if(testa!=nullptr)
        {
            return testa->dato;
        }
        throw std::length_error("Lista vuota");
    }

    template <typename Data>
    inline const Data & List<Data>:: Back() const
    {
        if(coda!=nullptr)
        {
            return coda->dato;
        }
        throw std::length_error("Lista vuota");    
    }

    template <typename Data>
    inline void List<Data>:: Map(MapFun funzione)
    {
        PreOrderMap(funzione);
    }

    template <typename Data>
    void List<Data>:: PreOrderMap(MapFun funzione)
    {
        Node* tmp=testa;
        while(tmp!=nullptr)
        {
            funzione(tmp->dato);
            tmp=tmp->next;
        }

    }

    template <typename Data>
    inline void List<Data>:: PostOrderMap(MapFun funzione)
    {
        PostOrderMap(funzione, testa);
    }

    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun funzione) const
    {
        PreOrderTraverse(funzione);
    }

    template <typename Data>
    void List<Data>:: PreOrderTraverse(TraverseFun funzione) const
    {
        Node* tmp=testa;
        while(tmp!=nullptr)
        {
            funzione(tmp->dato);
            tmp=tmp->next;
        }
    }

    template <typename Data>
    inline void List<Data>:: PostOrderTraverse(TraverseFun funzione) const
    {
        PostOrderTraverse(funzione, testa);
    }

    template <typename Data>
    void List<Data>:: Clear()
    {
        delete testa;
        testa=nullptr;
        coda=nullptr;
        size=0;
    }

    /* ************************************************************************** */

    template <typename Data>
    void List<Data>:: PostOrderMap(MapFun funzione, Node* tmp)
    {
        if(tmp!=nullptr)
        {
            PostOrderMap(funzione, tmp->next);
            funzione(tmp->dato);
        }
    }

    template <typename Data>
    void  List<Data>:: PostOrderTraverse(TraverseFun funzione, const Node* tmp) const
    {
        if(tmp!=nullptr)
        {
            PostOrderTraverse(funzione, tmp->next);
            funzione(tmp->dato);
        }
    }

    /* ************************************************************************** */

}