#include "Easy.h"

#include <algorithm>
#include <map>
#include <set>
#include <exception>

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

int number_581(std::pair<int, int> top_left1, std::pair<int, int> dimensions1, std::pair<int, int> top_left2, std::pair<int, int> dimensions2)
{
  //int bottom_left_y1 = top_left1.second - dimensions1.second;
  //int bottom_left_y2 = top_left2.second - dimensions2.second;

  //int top_right_x1 = top_left1.first + dimensions1.first;
  //int top_right_x2 = top_left2.first + dimensions2.first;

  //if(bottom_left_y2 > top_left1.second || bottom_left_y1 > top_left2.second)
  //  return 0;

  //if(top_right_x2 > top_left1.first  || top_right_x2 > top_left1.first)
  //  return 0;

  //auto height = top_left1.second - bottom_left_y2;
  //auto width = top_left1.first - top_right_x2;

  //auto area = height * width;
  //if(area < 0)
  //  area *= -1;

  // Right-most left border
  auto left_x = std::max(top_left1.first, top_left2.first);

  // Left-most right border
  auto right_x = std::min(top_left1.first + dimensions1.first, top_left2.first+ dimensions2.first);

  // Bottom-most top border
  auto top_y = std::min(top_left1.second, top_left2.second);

  // Top-most bottom border
  auto bottom_y = std::max(top_left1.second - dimensions1.second, top_left2.second - dimensions2.second);

  if(left_x > right_x || bottom_y > top_y)
    return 0;

  return (right_x - left_x) * (top_y - bottom_y);
}

// Support function for number_584()
void get_max_char(std::map<char, int> character_count, char& character, int& index)
{
  int current_max = 0;

  for(auto it = character_count.begin(); it != character_count.end(); ++it)
  {
    if(it->second > current_max)
    {
      current_max = it->second;
      character = it->first;
      index = it->second;
    }
  }
}

// Support structure for number_584()
struct character_info
{
  char character;
  int count;
  bool active;
};

// Support function for number_584()
bool is_active_element(std::vector<character_info> vec)
{
  auto result = std::find_if(vec.begin(), vec.end(), [] (character_info element) {
    return element.active;
  });

  return result != vec.end();
}

// Support function for number_584()
void get_max_char_element(std::vector<character_info> vec, char& character, int& count, int& index)
{
  int current_max = 0;

  for(unsigned i = 0; i < vec.size(); ++i)
  {
    if(vec[i].count > current_max && vec[i].active)
    {
      current_max = vec[ i ].count;
      character = vec[ i ].character;
      count = vec[ i ].count;
      index = i;
    }
  }
}

// The complexity here is due to the fact that a C++ vector, map, etc. cannot EASILY be
// modified while iterating. This is in contrast to a Python dictionary, which can have
// deletion operations in an iteration.
std::string number_584(std::string test_string)
{
  std::vector<character_info> elements;
  char found_char;
  int found_count;
  int index;
  std::string result;

  std::map<char, int> character_count;

  for(unsigned i = 0; i < test_string.size(); ++i)
  {
    auto itr = character_count.find(test_string[ i ]);
    if(itr == character_count.end())
    {
      character_count[ test_string[ i ] ] = 1;
    }
    else
    {
      auto val = itr->second;
      character_count[ test_string[ i ] ] = ++val;
    }
  }

  for(auto it = character_count.begin(); it != character_count.end(); ++it)
  {
    character_info element;
    element.character = it->first;
    element.count = it->second;
    element.active = true;
    elements.push_back(element);
  }

  get_max_char_element(elements, found_char, found_count, index);
  elements[ index ].active = false;
  result.push_back(found_char);

  while(is_active_element(elements))
  {
    char last_char = found_char;
    int last_count = found_count;

    get_max_char_element(elements, found_char, found_count, index);
    elements[ index ].active = false;
    result.push_back(found_char);

    if(last_count > 1)
    {
      for(unsigned i = 0; i < elements.size(); ++i)
      {
        if(elements[ i ].character == last_char)
        {
          elements[ i ].count = last_count - 1;
          elements[ i ].active = true;
          break;
        }
      }
    }
  }

  if(result.size() == test_string.size())
  {
    return result;
  }
  else
  {
    return "None";
  }
}

// Support structure for number_588()
template<typename T>
struct SparseArray
{
  std::map<int, T> sparse_array;
  int size;

  void init(std::vector<T> arr, int size_)
  {
    size = size_;

    for(int i = 0; i < size; i++)
    {
      if(arr[ i ] != 0)
      {
        sparse_array[ i ] = arr[ i ];
      }
    }
  }

  void set(int index, int val)
  {
    if(index >= size || index < 0)
    {
      throw std::exception();
    }
    sparse_array[ index ] = val;
  }

