#include "Medium.h"

#include <map>
#include <algorithm>

using key_type = std::vector<int>;
using cache_type = std::map<key_type, int>;

int collect_coins(std::vector< std::vector< int > > matrix, int row = 0, int column = 0, cache_type cache = cache_type());

// Support function for number_583()
int collect_coins(std::vector< std::vector< int > > matrix, int row, int column, cache_type cache)
{
  int num_rows = matrix.size();
  int num_columns = matrix[ 0 ].size();

  bool is_bottom = (row == num_rows - 1);
  bool is_rightmost = (column == num_columns - 1);

  auto itr = cache.find({ row, column });
  if(itr == cache.end())
  {
    if(is_bottom && is_rightmost)
    {
      cache[ {row, column} ] = matrix[ row ][ column ];
    }
    else if(is_bottom)
    {
      cache[ {row, column} ] = matrix[ row ][ column ] + collect_coins(matrix, row, column + 1, cache);
    }
    else if(is_rightmost)
    {
      cache[ {row, column} ] = matrix[ row ][ column ] + collect_coins(matrix, row + 1, column, cache);
    }
    else
    {
      cache[ {row, column} ] = matrix[ row ][ column ] + std::max(collect_coins(matrix, row + 1, column, cache), collect_coins(matrix, row, column + 1, cache));
    }
  }

  return cache[ {row, column} ];
}

int number_583(std::vector< std::vector< int > > matrix)
{
  return collect_coins(matrix);
}

// Support function for number_636()
int find_minimal(std::vector<int> arr, int low, int high)
{
  if(low == high)
    return arr[ low ];

  int mid = (high + low) / 2;
  if(arr[ mid ] < arr[ high ])
  {
    // Right part is sorted => answer is in left part
    high = mid;
  }
  else
  {
    // Left part is sorted => answer is in right part
    low = mid + 1;
  }

  return find_minimal(arr, low, high);
}

int number_636(std::vector<int> numbers)
{
  return find_minimal(numbers, 0, (int)numbers.size() - 1);
}
