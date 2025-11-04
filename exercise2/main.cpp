
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "LASD Libraries 2025" << std::endl;

  int val;
  std::cout << ("Inserisci 1 per lasdtest, 2 per mytest: ");
  std::cin >> val;
  switch(val){
    case 1:
      lasdtest(); 
      break;
    case 2:
      mytest();
      break;
  }
  return 0;
}
