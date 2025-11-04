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

void mySetVecInt(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetVec<int> Test:" << endl;
  try {
    lasd::Vector<int> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 6);
    SetAt(loctestnum, loctesterr, vec, true, 3, 5);
    SetAt(loctestnum, loctesterr, vec, true, 4, 0);
    SetAt(loctestnum, loctesterr, vec, true, 5, 2);
    SetAt(loctestnum, loctesterr, vec, true, 6, 4); 

    lasd::SetVec<int> setvec;
    Empty(loctestnum, loctesterr, setvec, true);
    Size(loctestnum, loctesterr, setvec, true, 0);
    GetAt(loctestnum, loctesterr, setvec, false, 1, 2);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    
    setvec.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setvec, true, 7);
    lasd::SetVec<int> setvec1(setvec);
    EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);
    Remove(loctestnum, loctesterr, setvec1, true, 4);
    Remove(loctestnum, loctesterr, setvec1, true, 5);
    Size(loctestnum, loctesterr, setvec1, true, 5);
    InsertC(loctestnum, loctesterr, setvec1, true, 4);
    InsertC(loctestnum, loctesterr, setvec1, false, 4);

    lasd::SetVec<int> setvec2 = setvec1;
    EqualSetVec(loctestnum, loctesterr, setvec2, setvec1, true);

    RemovePredecessor(loctestnum, loctesterr, setvec1, false, 0);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 7);
    Size(loctestnum, loctesterr, setvec1, true, 5);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 3);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setvec1, true, 4);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 19);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, -1);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setvec1, true, 2);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, false, 9);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, false, 3);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, 2);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    Size(loctestnum, loctesterr, setvec1, true, 1);
    InsertC(loctestnum, loctesterr, setvec1, true, -1);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    Min(loctestnum, loctesterr, setvec1, true, -1);
    MinNRemove(loctestnum, loctesterr, setvec1, true, -1);
    RemoveMin(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
    Empty(loctestnum, loctesterr, setvec1, true);
    Size(loctestnum, loctesterr, setvec1, true, 0);

    InsertC(loctestnum, loctesterr, setvec1, true, 100);
    InsertC(loctestnum, loctesterr, setvec1, true, 50);
    Max(loctestnum, loctesterr, setvec1, true, 100);
    RemoveMax(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    MaxNRemove(loctestnum, loctesterr, setvec1, true, 50);

    setvec.Clear();
    InsertM(loctestnum, loctesterr, setvec, true, 1);
    Remove(loctestnum, loctesterr, setvec, 1);
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, 1);
    Remove(loctestnum, loctesterr, setvec, 1);
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, 1);
    InsertC(loctestnum, loctesterr, setvec, true, 100);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    InsertAllC(loctestnum, loctesterr, setvec, false, vec);
    InsertSomeC(loctestnum, loctesterr, setvec, false, vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);
    RemoveSome(loctestnum, loctesterr, setvec, true, vec);
    Size(loctestnum, loctesterr, setvec, true, 1);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<int>);

    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetVec<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetVecDouble(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetVec<double> Test:" << endl;
  try {
    lasd::Vector<double> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3.3);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1.1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 6.6);
    SetAt(loctestnum, loctesterr, vec, true, 3, 5.5);
    SetAt(loctestnum, loctesterr, vec, true, 4, 0.1);
    SetAt(loctestnum, loctesterr, vec, true, 5, 2.2);
    SetAt(loctestnum, loctesterr, vec, true, 6, 4.4); 

    lasd::SetVec<double> setvec;
    Empty(loctestnum, loctesterr, setvec, true);
    Size(loctestnum, loctesterr, setvec, true, 0);
    GetAt(loctestnum, loctesterr, setvec, false, 1, 2.4);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    
    setvec.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setvec, true, 7);
    lasd::SetVec<double> setvec1(setvec);
    EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);
    Remove(loctestnum, loctesterr, setvec1, true, 4.4);
    Remove(loctestnum, loctesterr, setvec1, true, 5.5);
    Size(loctestnum, loctesterr, setvec1, true, 5);
    InsertC(loctestnum, loctesterr, setvec1, true, 4.3);
    InsertC(loctestnum, loctesterr, setvec1, false, 4.3);

    lasd::SetVec<double> setvec2 = setvec1;
    EqualSetVec(loctestnum, loctesterr, setvec2, setvec1, true);

    RemovePredecessor(loctestnum, loctesterr, setvec1, false, 0.0);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 7.0);
    Size(loctestnum, loctesterr, setvec1, true, 5);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 3.3);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setvec1, true, 4);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, 19.11);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, -1.123);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setvec1, true, 2);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, false, 9.12);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, false, 3.4);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, 2.2);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    Size(loctestnum, loctesterr, setvec1, true, 1);
    InsertC(loctestnum, loctesterr, setvec1, true, -1.123);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    Min(loctestnum, loctesterr, setvec1, true, -1.123);
    MinNRemove(loctestnum, loctesterr, setvec1, true, -1.123);
    RemoveMin(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    Empty(loctestnum, loctesterr, setvec1, true);
    Size(loctestnum, loctesterr, setvec1, true, 0);

    InsertC(loctestnum, loctesterr, setvec1, true, 100.54);
    InsertC(loctestnum, loctesterr, setvec1, true, 50.4);
    Max(loctestnum, loctesterr, setvec1, true, 100.54);
    RemoveMax(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    MaxNRemove(loctestnum, loctesterr, setvec1, true, 50.4);

    setvec.Clear();
    InsertM(loctestnum, loctesterr, setvec, true, 1.0);
    Remove(loctestnum, loctesterr, setvec, 1.0);
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, 1.1);
    Remove(loctestnum, loctesterr, setvec, 1.1);
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, 1.2);
    InsertC(loctestnum, loctesterr, setvec, true, 100.123);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    InsertAllC(loctestnum, loctesterr, setvec, true, vec);
    InsertSomeC(loctestnum, loctesterr, setvec, false, vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    RemoveSome(loctestnum, loctesterr, setvec, true, vec);
    Size(loctestnum, loctesterr, setvec, true, 2);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<double>);
    
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetVecString(uint & testnum, uint & testerr)
{

  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of SetVec<string> Test:" << endl;
  try {
    lasd::Vector<string> vec(7);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("D"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("G"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("F"));
    SetAt(loctestnum, loctesterr, vec, true, 4, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 5, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 6, string("E")); 

    lasd::SetVec<string> setvec;
    Empty(loctestnum, loctesterr, setvec, true);
    Size(loctestnum, loctesterr, setvec, true, 0);
    GetAt(loctestnum, loctesterr, setvec, false, 1, string("B"));
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    
    setvec.InsertAll(vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setvec, true, 7);
    lasd::SetVec<string> setvec1(setvec);
    EqualSetVec(loctestnum, loctesterr, setvec, setvec1, true);
    Remove(loctestnum, loctesterr, setvec1, true, string("E"));
    Remove(loctestnum, loctesterr, setvec1, true, string("F"));
    Size(loctestnum, loctesterr, setvec1, true, 5);
    InsertC(loctestnum, loctesterr, setvec1, true, string("E"));
    InsertC(loctestnum, loctesterr, setvec1, false, string("E"));

    lasd::SetVec<string> setvec2 = setvec1;
    EqualSetVec(loctestnum, loctesterr, setvec2, setvec1, true);

    RemovePredecessor(loctestnum, loctesterr, setvec1, false, string("A"));
    RemovePredecessor(loctestnum, loctesterr, setvec1, false, string(""));
    Size(loctestnum, loctesterr, setvec1, true, 6);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, string("D"));
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setvec1, true, 5);
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, string("ZZZ"));
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, string("0"));
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setvec1, true, 3);
    RemoveSuccessor(loctestnum, loctesterr, setvec1, false, string("Z"));
    RemoveSuccessor(loctestnum, loctesterr, setvec1, true, string("C"));
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    Size(loctestnum, loctesterr, setvec1, true, 2);
    InsertC(loctestnum, loctesterr, setvec1, true, string(""));
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    Min(loctestnum, loctesterr, setvec1, true, string(""));
    MinNRemove(loctestnum, loctesterr, setvec1, true, string(""));
    RemoveMin(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<string>);
    Empty(loctestnum, loctesterr, setvec1, false);
    Size(loctestnum, loctesterr, setvec1, true, 1);

    InsertC(loctestnum, loctesterr, setvec1, true, string("J"));
    InsertC(loctestnum, loctesterr, setvec1, true, string("F"));
    Max(loctestnum, loctesterr, setvec1, true, string("J"));
    RemoveMax(loctestnum, loctesterr, setvec1, true);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    MaxNRemove(loctestnum, loctesterr, setvec1, true, string("F"));

    setvec.Clear();
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    InsertM(loctestnum, loctesterr, setvec, true, string("A"));
    Remove(loctestnum, loctesterr, setvec, string("A"));
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, string("A"));
    Remove(loctestnum, loctesterr, setvec, string("A"));
    Empty(loctestnum, loctesterr, setvec, true);
    InsertC(loctestnum, loctesterr, setvec, true, string("A"));
    InsertC(loctestnum, loctesterr, setvec, true, string("Z"));
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    InsertAllC(loctestnum, loctesterr, setvec, false, vec);
    InsertSomeC(loctestnum, loctesterr, setvec, false, vec);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    RemoveSome(loctestnum, loctesterr, setvec, true, vec);
    Size(loctestnum, loctesterr, setvec, true, 1);
    Traverse(loctestnum, loctesterr, setvec, true, &TraversePrint<string>);
    
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetVec<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mySetVecTest(uint & testnum, uint & testerr)
{
  mySetVecInt(testnum, testerr);
  mySetVecDouble(testnum, testerr);
  mySetVecString(testnum, testerr);
  cout << endl << "Exercise 1B (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}