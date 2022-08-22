#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
    if(snail_map[0].empty())
        return {};
    
    std::vector<int> snail_res = {};
    int matrix_size = snail_map.size();
  
    if (matrix_size == 1)
    {
      snail_res.push_back(snail_map[0][0]);
      return snail_res;
    }
  
    int j = 0;
    int k = 0;
    while(j < 1 + matrix_size/2)
    {
        for(int i = j; i <= matrix_size-1-j; i++)  // for example [0][from 0 to size]
            snail_res.push_back(snail_map[j][i]);

        for(int i = j+1; i <= matrix_size-1-j; i++)  // for example [from 0 to size][size]
            snail_res.push_back(snail_map[i][matrix_size-1-j]);
      
        for(int i = matrix_size-2-j; i >= j; i--) // for example [size][from size to 0]
            snail_res.push_back(snail_map[matrix_size-1-j][i]);
      
        k++;
        for(int i = matrix_size-2-j; i >= k; i--) // for example [from size to 0+k][0+j]
            snail_res.push_back(snail_map[i][j]);
        j++;
    }
    
    return {snail_res};
}