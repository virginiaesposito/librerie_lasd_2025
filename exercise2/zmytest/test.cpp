
#include "test.hpp"
#include "vector/vector.hpp"
#include "./list/list.hpp"
#include "./set/setvec/setvec.hpp"
#include "./set/setlst/setlst.hpp"
#include "./heap/heap.hpp"
#include "./pq/pq.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << " Inizio MyTest" << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;

  loctestnum = 0; loctesterr = 0;
  //myVecTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  //myListTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  //mySetVecTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  //mySetListTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  myHeapVecTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  myPQHeapTest(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl << "My Test Exercise 2 (Errors/Tests: " << stesterr << "/" << stestnum << ")"<< endl;

}


