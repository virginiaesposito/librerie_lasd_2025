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

#include "../../zlasdtest/heap/heap.hpp"
#include "../../zlasdtest/pq/pq.hpp"

#include "../../heap/heap.hpp"
#include "../../heap/vec/heapvec.hpp"

#include "../../pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

using namespace std;

void myPQHeapInt(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyPQHeap<int> Test:" << endl;
  try {
    {
      lasd::PQHeap<int> pq0;
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);
      Tip(loctestnum, loctesterr, pq0, false, 0);
      TipNRemove(loctestnum, loctesterr, pq0, false, 0);
      RemoveTip(loctestnum, loctesterr, pq0, false);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq0, false, 0, 8);
      Exists(loctestnum, loctesterr, pq0, false, 0);

      Insert(loctestnum, loctesterr, pq0, 5);
      Size(loctestnum, loctesterr, pq0, true, 1);
      Tip(loctestnum, loctesterr, pq0, true, 5);

      Insert(loctestnum, loctesterr, pq0, 5);
      Size(loctestnum, loctesterr, pq0, true, 2);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      Insert(loctestnum, loctesterr, pq0, 3);
      Insert(loctestnum, loctesterr, pq0, 7);
      Size(loctestnum, loctesterr, pq0, true, 4);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      Insert(loctestnum, loctesterr, pq0, 4);
      Insert(loctestnum, loctesterr, pq0, 2);
      Size(loctestnum, loctesterr, pq0, true, 6);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      Insert(loctestnum, loctesterr, pq0, 6);
      Insert(loctestnum, loctesterr, pq0, 8);
      Size(loctestnum, loctesterr, pq0, true, 8);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      Insert(loctestnum, loctesterr, pq0, -1);
      Size(loctestnum, loctesterr, pq0, true, 9);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      lasd::PQHeap<int> pq1(pq0);
      EqualLinear(loctestnum, loctesterr, pq0, pq1, true);

      TipNRemove(loctestnum, loctesterr, pq0, true, 8);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq0, true, 5, 0);
      Exists(loctestnum, loctesterr, pq0, true, 0);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq0, true, 5, 8);
      Exists(loctestnum, loctesterr, pq0, true, 8);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq0, true, 5, 9);
      Exists(loctestnum, loctesterr, pq0, true, 9);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);

      Change(loctestnum, loctesterr, pq0, true, 7, 10);
      Exists(loctestnum, loctesterr, pq0, true, 10);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<int>);
      TipNRemove(loctestnum, loctesterr, pq0, true, 10);
      Exists(loctestnum, loctesterr, pq0, false, 10);

      EqualLinear(loctestnum, loctesterr, pq0, pq1, false);
      lasd::PQHeap<int> pq2(std::move(pq0));

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      lasd::PQHeap<int> pq3;
      pq3=pq2;
      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
      EqualLinear(loctestnum, loctesterr, pq3, pq2, true);

      lasd::Vector<int> vec(7);
      SetAt(loctestnum, loctesterr, vec, true, 0, 0);
      SetAt(loctestnum, loctesterr, vec, true, 1, 1);
      SetAt(loctestnum, loctesterr, vec, true, 2, 2);
      SetAt(loctestnum, loctesterr, vec, true, 3, 3);
      SetAt(loctestnum, loctesterr, vec, true, 4, 4);
      SetAt(loctestnum, loctesterr, vec, true, 5, 5);
      SetAt(loctestnum, loctesterr, vec, true, 6, 6);    

      lasd::HeapVec<int> heap1(vec);
      lasd::PQHeap<int> pq4(vec);
      lasd::PQHeap<int> pq5(heap1);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      TraversePreOrder(loctestnum, loctesterr, pq5, true, &TraversePrint<int>);

      EqualLinear(loctestnum, loctesterr, pq4, pq5, true);  
      Tip(loctestnum, loctesterr, pq4, true, 6);
      Tip(loctestnum, loctesterr, pq5, true, 6);

      Change(loctestnum, loctesterr, pq4, true, 0, -1);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -2);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -3);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -4);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -5);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -6);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);
      Change(loctestnum, loctesterr, pq4, true, 0, -7);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<int>);

      TipNRemove(loctestnum, loctesterr, pq4, true, -1);
      Empty(loctestnum, loctesterr, pq4, false);
      Size(loctestnum, loctesterr, pq4, true, 6);

      Exists(loctestnum, loctesterr, pq4, false, -1);
      Exists(loctestnum, loctesterr, pq4, true, -2);
      Exists(loctestnum, loctesterr, pq4, true, -3);
      Exists(loctestnum, loctesterr, pq4, true, -4);
      Exists(loctestnum, loctesterr, pq4, true, -5);
      Exists(loctestnum, loctesterr, pq4, true, -6);
      Exists(loctestnum, loctesterr, pq4, true, -7);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyPQHeap<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myPQHeapDouble(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyPQHeap<double> Test:" << endl;
  try {
    {
      lasd::PQHeap<double> pq0;
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);
      Tip(loctestnum, loctesterr, pq0, false, 0.0);
      TipNRemove(loctestnum, loctesterr, pq0, false, 0.0);
      RemoveTip(loctestnum, loctesterr, pq0, false);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq0, false, 0, 8.0);
      Exists(loctestnum, loctesterr, pq0, false, 0.0);

      Insert(loctestnum, loctesterr, pq0, 5.0);
      Size(loctestnum, loctesterr, pq0, true, 1);
      Tip(loctestnum, loctesterr, pq0, true, 5.0);

      Insert(loctestnum, loctesterr, pq0, 5.0);
      Size(loctestnum, loctesterr, pq0, true, 2);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      Insert(loctestnum, loctesterr, pq0, 3.0);
      Insert(loctestnum, loctesterr, pq0, 7.0);
      Size(loctestnum, loctesterr, pq0, true, 4);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      Insert(loctestnum, loctesterr, pq0, 4.0);
      Insert(loctestnum, loctesterr, pq0, 2.0);
      Size(loctestnum, loctesterr, pq0, true, 6);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      Insert(loctestnum, loctesterr, pq0, 6.0);
      Insert(loctestnum, loctesterr, pq0, 8.0);
      Size(loctestnum, loctesterr, pq0, true, 8);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      Insert(loctestnum, loctesterr, pq0, -1.0);
      Size(loctestnum, loctesterr, pq0, true, 9);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      lasd::PQHeap<double> pq1(pq0);
      EqualLinear(loctestnum, loctesterr, pq0, pq1, true);

      TipNRemove(loctestnum, loctesterr, pq0, true, 8.0);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq0, true, 5, 0.0);
      Exists(loctestnum, loctesterr, pq0, true, 0.0);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq0, true, 5, 8.0);
      Exists(loctestnum, loctesterr, pq0, true, 8.0);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq0, true, 5, 9.0);
      Exists(loctestnum, loctesterr, pq0, true, 9.0);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);

      Change(loctestnum, loctesterr, pq0, true, 7, 10.1);
      Exists(loctestnum, loctesterr, pq0, true, 10.1);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<double>);
      TipNRemove(loctestnum, loctesterr, pq0, true, 10.1);
      Exists(loctestnum, loctesterr, pq0, false, 10.1);

      EqualLinear(loctestnum, loctesterr, pq0, pq1, false);
      lasd::PQHeap<double> pq2(std::move(pq0));

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      lasd::PQHeap<double> pq3;
      pq3=pq2;
      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
      EqualLinear(loctestnum, loctesterr, pq3, pq2, true);

      lasd::Vector<double> vec(7);
      SetAt(loctestnum, loctesterr, vec, true, 0, 0.0);
      SetAt(loctestnum, loctesterr, vec, true, 1, 1.0);
      SetAt(loctestnum, loctesterr, vec, true, 2, 2.0);
      SetAt(loctestnum, loctesterr, vec, true, 3, 3.0);
      SetAt(loctestnum, loctesterr, vec, true, 4, 4.0);
      SetAt(loctestnum, loctesterr, vec, true, 5, 5.0);
      SetAt(loctestnum, loctesterr, vec, true, 6, 6.0);    

      lasd::HeapVec<double> heap1(vec);
      lasd::PQHeap<double> pq4(vec);
      lasd::PQHeap<double> pq5(heap1);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      TraversePreOrder(loctestnum, loctesterr, pq5, true, &TraversePrint<double>);

      EqualLinear(loctestnum, loctesterr, pq4, pq5, true);  
      Tip(loctestnum, loctesterr, pq4, true, 6.0);
      Tip(loctestnum, loctesterr, pq5, true, 6.0);

      Change(loctestnum, loctesterr, pq4, true, 0, -1.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -2.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -3.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -4.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -5.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -6.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);
      Change(loctestnum, loctesterr, pq4, true, 0, -7.0);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<double>);

      TipNRemove(loctestnum, loctesterr, pq4, true, -1.0);
      Empty(loctestnum, loctesterr, pq4, false);
      Size(loctestnum, loctesterr, pq4, true, 6);

      Exists(loctestnum, loctesterr, pq4, false, -1.0);
      Exists(loctestnum, loctesterr, pq4, true, -2.0);
      Exists(loctestnum, loctesterr, pq4, true, -3.0);
      Exists(loctestnum, loctesterr, pq4, true, -4.0);
      Exists(loctestnum, loctesterr, pq4, true, -5.0);
      Exists(loctestnum, loctesterr, pq4, true, -6.0);
      Exists(loctestnum, loctesterr, pq4, true, -7.0);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyPQHeap<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myPQHeapString(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyPQHeap<string> Test:" << endl;
  try {
    {
      lasd::PQHeap<string> pq0;
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);
      Tip(loctestnum, loctesterr, pq0, false, string(""));
      TipNRemove(loctestnum, loctesterr, pq0, false, string(""));
      RemoveTip(loctestnum, loctesterr, pq0, false);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq0, false, 0, string("A"));
      Exists(loctestnum, loctesterr, pq0, false, string(""));

      Insert(loctestnum, loctesterr, pq0, string("E"));
      Size(loctestnum, loctesterr, pq0, true, 1);
      Tip(loctestnum, loctesterr, pq0, true, string("E"));

      Insert(loctestnum, loctesterr, pq0, string("E"));
      Size(loctestnum, loctesterr, pq0, true, 2);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      Insert(loctestnum, loctesterr, pq0, string("C"));
      Insert(loctestnum, loctesterr, pq0, string("G"));
      Size(loctestnum, loctesterr, pq0, true, 4);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      Insert(loctestnum, loctesterr, pq0, string("D"));
      Insert(loctestnum, loctesterr, pq0, string("B"));
      Size(loctestnum, loctesterr, pq0, true, 6);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      Insert(loctestnum, loctesterr, pq0, string("F"));
      Insert(loctestnum, loctesterr, pq0, string("H"));
      Size(loctestnum, loctesterr, pq0, true, 8);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      Insert(loctestnum, loctesterr, pq0, string(" "));
      Size(loctestnum, loctesterr, pq0, true, 9);
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      lasd::PQHeap<string> pq1(pq0);
      EqualLinear(loctestnum, loctesterr, pq0, pq1, true);

      TipNRemove(loctestnum, loctesterr, pq0, true, string("H"));
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq0, true, 5, string(" "));
      Exists(loctestnum, loctesterr, pq0, true, string(" "));
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq0, true, 5, string("H"));
      Exists(loctestnum, loctesterr, pq0, true, string("H"));
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq0, true, 5, string("I"));
      Exists(loctestnum, loctesterr, pq0, true, string("I"));
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);

      Change(loctestnum, loctesterr, pq0, true, 7, string("La"));
      Exists(loctestnum, loctesterr, pq0, true, string("La"));
      TraversePreOrder(loctestnum, loctesterr, pq0, true, &TraversePrint<string>);
      TipNRemove(loctestnum, loctesterr, pq0, true, string("La"));
      Exists(loctestnum, loctesterr, pq0, false, string("La"));

      EqualLinear(loctestnum, loctesterr, pq0, pq1, false);
      lasd::PQHeap<string> pq2(std::move(pq0));

      TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
      Empty(loctestnum, loctesterr, pq0, true);
      Size(loctestnum, loctesterr, pq0, true, 0);

      lasd::PQHeap<string> pq3;
      pq3=pq2;
      TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
      EqualLinear(loctestnum, loctesterr, pq3, pq2, true);

      lasd::Vector<string> vec(7);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("  "));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("a "));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("b "));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("c "));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("d "));
      SetAt(loctestnum, loctesterr, vec, true, 5, string("e "));
      SetAt(loctestnum, loctesterr, vec, true, 6, string("f "));    

      lasd::HeapVec<string> heap1(vec);
      lasd::PQHeap<string> pq4(vec);
      lasd::PQHeap<string> pq5(heap1);
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, pq5, true, &TraversePrint<string>);

      EqualLinear(loctestnum, loctesterr, pq4, pq5, true);  
      Tip(loctestnum, loctesterr, pq4, true, string("f "));
      Tip(loctestnum, loctesterr, pq5, true, string("f "));

      Change(loctestnum, loctesterr, pq4, true, 0, string("z "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 1, string("v "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 2, string("w "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 3, string("y "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 4, string("x "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 5, string("u "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);
      Change(loctestnum, loctesterr, pq4, true, 6, string("t "));
      TraversePreOrder(loctestnum, loctesterr, pq4, true, &TraversePrint<string>);

      TipNRemove(loctestnum, loctesterr, pq4, true, string("z "));
      Empty(loctestnum, loctesterr, pq4, false);
      Size(loctestnum, loctesterr, pq4, true, 6);

      Exists(loctestnum, loctesterr, pq4, false, string("z "));
      Exists(loctestnum, loctesterr, pq4, true, string("u "));
      Exists(loctestnum, loctesterr, pq4, true, string("v "));
      Exists(loctestnum, loctesterr, pq4, true, string("w "));
      Exists(loctestnum, loctesterr, pq4, true, string("y "));
      Exists(loctestnum, loctesterr, pq4, true, string("x "));
      Exists(loctestnum, loctesterr, pq4, true, string("t "));
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyPQHeap<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myPQHeapTest(uint & testnum, uint & testerr)
{
  myPQHeapInt(testnum, testerr);
  myPQHeapDouble(testnum, testerr);
  myPQHeapString(testnum, testerr);
  cout << endl << "My PQHeapTest (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}