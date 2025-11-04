
namespace lasd {

  /* ************************************************************************ */

  // Specific constructors
  template<typename Data>
  SetLst<Data>:: SetLst(const TraversableContainer<Data> & struttura)
  {
    struttura.Traverse([this](const Data & curr){Insert(curr);});
  } // A set obtained from a TraversableContainer

  template<typename Data>
  SetLst<Data>:: SetLst(MappableContainer<Data> && struttura)
  {
    struttura.Map([this] (Data & curr) {Insert(std::move(curr));});
  } // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  template<typename Data>
  SetLst<Data>:: SetLst(const SetLst & set) : List<Data>(set)
  {

  }

  // Move constructor
  template<typename Data>
  SetLst<Data>:: SetLst(SetLst && set) noexcept
  {
    std::swap(testa, set.testa);
    std::swap(coda, set.coda);
    std::swap(size, set.size);
  }

  /* ************************************************************************ */

  // Copy assignment
  template<typename Data>
  SetLst<Data> & SetLst<Data>:: operator=(const SetLst & set)
  {
    List<Data>::operator=(static_cast<const List<Data>&>(set));
    return (*this);
  }

  // Move assignment
  template<typename Data>
  SetLst<Data> & SetLst<Data>:: operator=(SetLst && set) noexcept
  {
    List<Data>::operator=(static_cast<List<Data>&&>(std::move(set)));
    return (*this);    
  }

  /* ************************************************************************ */

  // Comparison operators
  template<typename Data>
  bool SetLst<Data>:: operator==(const SetLst & set) const noexcept
  {
    return List<Data>::operator==(static_cast<const List<Data>&>(set)); 
  }

