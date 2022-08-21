#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long determinant(vector< vector<long long> > m) 
{
  int matrix_size = m[0].size();
  vector< vector<long long> > new_m(matrix_size-1);
  long long matrix_det = 0;

  if (matrix_size == 1)               // checking for first order matrix case
      return m[0][0];
  if (matrix_size == 2)               // checking for second order matrix case
      return (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
  else if (matrix_size > 2)
  {
    for(int k = 0; k < matrix_size; k++)    // counting det through a submatrix det
    {
        for(int j = 0; j < matrix_size - 1; j++)    // building a submatrix
        {
            new_m[j].resize(matrix_size-1);
            for(int i = 0; i < matrix_size; i++)
            {
                if (i < k)
                    new_m[j][i] = m[j+1][i];
                else if (i > k)
                    new_m[j][i-1] = m[j+1][i];
            }
        }
        matrix_det += m[0][k] * determinant(new_m) * pow(-1, k);   // recursive call
    }
    return matrix_det;
  }
}