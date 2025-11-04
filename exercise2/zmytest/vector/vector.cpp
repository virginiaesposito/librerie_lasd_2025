
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

void myVectorInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<int> Test:" << endl;
  try {
    {
      lasd::SortableVector<int> vec;
      lasd::SortableVector<int> vec2;
      lasd::SortableVector<int> vec3(3);
      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);
      Size(loctestnum, loctesterr, vec, false, 1);
      vec.Clear();
      Size(loctestnum, loctesterr, vec, true, 0);

      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetFront(loctestnum, loctesterr, vec, false, 0);
      GetBack(loctestnum, loctesterr, vec, false, 0);
      SetAt(loctestnum, loctesterr, vec, false, 1, 0);
      GetAt(loctestnum, loctesterr, vec, false, 2, 0);

      Exists(loctestnum, loctesterr, vec, false, 0);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);

      vec.Resize(5);
      Size(loctestnum, loctesterr, vec, true, 5);
      SetAt(loctestnum, loctesterr, vec, true, 0, 4);
      SetAt(loctestnum, loctesterr, vec, false, 5, 4);
      SetAt(loctestnum, loctesterr, vec, true, 2, 4);
      SetAt(loctestnum, loctesterr, vec, true, 1, 6);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 14);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 1, 0);
      Exists(loctestnum, loctesterr, vec, true, 4);
      Exists(loctestnum, loctesterr, vec, true, 0);
      Exists(loctestnum, loctesterr, vec, false, 26);

      NonEqualLinear(loctestnum, loctesterr, vec, vec2, true);
      NonEqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetAt(loctestnum, loctesterr, vec, true, 3, 0);
      GetFront(loctestnum, loctesterr, vec, true, 4);
      SetFront(loctestnum, loctesterr, vec, true, 5);
      GetBack(loctestnum, loctesterr, vec, true, 0);
      SetBack(loctestnum, loctesterr, vec, true, 26);

      Exists(loctestnum, loctesterr, vec, true, 26);

      vec2=vec;
      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      vec3=move(vec);
      EqualLinear(loctestnum, loctesterr, vec2, vec3, true);
      EqualVector(loctestnum, loctesterr, vec2, vec3, true);

      vec.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      vec2.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

      vec2.Resize(2);
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

      lasd:: List<int> list1;

      InsertAtBack(loctestnum, loctesterr, list1, true, 1);
      InsertAtBack(loctestnum, loctesterr, list1, true, 2);
      InsertAtBack(loctestnum, loctesterr, list1, true, 3);
      InsertAtBack(loctestnum, loctesterr, list1, true, 4);

      lasd::SortableVector<int> vec4(list1);
      lasd::SortableVector<int> vecm4(move(list1));
      EqualLinear(loctestnum, loctesterr, vec4, list1, true);
      EqualLinear(loctestnum, loctesterr, vecm4, list1, true);

      lasd:: SetVec<int> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true, 5);
      InsertC(loctestnum, loctesterr, setvec1, true, 6);
      InsertC(loctestnum, loctesterr, setvec1, true, 7);
      InsertC(loctestnum, loctesterr, setvec1, true, 8);

      lasd::SortableVector<int> vec5(setvec1);     
      EqualLinear(loctestnum, loctesterr, vec5, setvec1, true);

      
      lasd:: SetLst<int> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true, 9);
      InsertC(loctestnum, loctesterr, setlist1, true, 10);
      InsertC(loctestnum, loctesterr, setlist1, true, 11);
      InsertC(loctestnum, loctesterr, setlist1, true, 12);

      lasd::SortableVector<int> vec6(setlist1);     
      EqualLinear(loctestnum, loctesterr, vec6, setlist1, true);       
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void myVectorDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<double> Test:" << endl;
  try {
    {
      lasd::SortableVector<double> vec;
      lasd::SortableVector<double> vec2;
      lasd::SortableVector<double> vec3(3);
      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);
      Size(loctestnum, loctesterr, vec, false, 1);
      vec.Clear();
      Size(loctestnum, loctesterr, vec, true, 0);

      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetFront(loctestnum, loctesterr, vec, false, 0.0);
      GetBack(loctestnum, loctesterr, vec, false, 0.0);
      SetAt(loctestnum, loctesterr, vec, false, 1, 0.0);
      GetAt(loctestnum, loctesterr, vec, false, 2, 0.0);

      Exists(loctestnum, loctesterr, vec, false, 0.0);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);

      vec.Resize(5);
      Size(loctestnum, loctesterr, vec, true, 5);
      SetAt(loctestnum, loctesterr, vec, true, 0, 4.1);
      SetAt(loctestnum, loctesterr, vec, false, 5, 4.2);
      SetAt(loctestnum, loctesterr, vec, true, 2, 4.3);
      SetAt(loctestnum, loctesterr, vec, true, 1, 6.5);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      Exists(loctestnum, loctesterr, vec, true, 0.0);
      Exists(loctestnum, loctesterr, vec, false, 26.3);

      NonEqualLinear(loctestnum, loctesterr, vec, vec2, true);
      NonEqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetAt(loctestnum, loctesterr, vec, true, 3, 0.0);
      GetFront(loctestnum, loctesterr, vec, true, 4.1);
      SetFront(loctestnum, loctesterr, vec, true, 5.1);
      GetBack(loctestnum, loctesterr, vec, true, 0.0);
      SetBack(loctestnum, loctesterr, vec, true, 26.3);

      Exists(loctestnum, loctesterr, vec, true, 26.3);

      vec2=vec;
      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      vec3=move(vec);
      EqualLinear(loctestnum, loctesterr, vec2, vec3, true);
      EqualVector(loctestnum, loctesterr, vec2, vec3, true);

      vec.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      vec2.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

      vec2.Resize(2);
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

      lasd:: List<double> list1;

      InsertAtBack(loctestnum, loctesterr, list1, true, 1.1);
      InsertAtBack(loctestnum, loctesterr, list1, true, 2.2);
      InsertAtBack(loctestnum, loctesterr, list1, true, 3.3);
      InsertAtBack(loctestnum, loctesterr, list1, true, 4.4);

      lasd::SortableVector<double> vec4(list1);
      lasd::SortableVector<double> vecm4 (move(list1));
      EqualLinear(loctestnum, loctesterr, vec4, list1, true);
      EqualLinear(loctestnum, loctesterr, vecm4, list1, true);

      lasd:: SetVec<double> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true, 5.5);
      InsertC(loctestnum, loctesterr, setvec1, true, 6.6);
      InsertC(loctestnum, loctesterr, setvec1, true, 7.7);
      InsertC(loctestnum, loctesterr, setvec1, true, 8.8);

      lasd::SortableVector<double> vec5(setvec1);    
      EqualLinear(loctestnum, loctesterr, vec5, setvec1, true);
      
      lasd:: SetLst<double> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true, 9.9);
      InsertC(loctestnum, loctesterr, setlist1, true, 10.1);
      InsertC(loctestnum, loctesterr, setlist1, true, 11.1);
      InsertC(loctestnum, loctesterr, setlist1, true, 12.1);

      lasd::SortableVector<double> vec6(setlist1);    
      EqualLinear(loctestnum, loctesterr, vec6, setlist1, true);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myVectorString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<string> Test:" << endl;
  try     {
      lasd::SortableVector<string> vec;
      lasd::SortableVector<string> vec2;
      lasd::SortableVector<string> vec3(3);
      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);
      Size(loctestnum, loctesterr, vec, false, 1);
      vec.Clear();
      Size(loctestnum, loctesterr, vec, true, 0);

      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetFront(loctestnum, loctesterr, vec, false, string("A"));
      GetBack(loctestnum, loctesterr, vec, false, string("A"));
      SetAt(loctestnum, loctesterr, vec, false, 1, string("A"));
      GetAt(loctestnum, loctesterr, vec, false, 2, string("A"));

      Exists(loctestnum, loctesterr, vec, false, string("A"));

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("inizio"), string("inizio"));
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("inizio"), string("inizio"));

      vec.Resize(5);
      Size(loctestnum, loctesterr, vec, true, 5);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec, false, 5, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("inizio"), string("inizioABA"));
      Exists(loctestnum, loctesterr, vec, true, string("A"));
      Exists(loctestnum, loctesterr, vec, true, string("B"));
      Exists(loctestnum, loctesterr, vec, false, string("C"));

      NonEqualLinear(loctestnum, loctesterr, vec, vec2, true);
      NonEqualVector(loctestnum, loctesterr, vec, vec2, true);

      GetAt(loctestnum, loctesterr, vec, true, 3,string(""));
      GetFront(loctestnum, loctesterr, vec, true, string("A"));
      SetFront(loctestnum, loctesterr, vec, true, string("D"));
      GetBack(loctestnum, loctesterr, vec, true,string(""));
      SetBack(loctestnum, loctesterr, vec, true,string("Z"));

      Exists(loctestnum, loctesterr, vec, true,string("Z"));

      vec2=vec;
      EqualLinear(loctestnum, loctesterr, vec, vec2, true);
      EqualVector(loctestnum, loctesterr, vec, vec2, true);

      vec3=move(vec);
      EqualLinear(loctestnum, loctesterr, vec2, vec3, true);
      EqualVector(loctestnum, loctesterr, vec2, vec3, true);

      vec.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      vec2.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<string>);

      vec2.Resize(2);
      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<string>);

      lasd:: List<string> list1;

      InsertAtBack(loctestnum, loctesterr, list1, true,string("A"));
      InsertAtBack(loctestnum, loctesterr, list1, true,string("C"));
      InsertAtBack(loctestnum, loctesterr, list1, true,string("D"));
      InsertAtBack(loctestnum, loctesterr, list1, true,string("E"));

      lasd::SortableVector<string> vec4(list1);
      lasd::SortableVector<string> vecm4(move(list1));
      EqualLinear(loctestnum, loctesterr, vec4, vecm4, true);
      EqualLinear(loctestnum, loctesterr, vecm4, vec4, true);

      lasd:: SetVec<string> setvec1;

      InsertC(loctestnum, loctesterr, setvec1, true,string("F"));
      InsertC(loctestnum, loctesterr, setvec1, true,string("G"));
      InsertC(loctestnum, loctesterr, setvec1, true,string("H"));
      InsertC(loctestnum, loctesterr, setvec1, true,string("I"));

      lasd::SortableVector<string> vec5(setvec1);     
      EqualLinear(loctestnum, loctesterr, vec5, setvec1, true);

      
      lasd:: SetLst<string> setlist1;

      InsertC(loctestnum, loctesterr, setlist1, true,string("L"));
      InsertC(loctestnum, loctesterr, setlist1, true,string("M"));
      InsertC(loctestnum, loctesterr, setlist1, true,string("N"));
      InsertC(loctestnum, loctesterr, setlist1, true,string("O"));

      lasd::SortableVector<string> vec6(setlist1);     
      EqualLinear(loctestnum, loctesterr, vec6, setlist1, true);       
    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myVecTest(uint & testnum, uint & testerr) {
  myVectorInt(testnum, testerr);
  myVectorDouble(testnum, testerr);
  myVectorString(testnum, testerr);
  cout << endl << "Exercise 1A (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}