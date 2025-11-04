#include <iostream>
#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"
#include "../../../zlasdtest/container/dictionary.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/linear.hpp"
#include "../../../zlasdtest/vector/vector.hpp"
#include "../../../zlasdtest/list/list.hpp"
#include "../../../zlasdtest/set/set.hpp"

using namespace std;

void mySetListInt(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetList<int> Test:" << endl;
  try {
    lasd::Vector<int> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 6);
    SetAt(loctestnum, loctesterr, vec, true, 3, 5);
    SetAt(loctestnum, loctesterr, vec, true, 4, 0);
    SetAt(loctestnum, loctesterr, vec, true, 5, 2);
    SetAt(loctestnum, loctesterr, vec, true, 6, 4); 

    lasd::SetLst<int> setlst;
    Empty(loctestnum, loctesterr, setlst, true);
    Size(loctestnum, loctesterr, setlst, true, 0);
    GetAt(loctestnum, loctesterr, setlst, false, 1, 2);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    
    setlst.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setlst, true, 7);
    lasd::SetLst<int> setlst1(setlst);
    EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);
    Remove(loctestnum, loctesterr, setlst1, true, 4);
    Remove(loctestnum, loctesterr, setlst1, true, 5);
    Size(loctestnum, loctesterr, setlst1, true, 5);
    InsertC(loctestnum, loctesterr, setlst1, true, 4);
    InsertC(loctestnum, loctesterr, setlst1, false, 4);

    lasd::SetLst<int> setlst2 = setlst1;
    EqualSetLst(loctestnum, loctesterr, setlst2, setlst1, true);

    RemovePredecessor(loctestnum, loctesterr, setlst1, false, 0);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 7);
    Size(loctestnum, loctesterr, setlst1, true, 5);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 3);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setlst1, true, 4);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 19);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, -1);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setlst1, true, 2);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, false, 9);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, false, 3);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, 2);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setlst1, true, 1);
    InsertC(loctestnum, loctesterr, setlst1, true, -1);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    Min(loctestnum, loctesterr, setlst1, true, -1);
    MinNRemove(loctestnum, loctesterr, setlst1, true, -1);
    RemoveMin(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<int>);
    Empty(loctestnum, loctesterr, setlst1, true);
    Size(loctestnum, loctesterr, setlst1, true, 0);

    InsertC(loctestnum, loctesterr, setlst1, true, 100);
    InsertC(loctestnum, loctesterr, setlst1, true, 50);
    Max(loctestnum, loctesterr, setlst1, true, 100);
    RemoveMax(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    MaxNRemove(loctestnum, loctesterr, setlst1, true, 50);

    setlst.Clear();
    InsertM(loctestnum, loctesterr, setlst, true, 1);
    Remove(loctestnum, loctesterr, setlst, 1);
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, 1);
    Remove(loctestnum, loctesterr, setlst, 1);
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, 1);
    InsertC(loctestnum, loctesterr, setlst, true, 100);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    InsertAllC(loctestnum, loctesterr, setlst, false, vec);
    InsertSomeC(loctestnum, loctesterr, setlst, false, vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);
    RemoveSome(loctestnum, loctesterr, setlst, true, vec);
    Size(loctestnum, loctesterr, setlst, true, 1);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<int>);


    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetList<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetListDouble(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetList<double> Test:" << endl;
  try {
lasd::Vector<double> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3.3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1.1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 6.6);
    SetAt(loctestnum, loctesterr, vec, true, 3, 5.5);
    SetAt(loctestnum, loctesterr, vec, true, 4, 0.1);
    SetAt(loctestnum, loctesterr, vec, true, 5, 2.2);
    SetAt(loctestnum, loctesterr, vec, true, 6, 4.4); 

    lasd::SetLst<double> setlst;
    Empty(loctestnum, loctesterr, setlst, true);
    Size(loctestnum, loctesterr, setlst, true, 0);
    GetAt(loctestnum, loctesterr, setlst, false, 1, 2.4);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    
    setlst.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setlst, true, 7);
    lasd::SetLst<double> setlst1(setlst);
    EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);
    Remove(loctestnum, loctesterr, setlst1, true, 4.4);
    Remove(loctestnum, loctesterr, setlst1, true, 5.5);
    Size(loctestnum, loctesterr, setlst1, true, 5);
    InsertC(loctestnum, loctesterr, setlst1, true, 4.3);
    InsertC(loctestnum, loctesterr, setlst1, false, 4.3);

    lasd::SetLst<double> setlst2 = setlst1;
    EqualSetLst(loctestnum, loctesterr, setlst2, setlst1, true);

    RemovePredecessor(loctestnum, loctesterr, setlst1, false, 0.0);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 7.0);
    Size(loctestnum, loctesterr, setlst1, true, 5);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 3.3);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setlst1, true, 4);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, 19.11);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, -1.123);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setlst1, true, 2);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, false, 9.12);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, false, 3.4);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, 2.2);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setlst1, true, 1);
    InsertC(loctestnum, loctesterr, setlst1, true, -1.123);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    Min(loctestnum, loctesterr, setlst1, true, -1.123);
    MinNRemove(loctestnum, loctesterr, setlst1, true, -1.123);
    RemoveMin(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    Empty(loctestnum, loctesterr, setlst1, true);
    Size(loctestnum, loctesterr, setlst1, true, 0);

    InsertC(loctestnum, loctesterr, setlst1, true, 100.54);
    InsertC(loctestnum, loctesterr, setlst1, true, 50.4);
    Max(loctestnum, loctesterr, setlst1, true, 100.54);
    RemoveMax(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    MaxNRemove(loctestnum, loctesterr, setlst1, true, 50.4);

    setlst.Clear();
    InsertM(loctestnum, loctesterr, setlst, true, 1.0);
    Remove(loctestnum, loctesterr, setlst, 1.0);
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, 1.1);
    Remove(loctestnum, loctesterr, setlst, 1.1);
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, 1.2);
    InsertC(loctestnum, loctesterr, setlst, true, 100.123);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    InsertAllC(loctestnum, loctesterr, setlst, true, vec);
    InsertSomeC(loctestnum, loctesterr, setlst, false, vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    RemoveSome(loctestnum, loctesterr, setlst, true, vec);
    Size(loctestnum, loctesterr, setlst, true, 2);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<double>);
    
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetList<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetListString(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetList<string> Test:" << endl;
  try {
lasd::Vector<string> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("G"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("F"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 5, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 6, string("E")); 

    lasd::SetLst<string> setlst;
    Empty(loctestnum, loctesterr, setlst, true);
    Size(loctestnum, loctesterr, setlst, true, 0);
    GetAt(loctestnum, loctesterr, setlst, false, 1, string("B"));
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    
    setlst.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setlst, true, 7);
    lasd::SetLst<string> setlst1(setlst);
    EqualSetLst(loctestnum, loctesterr, setlst, setlst1, true);
    Remove(loctestnum, loctesterr, setlst1, true, string("E"));
    Remove(loctestnum, loctesterr, setlst1, true, string("F"));
    Size(loctestnum, loctesterr, setlst1, true, 5);
    InsertC(loctestnum, loctesterr, setlst1, true, string("E"));
    InsertC(loctestnum, loctesterr, setlst1, false, string("E"));

    lasd::SetLst<string> setlst2 = setlst1;
    EqualSetLst(loctestnum, loctesterr, setlst2, setlst1, true);

    RemovePredecessor(loctestnum, loctesterr, setlst1, false, string("A"));
    RemovePredecessor(loctestnum, loctesterr, setlst1, false, string(""));
    Size(loctestnum, loctesterr, setlst1, true, 6);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, string("D"));
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setlst1, true, 5);
    RemovePredecessor(loctestnum, loctesterr, setlst1, true, string("ZZZ"));
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, string("0"));
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setlst1, true, 3);
    RemoveSuccessor(loctestnum, loctesterr, setlst1, false, string("Z"));
    RemoveSuccessor(loctestnum, loctesterr, setlst1, true, string("C"));
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setlst1, true, 2);
    InsertC(loctestnum, loctesterr, setlst1, true, string(""));
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    Min(loctestnum, loctesterr, setlst1, true, string(""));
    MinNRemove(loctestnum, loctesterr, setlst1, true, string(""));
    RemoveMin(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst1, true, &TraversePrint<string>);
    Empty(loctestnum, loctesterr, setlst1, false);
    Size(loctestnum, loctesterr, setlst1, true, 1);

    InsertC(loctestnum, loctesterr, setlst1, true, string("J"));
    InsertC(loctestnum, loctesterr, setlst1, true, string("F"));
    Max(loctestnum, loctesterr, setlst1, true, string("J"));
    RemoveMax(loctestnum, loctesterr, setlst1, true);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    MaxNRemove(loctestnum, loctesterr, setlst1, true, string("F"));

    setlst.Clear();
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    InsertM(loctestnum, loctesterr, setlst, true, string("A"));
    Remove(loctestnum, loctesterr, setlst, string("A"));
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, string("A"));
    Remove(loctestnum, loctesterr, setlst, string("A"));
    Empty(loctestnum, loctesterr, setlst, true);
    InsertC(loctestnum, loctesterr, setlst, true, string("A"));
    InsertC(loctestnum, loctesterr, setlst, true, string("Z"));
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    InsertAllC(loctestnum, loctesterr, setlst, false, vec);
    InsertSomeC(loctestnum, loctesterr, setlst, false, vec);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    RemoveSome(loctestnum, loctesterr, setlst, true, vec);
    Size(loctestnum, loctesterr, setlst, true, 1);
    Traverse(loctestnum, loctesterr, setlst, true, &TraversePrint<string>);
    
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetList<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetListTest(uint & testnum, uint & testerr)
{
  mySetListInt(testnum, testerr);
  mySetListDouble(testnum, testerr);
  mySetListString(testnum, testerr);
  cout << endl << "Exercise 1B (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}