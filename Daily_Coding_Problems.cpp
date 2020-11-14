// Daily_Coding_Problems.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include "Easy.h"

#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "Daily Coding Problems\n";

  std::cout << "-------------\n";
  std::cout << "Easy Problems\n";
  std::cout << "-------------\n";

  std::cout << '\n';
  auto times = number_456();
  std::cout << "Number 456 = " << number_456().first << "," << number_456().second << '\n';

  std::cout << '\n';
  // Completed: 11/07/2020
  std::cout << "Number 491(121) = " << std::boolalpha << number_491(121) << '\n';
  std::cout << "Number 491(678) = " << std::boolalpha << number_491(678) << '\n';
  std::cout << "Number 491(888) = " << std::boolalpha << number_491(888) << '\n';
  std::cout << '\n';

  return 0;
}

