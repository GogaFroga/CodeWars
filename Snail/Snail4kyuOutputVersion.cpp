/* output version */
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
        std::cout << j << " iteration\n";
        for(int i = j; i <= matrix_size-1-j; i++)  // for example [0][from 0 to size]
        {
            std::cout << j << i << "-" << snail_map[j][i] << " ";
            snail_res.push_back(snail_map[j][i]);
        }
      
        std::cout << std::endl << "array: ";
        for(unsigned long i = 0; i < snail_res.size(); i++)
            std::cout << " {" << snail_res[i] << "}";
        std::cout << std::endl;
      
        for(int i = j+1; i <= matrix_size-1-j; i++)  // for example [from 0 to size][size]
        {
            std::cout << j << i << "-" << snail_map[i][matrix_size-1-j] << " ";
            snail_res.push_back(snail_map[i][matrix_size-1-j]);
        }
      
        std::cout << std::endl << "array: ";
        for(unsigned long i = 0; i < snail_res.size(); i++)
            std::cout << " {" << snail_res[i] << "}";
        std::cout << std::endl;
      
        for(int i = matrix_size-2-j; i >= j; i--) // for example [size][from size to 0]
        {
            std::cout << j << i << "-" << snail_map[matrix_size-1-j][i] << " ";
            snail_res.push_back(snail_map[matrix_size-1-j][i]);
        }
      
        std::cout << std::endl << "array: ";
        for(unsigned long i = 0; i < snail_res.size(); i++)
            std::cout << " {" << snail_res[i] << "}";
        std::cout << std::endl;
      
        k++;
        for(int i = matrix_size-2-j; i >= k; i--) // for example [from size to 0+k][0+j]
        {
            std::cout << j << i << "-" << snail_map[i][j] << " ";
            snail_res.push_back(snail_map[i][j]);
        }
        j++;
      
        std::cout << std::endl << "array: ";
        for(unsigned long i = 0; i < snail_res.size(); i++)
            std::cout << " {" << snail_res[i] << "}";
        std::cout << std::endl;
    }
    
    return {snail_res};
}