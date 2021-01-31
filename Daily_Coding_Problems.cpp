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
  std::cout << "-------------\n\n";

  // Completed: 11/14/2020
  auto times = number_456();
  std::cout << "Number 456 = " << number_456().first << "," << number_456().second << '\n';
  std::cout << '\n';

  // Completed: 11/07/2020
  std::cout << "Number 491(121) = " << std::boolalpha << number_491(121) << '\n';
  std::cout << "Number 491(678) = " << std::boolalpha << number_491(678) << '\n';
  std::cout << "Number 491(888) = " << std::boolalpha << number_491(888) << '\n';
  std::cout << '\n';

  // Completed: 12/12/2020
  std::cout << "Number 516(4) = " << number_516(4) << '\n';
  std::cout << "Number 516(5) = " << number_516(5) << '\n';
  std::cout << '\n';

  // Completed: 12/06/2020
  std::vector<int> nums{ 20, 304, 3, 4, 25 };
  std::cout << "Number 518([20, 303, 3, 4, 25], 49) = " << std::boolalpha << number_518(nums, 49) << '\n';
  std::cout << "Number 518([20, 303, 3, 4, 25], 50) = " << std::boolalpha << number_518(nums, 50) << '\n';
  std::cout << '\n';

  // Completed: 12/12/2020
  auto pairs = number_523(7, 7);
  for(auto item : pairs)
  {
    std::cout << "Number_523(7,7) = " << item.first << "," << item.second << '\n';
  }
  std::cout << '\n';

  // Completed 01/31/2021
  std::cout << "Number 578{abc, bcd) = " << std::boolalpha << number_578(std::string("abc"), std::string("bcd")) << '\n';
  std::cout << "Number 578{foo, bar) = " << std::boolalpha << number_578(std::string("foo"), std::string("bar")) << '\n';
  std::cout << '\n';

  return 0;
}

