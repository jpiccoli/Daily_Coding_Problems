// Daily_Coding_Problems.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include "Easy.h"
#include "Medium.h"

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

  // Completed 02/07/2021
  std::pair<int, int> top_left1{ 1, 4 };
  std::pair<int, int> dimensions1{ 3, 3 };
  std::pair<int, int> top_left2{ 0, 5 };
  std::pair<int, int> dimensions2{ 4, 3 };
  std::cout << "Number 581((1,4), (3,3), (0,5), (4,3)) = " << number_581(top_left1, dimensions1, top_left2, dimensions2) << '\n';
  std::cout << '\n';

  // Completed 03/20/2021
  std::vector<std::vector<int>> matrix;
  matrix.push_back({ 0,3,1,1 });
  matrix.push_back({ 2,0,0,4 });
  matrix.push_back({ 1,5,3,1 });
  std::cout << "Number 583(matrix) value = " << number_583(matrix) << '\n';
  std::cout << '\n';

  // Completed 03/20/2021
  std::string test1{ "aaabbc" };
  std::cout << "Number 584(aaabbc) = " << number_584(test1) << '\n';
  std::string test2{ "aaab" };
  std::cout << "Number 584(aaab) = " << number_584(test2) << '\n';
  std::cout << '\n';

  // Completed 03/20/2021
  std::vector<int> initial{ 1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,11,0,12,0,13,0,14,0 };
  int result;
  auto size = number_588(initial, result);
  std::cout << "Number 588(initial) size = " << size << '\n';
  std::cout << "Number 588(initial) value at index 0 = " << result << '\n';
  std::cout << '\n';

  // Completed 03/20/2021
  std::vector<int> prod_test1{ -10, -10, 5, 2 };
  std::cout << "Number_626(-10, -10, 5, 2) = " << number_626(prod_test1) << '\n';
  std::vector<int> prod_test2{ 1, 2, 3, 4, 5, 6, 7, 8 };
  std::cout << "Number_626(1, 2, 3, 4, 5, 6, 7, 8) = " << number_626(prod_test2) << '\n';
  std::cout << '\n';

  // Completed 03/28/2021
  std::vector<int> numbers1{ 5, 7, 9, 3, 4 };
  std::cout << "Number_636(5, 7, 9, 3, 4) = " << number_636(numbers1) << '\n';
  std::vector<int> numbers2{ 7, 5, 9, 4, 3 };
  std::cout << "Number_636(7, 5, 9, 4, 3) = " << number_636(numbers2) << '\n';
  std::vector<int> numbers3{ 7, 6, 3, 9, 4 };
  std::cout << "Number_636(7, 6, 3, 9, 4) = " << number_636(numbers3) << '\n';
  std::cout << '\n';

  return 0;
}

// Techniques for solving algorithm problems:
// 1. See if sorting will help. Good for min/max problems.
// 2. Break up the problem into smaller problems.
// 3. Look beyond the "brute force" approach AFTER it is working.
// 4. Look at maps and sets along with vectors, etc.
// 5. Look at recursive solutions.
// 6. Don't be afraid to create additional or compound data structures.
// 7. "O(log N)" in problem description => use binary search approach.

