
namespace lasd {

/* ************************************************************************** */

  // Specific member function
  template <typename Data>
  template <typename Accumulator>
  inline Accumulator TraversableContainer<Data>::Fold(FoldFun <Accumulator> funzione, Accumulator accumulatore) const
  {
    Traverse([funzione, &accumulatore] (const Data & curr) { accumulatore = funzione(curr, accumulatore);});
    return accumulatore;
  }

  // Specific member function (inherited from TestableContainer)
  template <typename Data>
  inline bool TraversableContainer<Data>::Exists(const Data & elemDaTrovare) const noexcept
  {
    bool trovato = false;
    Traverse([&trovato, elemDaTrovare] (const Data & curr) {if(curr==elemDaTrovare){trovato=true;}});
    return trovato;
  }

  /* ************************************************************************** */

  // Specific member function
  template <typename Data>
  template <typename Accumulator>
  inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> funzione, Accumulator accumulatore) const
  {
    PreOrderTraverse([funzione, &accumulatore] (const Data& curr) { accumulatore = funzione(curr, accumulatore);});
    return accumulatore;
  }

  // Specific member function (inherited from TraversableContainer)
  template <typename Data>
  inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const
  {
    PreOrderTraverse(funzione);
  }


  /* ************************************************************************** */  
  

  // Specific member function
  template <typename Data>
  template <typename Accumulator>
  inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> funzione, Accumulator accumulatore) const
  {
    PostOrderTraverse([funzione, &accumulatore] (const Data& curr) { accumulatore = funzione(curr, accumulatore);});
    return accumulatore;
  }

  // Specific member function (inherited from TraversableContainer)
  template <typename Data>
  inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const
  {
    PostOrderTraverse(funzione);
  }
  /* ************************************************************************** */

}
