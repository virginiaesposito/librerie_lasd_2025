
#include <iostream>
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/set/set.hpp"

using namespace std;

void myListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<int> Test:" << endl;
  try {
    {
      lasd::List<int> list;
      lasd::List<int> list2;
      lasd::List<int> list3;
      Empty(loctestnum, loctesterr, list, true);
      Size(loctestnum, loctesterr, list, true, 0);
      Size(loctestnum, loctesterr, list, false, 1);
      list.Clear();
      Size(loctestnum, loctesterr, list, true, 0);

      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      GetFront(loctestnum, loctesterr, list, false, 0);
      GetBack(loctestnum, loctesterr, list, false, 0);
      SetAt(loctestnum, loctesterr, list, false, 1, 0);
      GetAt(loctestnum, loctesterr, list, false, 2, 0);
      RemoveFromFront(loctestnum, loctesterr, list, false);
      FrontNRemove(loctestnum, loctesterr, list, false, 0);
      RemoveFromBack(loctestnum, loctesterr, list, false);
      BackNRemove(loctestnum, loctesterr, list, false, 0);

      Exists(loctestnum, loctesterr, list, false, 0);

      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 0);

      
      SetAt(loctestnum, loctesterr, list, false, 0, 4);
      InsertAtBack(loctestnum, loctesterr, list, true, 2);
      InsertAtFront(loctestnum, loctesterr, list, true, 1);
        Size(loctestnum, loctesterr, list, true, 2);


      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 3);
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldMultiply<int>, 1, 2);
      Exists(loctestnum, loctesterr, list, true, 1);
      Exists(loctestnum, loctesterr, list, true, 2);
      Exists(loctestnum, loctesterr, list, false, 26);

      NonEqualLinear(loctestnum, loctesterr, list, list2, true);
      NonEqualList(loctestnum, loctesterr, list, list2, true);

      GetAt(loctestnum, loctesterr, list, true, 1, 2);
      GetFront(loctestnum, loctesterr, list, true, 1);
      SetFront(loctestnum, loctesterr, list, true, 3);
      InsertAtBack(loctestnum, loctesterr, list, true, 1);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
      SetBack(loctestnum, loctesterr, list, true, 26);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);

      Exists(loctestnum, loctesterr, list, true, 26);

      list2=list;
      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      list3=move(list);
      EqualLinear(loctestnum, loctesterr, list2, list3, true);
      EqualList(loctestnum, loctesterr, list2, list3, true);

      list.Clear();
      InsertAtBack(loctestnum, loctesterr, list, true, 1);
      InsertAtBack(loctestnum, loctesterr, list, true, 2);
      FrontNRemove(loctestnum, loctesterr, list, true, 1);
      BackNRemove(loctestnum, loctesterr, list, true, 2);
      Empty(loctestnum, loctesterr, list, true);

      lasd:: SortableVector<int> vec1(4);

      SetAt(loctestnum, loctesterr, vec1, true,0, 1);
      SetAt(loctestnum, loctesterr, vec1, true,1, 2);
      SetAt(loctestnum, loctesterr, vec1, true,2, 3);
      SetAt(loctestnum, loctesterr, vec1, true,3, 4);

      lasd::SortableVector<int> vec2(list);
      lasd::SortableVector<int> vecm2(move(list));
      EqualLinear(loctestnum, loctesterr, vec2, vecm2, true);

      lasd:: SetVec<int> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true, 5);
      InsertC(loctestnum, loctesterr, setvec1, true, 6);
      InsertC(loctestnum, loctesterr, setvec1, true, 7);
      InsertC(loctestnum, loctesterr, setvec1, true, 8);

      lasd::List<int> list5(setvec1);     
      EqualLinear(loctestnum, loctesterr, list5, setvec1, true);

      
      lasd:: SetLst<int> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true, 9);
      InsertC(loctestnum, loctesterr, setlist1, true, 10);
      InsertC(loctestnum, loctesterr, setlist1, true, 11);
      InsertC(loctestnum, loctesterr, setlist1, true, 12);
   
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void myListDouble(uint & testnum, uint & testerr) {  
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of List<double> Test:" << endl;
  try {
    {
      lasd::List<double> list;
      lasd::List<double> list2;
      lasd::List<double> list3;
      Empty(loctestnum, loctesterr, list, true);
      Size(loctestnum, loctesterr, list, true, 0);
      Size(loctestnum, loctesterr, list, false, 1);
      list.Clear();
      Size(loctestnum, loctesterr, list, true, 0);

      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      GetFront(loctestnum, loctesterr, list, false, 0.0);
      GetBack(loctestnum, loctesterr, list, false, 0.0);
      SetAt(loctestnum, loctesterr, list, false, 1, 0.0);
      GetAt(loctestnum, loctesterr, list, false, 2, 0.0);
      RemoveFromFront(loctestnum, loctesterr, list, false);
      FrontNRemove(loctestnum, loctesterr, list, false, 0.0);
      RemoveFromBack(loctestnum, loctesterr, list, false);
      BackNRemove(loctestnum, loctesterr, list, false, 0.0);

      Exists(loctestnum, loctesterr, list, false, 0.0);

      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 0.0);

      
      SetAt(loctestnum, loctesterr, list, false, 0, 4.8);
      InsertAtBack(loctestnum, loctesterr, list, true, 2.9);
      InsertAtFront(loctestnum, loctesterr, list, true, 1.9);
        Size(loctestnum, loctesterr, list, true, 2);


      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      Exists(loctestnum, loctesterr, list, true, 1.9);
      Exists(loctestnum, loctesterr, list, true, 2.9);
      Exists(loctestnum, loctesterr, list, false, 26.7);

      NonEqualLinear(loctestnum, loctesterr, list, list2, true);
      NonEqualList(loctestnum, loctesterr, list, list2, true);

      GetAt(loctestnum, loctesterr, list, true, 1, 2.9);
      GetFront(loctestnum, loctesterr, list, true, 1.9);
      SetFront(loctestnum, loctesterr, list, true, 3.8);
      InsertAtBack(loctestnum, loctesterr, list, true, 1.7);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      SetBack(loctestnum, loctesterr, list, true, 26.7);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);

      Exists(loctestnum, loctesterr, list, true, 26.7);

      list2=list;
      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      list3=move(list);
      EqualLinear(loctestnum, loctesterr, list2, list3, true);
      EqualList(loctestnum, loctesterr, list2, list3, true);

      list.Clear();
      InsertAtBack(loctestnum, loctesterr, list, true, 1.1);
      InsertAtBack(loctestnum, loctesterr, list, true, 2.2);
      FrontNRemove(loctestnum, loctesterr, list, true, 1.1);
      BackNRemove(loctestnum, loctesterr, list, true, 2.2);
      Empty(loctestnum, loctesterr, list, true);

      lasd:: SortableVector<double> vec1(4);

      SetAt(loctestnum, loctesterr, vec1, true,0, 1.2);
      SetAt(loctestnum, loctesterr, vec1, true,1, 2.3);
      SetAt(loctestnum, loctesterr, vec1, true,2, 3.4);
      SetAt(loctestnum, loctesterr, vec1, true,3, 4.5);

      lasd::SortableVector<double> vec2(list);
      lasd::SortableVector<double> vecm2(move(list));
      EqualLinear(loctestnum, loctesterr, vec2, vecm2, true);

      lasd:: SetVec<double> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true, 5.6);
      InsertC(loctestnum, loctesterr, setvec1, true, 6.7);
      InsertC(loctestnum, loctesterr, setvec1, true, 7.8);
      InsertC(loctestnum, loctesterr, setvec1, true, 8.9);

      lasd::List<double> list5(setvec1);     
      EqualLinear(loctestnum, loctesterr, list5, setvec1, true);

      
      lasd:: SetLst<double> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true, 9.1);
      InsertC(loctestnum, loctesterr, setlist1, true, 10.1);
      InsertC(loctestnum, loctesterr, setlist1, true, 11.1);
      InsertC(loctestnum, loctesterr, setlist1, true, 12.1);
   
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<string> Test:" << endl;
  try     {
      lasd::List<string> list;
      lasd::List<string> list2;
      lasd::List<string> list3;
      Empty(loctestnum, loctesterr, list, true);
      Size(loctestnum, loctesterr, list, true, 0);
      Size(loctestnum, loctesterr, list, false, 1);
      list.Clear();
      Size(loctestnum, loctesterr, list, true, 0);

      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      GetFront(loctestnum, loctesterr, list, false, string("A"));
      GetBack(loctestnum, loctesterr, list, false, string("A"));
      SetAt(loctestnum, loctesterr, list, false, 1, string("A"));
      GetAt(loctestnum, loctesterr, list, false, 2, string("A"));

      Exists(loctestnum, loctesterr, list, false, string("A"));

      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldStringConcatenate, string("inizio"), string("inizio"));
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldStringConcatenate, string("inizio"), string("inizio"));

      InsertAtBack(loctestnum, loctesterr, list, true, string("B"));
      InsertAtBack(loctestnum, loctesterr, list, true, string("A"));
      InsertAtFront(loctestnum, loctesterr, list, true, string("A"));

      Size(loctestnum, loctesterr, list, true, 3);

      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<string>);
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldStringConcatenate, string("inizio"), string("inizioABA"));
      Exists(loctestnum, loctesterr, list, true, string("A"));
      Exists(loctestnum, loctesterr, list, true, string("B"));
      Exists(loctestnum, loctesterr, list, false, string("C"));

      NonEqualLinear(loctestnum, loctesterr, list, list2, true);
      NonEqualList(loctestnum, loctesterr, list, list2, true);

      GetFront(loctestnum, loctesterr, list, true, string("A"));
      SetFront(loctestnum, loctesterr, list, true, string("D"));
      SetBack(loctestnum, loctesterr, list, true,string("Z"));

      Exists(loctestnum, loctesterr, list, true,string("Z"));

      list2=list;
      EqualLinear(loctestnum, loctesterr, list, list2, true);
      EqualList(loctestnum, loctesterr, list, list2, true);

      list3=move(list);
      EqualLinear(loctestnum, loctesterr, list2, list3, true);
      EqualList(loctestnum, loctesterr, list2, list3, true);

      list.Clear();
      InsertAtBack(loctestnum, loctesterr, list, true, string("A"));
      InsertAtBack(loctestnum, loctesterr, list, true, string("B"));
      FrontNRemove(loctestnum, loctesterr, list, true, string("A"));
      BackNRemove(loctestnum, loctesterr, list, true, string("B"));
      Empty(loctestnum, loctesterr, list, true);

      lasd:: SortableVector<string> vec1(4);

      SetAt(loctestnum, loctesterr, vec1, true,0, string("A"));
      SetAt(loctestnum, loctesterr, vec1, true,1, string("B"));
      SetAt(loctestnum, loctesterr, vec1, true,2, string("C"));
      SetAt(loctestnum, loctesterr, vec1, true,3, string("D"));

      lasd::SortableVector<string> vec2(list);
      lasd::SortableVector<string> vecm2(move(list));
      EqualLinear(loctestnum, loctesterr, vec2, vecm2, true);

      lasd:: SetVec<string> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true, string("E"));
      InsertC(loctestnum, loctesterr, setvec1, true, string("F"));
      InsertC(loctestnum, loctesterr, setvec1, true, string("G"));
      InsertC(loctestnum, loctesterr, setvec1, true, string("H"));

      lasd::List<string> list5(setvec1);     
      EqualLinear(loctestnum, loctesterr, list5, setvec1, true);

      
      lasd:: SetLst<string> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true, string("I"));
      InsertC(loctestnum, loctesterr, setlist1, true, string("L"));
      InsertC(loctestnum, loctesterr, setlist1, true, string("M"));
      InsertC(loctestnum, loctesterr, setlist1, true, string("N"));
   
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myListTest(uint & testnum, uint & testerr) {
  myListInt(testnum, testerr);
  myListDouble(testnum, testerr);
  myListString(testnum, testerr);
  cout << endl << "Exercise 1A (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}