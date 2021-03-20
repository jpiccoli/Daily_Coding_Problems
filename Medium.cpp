#include "Medium.h"

#include <map>
#include <algorithm>

using key_type = std::vector<int>;
using cache_type = std::map<key_type, int>;

int collect_coins(std::vector< std::vector< int > > matrix, int row = 0, int column = 0, cache_type cache = cache_type());

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
