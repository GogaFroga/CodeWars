#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string multiply(string a, string b) 
{
    int temp = 0;                                 // temp value
    int overflow = 0;                             // overflow value
    vector<int> result_vct(a.size() + b.size());  // vector value to store the result
    int vector_size = result_vct.size();          // vector size
  
    if ( !(a.compare("0") && b.compare("0")) )
        return("0");
  
    for(size_t j = 0; j < a.size(); j++)
        for(size_t i = 0; i < b.size(); i++)
        {
            temp = stoi(a.substr(a.size()-j-1, 1)) * stoi(b.substr(b.size()-i-1, 1));
            result_vct[vector_size-i-j-1] += temp;
            if(result_vct[vector_size-i-j-1] >= 10) // checking overflow
            {
                temp = result_vct[vector_size-i-j-1] % 10;
                overflow =  result_vct[vector_size-i-j-1] / 10;
                result_vct[vector_size-i-j-1] = temp;
                result_vct[vector_size-i-j-1-1] += overflow;
            }
        }

  // delete unused vector space
  while(result_vct[0] == 0)
      result_vct.erase(result_vct.begin());
  
  // convert vector to string
  stringstream strstream;
  for (size_t k = 0; k < result_vct.size(); k++)
        strstream << result_vct[k];

  return strstream.str();
}