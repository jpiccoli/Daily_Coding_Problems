#include "Easy.h"

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




























