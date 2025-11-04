
namespace lasd {

/* ************************************************************************** */
// Specific member function

template <typename Data>
inline void PreOrderMappableContainer<Data> :: Map(MapFun funzione)
{
    PreOrderMap(funzione);
}

/* ************************************************************************** */
// Specific member function

template <typename Data>
inline void PostOrderMappableContainer<Data> :: Map(MapFun funzione)
{
    PostOrderMap(funzione);
}

/* ************************************************************************** */

}