  template<typename Data>
  inline bool SetLst<Data>:: operator!=(const SetLst & set) const noexcept
  {
    return List<Data>::operator!=(static_cast<const List<Data>&>(set)); 
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  template<typename Data>
  const Data & SetLst<Data>:: Min() const 
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      return testa->dato;
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  Data SetLst<Data>:: MinNRemove()
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      return List<Data>::FrontNRemove(); 
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  void SetLst<Data>:: RemoveMin()
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      return List<Data>::RemoveFromFront(); 
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  const Data & SetLst<Data>:: Max() const
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      return coda->dato; 
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  Data SetLst<Data>:: MaxNRemove()
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      Data res=std::move(coda->dato);
      List<Data>::RemoveFromBack();
      return res; 
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  void SetLst<Data>:: RemoveMax()
  {
    if(testa==nullptr)
      throw std::length_error("insieme vuoto");
    else
    {
      return List<Data>::RemoveFromBack(); 
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  template<typename Data>
  const Data & SetLst<Data>:: Predecessor(const Data & dato) const
  {
    Node *tmp=BSearch(dato);
    if(tmp==nullptr)
    {
      throw std::length_error("non c'è predecessore");
    }
    else
    {
      return tmp->dato;
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  template<typename Data>
  Data SetLst<Data>:: PredecessorNRemove(const Data & dato)
  {
    Node* preprec=nullptr;
    Node* prec=BSearchPred(dato, preprec);

    if(prec==nullptr)
    {
      throw std::length_error("non c'è predecessore");
    }
    else
    {
      Data res=std::move(prec->dato);
      if(preprec==nullptr)
        List<Data>::RemoveFromFront();
      else if(prec->next==nullptr)
        List<Data>::RemoveFromBack();
      else
      {
        preprec->next=prec->next;
        prec->next=nullptr;
        delete prec;
        size--;
      }
      return res;
    }

  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  template<typename Data>
  void SetLst<Data>:: RemovePredecessor(const Data & dato)
  {
    Node* preprec=nullptr;
    Node* prec=BSearchPred(dato, preprec);

    if(prec==nullptr)
    {
      throw std::length_error("non c'è predecessore");
    }
    else
    {
      if(preprec==nullptr)
        List<Data>::RemoveFromFront();
      else if(prec->next==nullptr)
        List<Data>::RemoveFromBack();
      else
      {
        preprec->next=prec->next;
        prec->next=nullptr;
        delete prec;
        size--;
      }
    }
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  template<typename Data>
  const Data & SetLst<Data>:: Successor(const Data & dato) const
  {
    Node *tmp=BSearch(dato);
    if(size==0)
      throw std::length_error("non c'è successore");

    if(tmp==nullptr)
    {
      if(testa->dato==dato)
      {
        if(testa->next==nullptr)
          throw std::length_error("non c'è successore");
        else
          return testa->next->dato;
      }
      else
        return testa->dato;
    }
    else
    {
      if(tmp==coda)
        throw std::length_error("non c'è successore");
      else if(tmp->next->dato==dato)
      {
        if(tmp->next->next==nullptr)
         throw std::length_error("non c'è successore");
        else
         return tmp->next->next->dato;
      }
      else
        return tmp->next->dato;  
    }    
  } // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  template<typename Data>
  Data SetLst<Data>:: SuccessorNRemove(const Data & dato)
  {
    Node *tmp=BSearch(dato);
    if(size==0)
      throw std::length_error("non c'è successore");

    if(tmp==nullptr)
    {
      if(testa->dato==dato)
      {
        if(testa->next==nullptr)
          throw std::length_error("non c'è successore");
        else
        {
          Node* res=testa->next;
          Data remdat = res->dato;
          testa->next=res->next;
          res->next=nullptr;
          delete res;
          size--;
          return remdat;
        }
      }
      else
      {
        Data remdat = testa->dato;
        List<Data>::RemoveFromFront();
        return remdat;        
      }

    }
    else
    {
      if(tmp==coda)
        throw std::length_error("non c'è successore");
      else if(tmp->next->dato==dato)
      {
        if(tmp->next->next==nullptr)
         throw std::length_error("non c'è successore");
        else
        {
          Node* res=tmp->next->next;
          Data remdat = res->dato;          
          if(res==coda)
          {
            coda=tmp->next;
            coda->next=nullptr;
            res->next=nullptr;
            delete res;           
            size--; 
            return remdat;
          }
          else
          {
            tmp->next->next=res->next;
            res->next=nullptr;
            delete res;
            size--;
            return remdat;            
          }
        }
      }
      else
      {
        Node* res=tmp->next;
        Data remdat = res->dato;          
        if(res==coda)
        {
          coda=tmp;
          coda->next=nullptr;
          res->next=nullptr;
          delete res;
          size--;
          return remdat;
        }
        else
        {
          tmp->next=res->next;
          res->next=nullptr;
          delete res;
          size--;
          return remdat;            
        }
      }
    }    

  }// Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  template<typename Data>
  void SetLst<Data>:: RemoveSuccessor(const Data & dato)
  {

    Node *tmp=BSearch(dato);
    if(size==0)
      throw std::length_error("non c'è successore");

    if(tmp==nullptr)
    {
      if(testa->dato==dato)
      {
        if(testa->next==nullptr)
          throw std::length_error("non c'è successore");
        else
        {
          Node* res=testa->next;
          testa->next=res->next;
          res->next=nullptr;
          delete res;
          size--;
        }
      }
      else
      {
        List<Data>::RemoveFromFront();   
      }

    }
    else
    {
      if(tmp==coda)
        throw std::length_error("non c'è successore");
      else if(tmp->next->dato==dato)
      {
        if(tmp->next->next==nullptr)
         throw std::length_error("non c'è successore");
        else
        {
          Node* res=tmp->next->next;         
          if(res==coda)
          {
            coda=tmp->next;
            coda->next=nullptr;
            res->next=nullptr;
            delete res;          
            size--;  
          }
          else
          {
            tmp->next->next=res->next;
            res->next=nullptr;
            delete res;
            size--;           
          }
        }
      }
      else
      {
        Node* res=tmp->next;        
        if(res==coda)
        {
          coda=tmp;
          coda->next=nullptr;
          res->next=nullptr;
          delete res;
          size--;
        }
        else
        {
          tmp->next=res->next;
          res->next=nullptr;
          delete res;
          size--;            
        }
      }
    }    

  }// Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  template<typename Data>
  bool SetLst<Data>:: Insert(const Data & dato) 
  {
    if(size==0)
    {
      List<Data>::InsertAtFront(dato);
      return true;
    }
    Node *tmp=BSearch(dato);
    if((tmp==nullptr && testa->dato==dato)||(tmp!=nullptr && tmp->next!=nullptr && tmp->next->dato==dato))
      return false;
    else
    {
      if(tmp==nullptr)
        List<Data>::InsertAtFront(dato);
      else if(tmp->next==nullptr)
        List<Data>::InsertAtBack(dato);  

      else
      {
        Node* newNode=new Node(dato);
        newNode->next=tmp->next;
        tmp->next=newNode;
        size++;
      }
      return true;
    }
  } // Override DictionaryContainer member (copy of the value)

  template<typename Data>
  bool SetLst<Data>:: Insert(Data && dato)
  {
    if(size==0)
    {
      List<Data>::InsertAtFront(std::move(dato));
      return true;
    }
    Node *tmp=BSearch(dato);
    if((tmp==nullptr && testa->dato==dato)||(tmp!=nullptr && tmp->next!=nullptr && tmp->next->dato==dato))
      return false;
    else
    {
      if(tmp==nullptr)
        List<Data>::InsertAtFront(std::move(dato));
      else if(tmp->next==nullptr)
        List<Data>::InsertAtBack(std::move(dato));  

      else
      {
        Node* newNode=new Node(std::move(dato));
        newNode->next=tmp->next;
        tmp->next=newNode;
        size++;
      }
      return true;
    }
  } // Override DictionaryContainer member (move of the value)

  template<typename Data>
  bool SetLst<Data>:: Remove(const Data & dato)
  {
    if(size==0)
      return false;

    Node *tmp=BSearch(dato);
    if(tmp==nullptr)
    {
      if(testa->dato==dato)
      {
        List<Data>::RemoveFromFront();
        return true;
      }
      return false;
    }
    else if(tmp->next!=nullptr && tmp->next->dato==dato)
    {
      Node* rem=tmp->next;
      if(tmp->next==coda)
      {
        coda=tmp;
        coda->next=nullptr;
        delete rem;
        size--;
        return true;
      }
      tmp->next=rem->next;
      rem->next=nullptr;
      delete rem;
      size--;
      return true;
    }
    else
      return false;
  } // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)
  template<typename Data>
  const Data & SetLst<Data>:: operator[](const ulong elem) const
  {
    return List<Data>::operator[](elem); 
  } // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)
  template<typename Data>
  bool SetLst<Data>:: Exists(const Data & dato) const noexcept
  {
    if(size==0)
      return false;
  
    Node *tmp=BSearch(dato);
    if(tmp==nullptr)
      return (testa->dato==dato);
    else if(tmp->next!=nullptr && tmp->next->dato==dato)
      return true;
    else
      return false;
  } // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  template<typename Data>
  void SetLst<Data>:: Clear()
  {
    List<Data>::Clear();
  } // Override ClearableContainer member

  /* ************************************************************************** */

  template<typename Data>
  typename List<Data>::Node* SetLst<Data>:: BSearch(const Data & dato) const
  {
    Node*tmp1=testa;
    Node*tmp2=testa;
    Node*prec2=nullptr;
    Node*prec1=nullptr;
    if(size==0)
      return nullptr;
    ulong q;
    
    ulong numelem=size;

    while(numelem>0)
    {
      q=numelem/2;
      prec1=prec2;
      tmp1=tmp2;

      for(ulong i=1; i<=q; i++)
      {
        prec2=tmp2;
        tmp2=tmp2->next;
      }
        if(tmp2->dato==dato)
          return prec2;
        else if (tmp2->dato<dato)
        {
          numelem=numelem-q-1;
          prec2=tmp2;
          tmp2=tmp2->next;;
        }
        else
        {
          numelem=q;
          prec2=prec1;
          tmp2=tmp1; 
        }        
    }
    return prec2;
  }

  template<typename Data>
  typename List<Data>::Node* SetLst<Data>:: BSearchPred(const Data & dato, Node*& preprec2) const
  {
    Node*tmp1=testa;
    Node*tmp2=testa;
    Node*prec2=nullptr;
    Node*prec1=nullptr;
    Node*preprec1=nullptr;
    if(size==0)
      return nullptr;
    ulong q;
    
    ulong numelem=size;

    while(numelem>0)
    {
      q=numelem/2;
      preprec1=preprec2;
      prec1=prec2;
      tmp1=tmp2;

      for(ulong i=1; i<=q; i++)
      {
        preprec2=prec2;
        prec2=tmp2;
        tmp2=tmp2->next;
      }
      if(tmp2->dato==dato)
        return prec2;
      else if (tmp2->dato<dato)
      {
        numelem=numelem-q-1;
        preprec2=prec2;
        prec2=tmp2;
        tmp2=tmp2->next;
      }
      else
      {
        numelem=q;
        preprec2=preprec1;
        prec2=prec1;
        tmp2=tmp1; 
      }        
    }    
    return prec2;
  }
}
