#include "Easy.h"

//std::vector<int> number_489(std::vector<int> arr)
//{
//}

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




























