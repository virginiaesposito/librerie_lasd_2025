
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool DictionaryContainer<Data> :: InsertAll(const TraversableContainer<Data> & struttura)
{
    bool inserito = true;
    struttura.Traverse([&inserito, this] (const Data & curr) { if (Insert(curr) == false) {inserito = false;}});
    return inserito;
}

template <typename Data>
inline bool DictionaryContainer<Data> :: InsertAll(MappableContainer<Data> && struttura)
{
    bool inserito = true;
    struttura.Map([&inserito, this] (Data & curr) { if (Insert(std::move(curr))== false) {inserito = false;}});
    return inserito;
}

template <typename Data>
inline bool DictionaryContainer<Data> :: RemoveAll(const TraversableContainer<Data> & struttura)
{
    bool inserito = true;
    struttura.Traverse([&inserito, this] (const Data & curr) { if (Remove(curr) == false) {inserito = false;}});
    return inserito;
}

template <typename Data>
inline bool DictionaryContainer<Data> :: InsertSome(const TraversableContainer<Data> & struttura)
{
    bool inserito = false;
    struttura.Traverse([&inserito, this] (const Data & curr) { if (Insert(curr) == true) {inserito = true;}});
    return inserito;
}

template <typename Data>
inline bool DictionaryContainer<Data> :: InsertSome(MappableContainer<Data> && struttura)
{
    bool inserito = false;
    struttura.Map([&inserito, this] (Data & curr) { if (Insert(std::move(curr))== true) {inserito = true;}});
    return inserito;
}

template <typename Data>
inline bool DictionaryContainer<Data> :: RemoveSome(const TraversableContainer<Data> & struttura)
{
    bool inserito = false;
    struttura.Traverse([&inserito, this] (const Data & curr) { if (Remove(curr) == true) {inserito = true;}});
    return inserito;
}
/* ************************************************************************** */
}