  T get(int index)
  {
    if(index >= size || index < 0)
    {
      throw std::exception();
    }
    return sparse_array[ index ];
  }
};

int number_588(std::vector<int> vec, int& result)
{
  SparseArray<int> sa;

  std::vector<int> initial{ 1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,11,0,12,0,13,0,14,0,15,0 };
  sa.init(initial, (int)initial.size());
  sa.set(0, 29);
  result = sa.get(0);
  return sa.sparse_array.size();
}

int number_626(std::vector<int> numbers)
{
  if(numbers.size() == 3)
    return numbers[ 0 ] * numbers[ 1 ] * numbers[ 2 ];

  // Answer is one of the following either the product of the larger of three largest 
  // numbers or two smallest (most negative) numbers and the largest number
  std::sort(numbers.begin(), numbers.end());

  int third_largest = numbers[ numbers.size() - 3 ];
  int second_largest = numbers[ numbers.size() - 2 ];
  int first_largest = numbers[ numbers.size() - 1 ];

  int first_smallest = numbers[ 0 ];
  int second_smallest = numbers[ 1 ];

  return std::max(first_largest * second_largest * third_largest, first_largest * first_smallest * second_smallest);
}

boost::optional<unsigned int> number_708(std::vector<int> numbers)
{
  int low = 0;
  int high = numbers.size();
  int mid = 1;

  while(low <= high)
  {
    mid = (low + high) / 2;
    if(numbers[ mid ] == mid)
      return mid;
    else if(numbers[ mid ] < mid)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return boost::none;
}

std::string number_718_1(int value)
{
  std::string answer = "";

  int n = value;
  int remainder = 0;

  while(n > 0)
  {
    int x = n;
    n = (n - 1) / 26;
    remainder = (x - 1) % 26;
    char ch = remainder + 65;
    answer = ch + answer;
  }

  return answer;
}

std::pair<int, int> number_723(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3, std::pair<int, int> p4)
{
  std::pair<int, int> result;

  std::vector<std::pair<int, int>> points;

  points.push_back(p1);
  points.push_back(p2);
  points.push_back(p3);
  points.push_back(p4);

  std::vector<int> ranges;
  ranges.push_back(p1.second - p1.first);
  ranges.push_back(p2.second - p2.first);
  ranges.push_back(p3.second - p3.first);
  ranges.push_back(p4.second - p4.first);

  int range_index = -1;
  for(unsigned i = 0; i < ranges.size(); ++i)
  {
    if(range_index == -1)
    {
      range_index = ranges[i];
    }
    else if(ranges[ i ] < range_index)
    {
      range_index = i;
    }
  }

  // Check lowest point in the smallest range
  int small_range_start = points[ range_index ].first;

  std::vector<bool> small_range_status{ false, false, false, false };

  for(unsigned i = 0; i < points.size(); ++i)
  {
    if(points[ i ].first <= small_range_start && small_range_start <= points[ i ].second)
      small_range_status[i] = true;
  }

  int small_range_end = -1;
  bool small_range_end_set = false;
  for(unsigned i = 0; i < small_range_status.size(); ++i)
  {
    if(small_range_status[ i ] == false)
    {
      if(!small_range_end_set)
      {
        small_range_end = points[ i ].first;
        small_range_end_set = true;
      }
      else if(points[ i ].first < small_range_end )
      {
        small_range_end = points[ i ].first;
      }
    }
  }
  
  result.first = small_range_start;
  result.second = small_range_end;

  return result;
}

std::vector<int> number_725(std::vector<int> position1, std::vector<int> position2)
{
  int total = 0;

  std::sort(position1.begin(), position1.end());
  std::sort(position2.begin(), position2.end());

  std::vector<int> moves{ 0,0,0,0 };

  for(unsigned int i = 0; i < position1.size(); ++i)
  {
    moves[i] = (std::max(moves[i], std::abs(position1[i] - position2[i])));
  }

  return moves;
}

// Daily Coding Problem uses min-heap and max-heap
std::vector<double> number_727(std::vector<int> input)
{
  std::vector<double> medians;
  std::vector<int> temp;

  for(unsigned i = 0; i < input.size(); ++i)
  {
    temp.push_back(input[ i ]);
    std::sort(temp.begin(), temp.end());
    if(temp.size() % 2 == 1)
    {
      // Odd
      int index = (temp.size() / 2);
      medians.push_back(temp[ index ]);
    }
    else
    {
      //Even
      auto val = (temp[ temp.size() / 2 ] + temp[ (temp.size() / 2) - 1 ]) / 2.0;
      medians.push_back(val);
    }
  }

  return medians;
}




