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

void myHeapVecInt(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyHeapVec<int> Test:" << endl;
  try {
    {
      lasd::HeapVec<int> heap0;
      Empty(loctestnum, loctesterr, heap0, true);
      Size(loctestnum, loctesterr, heap0, true, 0);
      Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);
      IsHeap(loctestnum, loctesterr, heap0, true);        
      heap0.Sort();        
      IsHeap(loctestnum, loctesterr, heap0, true);        
      SetAt(loctestnum, loctesterr, heap0, false, 0, 4);
      SetAt(loctestnum, loctesterr, heap0, false, 1, 3);        
      heap0.Heapify();
      GetFront(loctestnum, loctesterr, heap0, false, 0);
      GetBack(loctestnum, loctesterr, heap0, false, 0);
      FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<int>, 0, 0);
      Exists(loctestnum, loctesterr, heap0, false, 10);
      heap0.Clear();

      lasd::Vector<int> vec1(7);
      SetAt(loctestnum, loctesterr, vec1, true, 0, 10);
      SetAt(loctestnum, loctesterr, vec1, true, 1, 3);
      SetAt(loctestnum, loctesterr, vec1, true, 2, 5);
      SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
      SetAt(loctestnum, loctesterr, vec1, true, 4, 2);
      SetAt(loctestnum, loctesterr, vec1, true, 5, 70);
      SetAt(loctestnum, loctesterr, vec1, true, 6, 1);

      lasd::HeapVec<int> heap1(vec1);

      lasd::HeapVec<int> heap11(std::move(vec1));

      Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);

      Traverse(loctestnum, loctesterr, heap11, true, &TraversePrint<int>);
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<int>);

      IsHeap(loctestnum, loctesterr, heap1, true);
      IsHeap(loctestnum, loctesterr, heap11, true);

      heap11.Clear();
      Empty(loctestnum, loctesterr, heap11, true);
      Size(loctestnum, loctesterr, heap11, true, 0);

      SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
      SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
      SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
      SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
      SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
      SetAt(loctestnum, loctesterr, vec1, true, 5, 10);
      SetAt(loctestnum, loctesterr, vec1, true, 6, 70);

      lasd::HeapVec<int> heap2(vec1);

      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);

      IsHeap(loctestnum, loctesterr, heap2, true);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);

      heap1.Sort();

      IsHeap(loctestnum, loctesterr, heap1, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
      GetFront(loctestnum, loctesterr, heap1, true, 1);
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
      GetBack(loctestnum, loctesterr, heap2, true, 3);
      FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldAdd<int>, 0, 95);
      FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldAdd<int>, 0, 95);
      Exists(loctestnum, loctesterr, heap1, true, 10);
      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      lasd::HeapVec<int> heap3(heap2);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      lasd::HeapVec<int> heap4(std::move(heap3));
      
      EqualLinear(loctestnum, loctesterr, heap2, heap4, true);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
      Empty(loctestnum, loctesterr, heap3, true);
      Size(loctestnum, loctesterr, heap3, true, 0);

      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);
      heap3 = heap11;
      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);

      heap3=heap2;
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<int>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      heap3 = std::move(heap2);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<int>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<int>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<int>);
      EqualLinear(loctestnum, loctesterr, heap3, heap4, true);

      std::cout<<"heap0"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<int>);
      std::cout<<"heap1"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<int>);
      std::cout<<"heap11"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<int>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<int>);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<int>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<int>);

      MapPreOrder(loctestnum, loctesterr, heap4, true, &MapInvert<int>);
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<int>);
      Empty(loctestnum, loctesterr, heap4, false);
      Size(loctestnum, loctesterr, heap4, true, 7);
      IsHeap(loctestnum, loctesterr, heap4, false);

      heap4.Sort();
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<int>);
      IsHeap(loctestnum, loctesterr, heap4, false);
      heap4.Heapify();
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<int>);
      IsHeap(loctestnum, loctesterr, heap4, true);

      FoldPreOrder(loctestnum, loctesterr, heap4, true, &FoldAdd<int>, 0, -95);
      FoldPostOrder(loctestnum, loctesterr, heap4, true, &FoldAdd<int>, 0, -95);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyHeapVec<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myHeapVecDouble(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyHeapVec<double> Test:" << endl;
  try {
    {
      lasd::HeapVec<double> heap0;
      Empty(loctestnum, loctesterr, heap0, true);
      Size(loctestnum, loctesterr, heap0, true, 0);
      Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);
      IsHeap(loctestnum, loctesterr, heap0, true);        
      heap0.Sort();        
      IsHeap(loctestnum, loctesterr, heap0, true);        
      SetAt(loctestnum, loctesterr, heap0, false, 0, 4.4);
      SetAt(loctestnum, loctesterr, heap0, false, 1, 3.3);        
      heap0.Heapify();
      GetFront(loctestnum, loctesterr, heap0, false, 0.1);
      GetBack(loctestnum, loctesterr, heap0, false, 0.1);
      FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, heap0, true, &FoldAdd<double>, 0.0, 0.0);
      Exists(loctestnum, loctesterr, heap0, false, 10.1);
      heap0.Clear();

      lasd::Vector<double> vec1(7);
      SetAt(loctestnum, loctesterr, vec1, true, 0, 10.1);
      SetAt(loctestnum, loctesterr, vec1, true, 1, 3.3);
      SetAt(loctestnum, loctesterr, vec1, true, 2, 5.5);
      SetAt(loctestnum, loctesterr, vec1, true, 3, 4.4);
      SetAt(loctestnum, loctesterr, vec1, true, 4, 2.2);
      SetAt(loctestnum, loctesterr, vec1, true, 5, 70.7);
      SetAt(loctestnum, loctesterr, vec1, true, 6, 1.1);

      lasd::HeapVec<double> heap1(vec1);

      lasd::HeapVec<double> heap11(std::move(vec1));

      Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);

      Traverse(loctestnum, loctesterr, heap11, true, &TraversePrint<double>);
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<double>);

      IsHeap(loctestnum, loctesterr, heap1, true);
      IsHeap(loctestnum, loctesterr, heap11, true);

      heap11.Clear();
      Empty(loctestnum, loctesterr, heap11, true);
      Size(loctestnum, loctesterr, heap11, true, 0);

      SetAt(loctestnum, loctesterr, vec1, true, 0, 1.1);
      SetAt(loctestnum, loctesterr, vec1, true, 1, 2.2);
      SetAt(loctestnum, loctesterr, vec1, true, 2, 3.3);
      SetAt(loctestnum, loctesterr, vec1, true, 3, 4.4);
      SetAt(loctestnum, loctesterr, vec1, true, 4, 5.5);
      SetAt(loctestnum, loctesterr, vec1, true, 5, 10.1);
      SetAt(loctestnum, loctesterr, vec1, true, 6, 70.7);

      lasd::HeapVec<double> heap2(vec1);

      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);

      IsHeap(loctestnum, loctesterr, heap2, true);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);

      heap1.Sort();

      IsHeap(loctestnum, loctesterr, heap1, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
      GetFront(loctestnum, loctesterr, heap1, true, 1.1);
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
      GetBack(loctestnum, loctesterr, heap2, true, 3.3);
      Exists(loctestnum, loctesterr, heap1, true, 10.1);
      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      lasd::HeapVec<double> heap3(heap2);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      lasd::HeapVec<double> heap4(std::move(heap3));
      
      EqualLinear(loctestnum, loctesterr, heap2, heap4, true);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
      Empty(loctestnum, loctesterr, heap3, true);
      Size(loctestnum, loctesterr, heap3, true, 0);

      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);
      heap3 = heap11;
      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);

      heap3=heap2;
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<double>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      heap3 = std::move(heap2);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<double>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<double>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<double>);
      EqualLinear(loctestnum, loctesterr, heap3, heap4, true);

      std::cout<<"heap0"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<double>);
      std::cout<<"heap1"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<double>);
      std::cout<<"heap11"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<double>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<double>);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<double>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<double>);

      MapPreOrder(loctestnum, loctesterr, heap4, true, &MapInvert<double>);
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<double>);
      Empty(loctestnum, loctesterr, heap4, false);
      Size(loctestnum, loctesterr, heap4, true, 7);
      IsHeap(loctestnum, loctesterr, heap4, false);

      heap4.Sort();
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<double>);
      IsHeap(loctestnum, loctesterr, heap4, false);
      heap4.Heapify();
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<double>);
      IsHeap(loctestnum, loctesterr, heap4, true);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyHeapVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myHeapVecString(uint & testnum, uint & testerr)
{
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of MyHeapVec<string> Test:" << endl;
  try {
    {
      lasd::HeapVec<string> heap0;
      Empty(loctestnum, loctesterr, heap0, true);
      Size(loctestnum, loctesterr, heap0, true, 0);
      Traverse(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      IsHeap(loctestnum, loctesterr, heap0, true);        
      heap0.Sort();        
      IsHeap(loctestnum, loctesterr, heap0, true);        
      SetAt(loctestnum, loctesterr, heap0, false, 0, string("A"));
      SetAt(loctestnum, loctesterr, heap0, false, 1, string("B"));        
      heap0.Heapify();
      GetFront(loctestnum, loctesterr, heap0, false, string("A"));
      GetBack(loctestnum, loctesterr, heap0, false, string("A"));
      FoldPreOrder(loctestnum, loctesterr, heap0, true, &FoldStringConcatenate, string(""), string(""));
      FoldPostOrder(loctestnum, loctesterr, heap0, true, &FoldStringConcatenate, string(""), string(""));
      Exists(loctestnum, loctesterr, heap0, false, string("A"));
      heap0.Clear();

      lasd::Vector<string> vec1(7);
      SetAt(loctestnum, loctesterr, vec1, true, 0, string("V"));
      SetAt(loctestnum, loctesterr, vec1, true, 1, string("C"));
      SetAt(loctestnum, loctesterr, vec1, true, 2, string("E"));
      SetAt(loctestnum, loctesterr, vec1, true, 3, string("D"));
      SetAt(loctestnum, loctesterr, vec1, true, 4, string("B"));
      SetAt(loctestnum, loctesterr, vec1, true, 5, string("Z"));
      SetAt(loctestnum, loctesterr, vec1, true, 6, string("A"));

      lasd::HeapVec<string> heap1(vec1);

      lasd::HeapVec<string> heap11(std::move(vec1));

      Traverse(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);

      Traverse(loctestnum, loctesterr, heap11, true, &TraversePrint<string>);
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<string>);

      IsHeap(loctestnum, loctesterr, heap1, true);
      IsHeap(loctestnum, loctesterr, heap11, true);

      heap11.Clear();
      Empty(loctestnum, loctesterr, heap11, true);
      Size(loctestnum, loctesterr, heap11, true, 0);

      SetAt(loctestnum, loctesterr, vec1, true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec1, true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec1, true, 2, string("C"));
      SetAt(loctestnum, loctesterr, vec1, true, 3, string("D"));
      SetAt(loctestnum, loctesterr, vec1, true, 4, string("E"));
      SetAt(loctestnum, loctesterr, vec1, true, 5, string("V"));
      SetAt(loctestnum, loctesterr, vec1, true, 6, string("Z"));

      lasd::HeapVec<string> heap2(vec1);

      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);

      IsHeap(loctestnum, loctesterr, heap2, true);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);

      heap1.Sort();

      IsHeap(loctestnum, loctesterr, heap1, false);
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);

      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      GetFront(loctestnum, loctesterr, heap1, true, string("A"));
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      GetBack(loctestnum, loctesterr, heap2, true, string("C"));
      FoldPreOrder(loctestnum, loctesterr, heap1, true, &FoldStringConcatenate, string(""), string("ABCDEVZ"));
      FoldPostOrder(loctestnum, loctesterr, heap2, true, &FoldStringConcatenate, string(""), string("CABDVEZ"));
      Exists(loctestnum, loctesterr, heap1, true, string("V"));
      EqualLinear(loctestnum, loctesterr, heap1, heap2, false);

      lasd::HeapVec<string> heap3(heap2);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      lasd::HeapVec<string> heap4(std::move(heap3));
      
      EqualLinear(loctestnum, loctesterr, heap2, heap4, true);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, false);
      Empty(loctestnum, loctesterr, heap3, true);
      Size(loctestnum, loctesterr, heap3, true, 0);

      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);
      heap3 = heap11;
      EqualLinear(loctestnum, loctesterr, heap3, heap11, true);

      heap3=heap2;
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);

      heap3 = std::move(heap2);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      EqualLinear(loctestnum, loctesterr, heap2, heap3, true);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<string>);
      EqualLinear(loctestnum, loctesterr, heap3, heap4, true);

      std::cout<<"heap0"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap0, true, &TraversePrint<string>);
      std::cout<<"heap1"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap1, true, &TraversePrint<string>);
      std::cout<<"heap11"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap11, true, &TraversePrint<string>);
      std::cout<<"heap2"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap2, true, &TraversePrint<string>);
      std::cout<<"heap3"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap3, true, &TraversePrint<string>);
      std::cout<<"heap4"<<std::endl;
      TraversePreOrder(loctestnum, loctesterr, heap4, true, &TraversePrint<string>);
    

      lasd::Vector<string> vec2(4);
      SetAt(loctestnum, loctesterr, vec2, true, 0, string("ciao"));
      SetAt(loctestnum, loctesterr, vec2, true, 1, string("io"));
      SetAt(loctestnum, loctesterr, vec2, true, 2, string("sono"));
      SetAt(loctestnum, loctesterr, vec2, true, 3, string("Virginia"));

      lasd::HeapVec<string> heap12(vec2);

      heap12.Heapify();
      TraversePreOrder(loctestnum, loctesterr, heap12, true, &TraversePrint<string>);

      heap12.Sort();
      TraversePreOrder(loctestnum, loctesterr, heap12, true, &TraversePrint<string>);
    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of MyHeapVec<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myHeapVecTest(uint & testnum, uint & testerr)
{
  myHeapVecInt(testnum, testerr);
  myHeapVecDouble(testnum, testerr);
  myHeapVecString(testnum, testerr);
  cout << endl << "My HeapVecTest (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}