#include "Easy.h"

#include <algorithm>
#include <map>
#include <set>

//std::vector<int> number_489(std::vector<int> arr)
//{
//}

struct action
{
  action(long timestamp_, int count_, std::string type_) : timestamp(timestamp_), count(count_), type(type_)
  {}

  long timestamp;
  int count;
  std::string type;
};

// Building occupancy problem
std::pair<long, long> number_456()
{
  std::pair<long, long> times;

  int current_count = 0;
  int max_count = 0;
  int min_count = 0;
  int min_time = 0;
  int num_people = 0;
  int max_num_people = 0;
  long max_time = 0;

  std::vector<action> actions = { 
    action(1526579928, 3, "enter"),
    action(1526580382, 2, "exit"),
    action(1526581000, 4, "enter"),
    action(1526581003, 3, "exit"),
  };

  //for(auto const& item : actions)
  //{
  //  if(item.type == "enter")
  //  {
  //    current_count += item.count;
  //    if(max_count == 0 || max_count < current_count)
  //    {
  //      max_count = current_count;
  //      max_time = item.timestamp;
  //    }
  //    if(min_count == 0 || current_count < min_count)
  //    {
  //      min_count = current_count;
  //      min_time = item.timestamp;
  //    }
  //  }
  //  else if(item.type == "exit")
  //  {
  //    current_count -= item.count;
  //    if(current_count < min_count)
  //    {
  //      min_time = item.timestamp;
  //    }
  //  }
  //}

  for(unsigned i = 0; i < actions.size() - 1; ++i)
  {
    if(actions[i].type == "enter")
    {
      num_people += actions[i].count;
    }
    else if(actions[i].type == "exit")
    {
      num_people -= actions[i].count;
    }

    if(max_num_people < num_people)
    {
      max_num_people = num_people;
      times.first = actions[ i ].timestamp;
      times.second = actions[ i + 1 ].timestamp;
    }
  }

  return times;
}

// Palindromic integer
bool number_491(int value)
{
  auto temp = value;
  //std::vector<int> digits;

  //while(temp != 0)
  //{
  //  digits.push_back(temp % 10);
  //  temp = temp / 10;
  //}

  //for(unsigned i = 0; i < digits.size() / 2; ++i)
  //{
  //  if(digits[ i ] != digits[ digits.size() - 1 - i ])
  //    return false;
  //}

  int divisor = 1;
  while(temp / divisor >= 10)
    divisor *= 10;

  while(temp != 0)
  {
    int first = temp / divisor;
    int last = temp % 10;

    if(first != last)
      return false;

    temp = (temp % divisor) / 10;

    divisor /= 100;
  }

  return true;
}

// Find the nth number that is a power of 7 or the sum f unique powers of 7
int number_516(int n)
{
  int answer = 0;
  int bit_place = 0;

  while(n > 0)
  {
    if(n & 1)
    {
      answer += static_cast<int>(pow(7, bit_place));
    }

    n >>= 1;
    bit_place++;
  }

  return answer;
}

// Support function for #518
bool pair_sums_to_k(std::vector<int> vec, int k, int start)
{
  int low = start;
  int high = vec.size() - 1;
  while(low < high)
  {
    if(vec[ low ] + vec[ high ] == k)
      return true;
    else if(vec[ low ] + vec[ high ] < k)
      low++;
    else
      high--;
  }

  return false;
}

// Numbers that sum to a given number
bool number_518(std::vector<int> nums, int sum)
{
  std::sort(nums.begin(), nums.end());
  for(unsigned i = 0; i < nums.size() - 2; ++i)
  {
    if(pair_sums_to_k(nums, sum - nums[ i ], i + 1))
      return true;
  }

  return false;
}

// How many integer pairs satsify the condition a + b = M and a XOR b = N
std::vector<std::pair<int, int>> number_523(int M, int N)
{
  int M_count = 0;
  int N_count = 0;
  int overall_count = 0;

  std::vector<std::pair<int,int>> pairs;

  for(int i = 0; i < M/2; ++i)
  {
    if((i ^ (M - i)) == N)
    {
      pairs.push_back(std::pair<int, int>(i, M - i));
    }
  }

  return pairs;
}

bool number_578(std::string s1, std::string s2)
{
  std::map<char, char> mapping;

  if(s1.length() != s2.length())
    return false;

  for(unsigned i = 0; i < s1.length(); ++i)
  {
    if(mapping.find(s1[ i ]) == mapping.end())
    {
      mapping.insert({ s1[ i ], s2[ i ] });
    }
    else if(mapping[ s1[ i ] ] != s2[ i ])
    {
      return false;
    }
  }

  return true;
}





















