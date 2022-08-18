#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string add(const string& const_a, const string& const_b) 
{
    int temp = 0;                                 // temp value
    int overflow = 0;                             // overflow value
    string a = const_a;
    string b = const_b;
    string temp_str;
    vector<int> result_vct(a.size() + b.size());  // vector value to store the result
    int vector_size = result_vct.size();          // vector size
  
    if(a.size() >= b.size())  // swap temp strings
    {
        temp_str = a;
        a = b;
        b = temp_str;
    }
    
    if(!a.compare("")) 
        a = "0";
    if(!b.compare(""))
        b = "0";
  
    for(size_t i = 0; i < a.size(); i++)  // adding the smallest number digits of a and b strings
    {
        result_vct[vector_size-i-1] += (stoi(a.substr(a.size()-i-1, 1)) + stoi(b.substr(b.size()-i-1, 1)));
        if(result_vct[vector_size-i-1] >= 10) // checking overflow
        {
            temp = result_vct[vector_size-i-1] % 10;
            overflow = result_vct[vector_size-i-1] / 10;
            result_vct[vector_size-i-1] = temp;
            result_vct[vector_size-i-1-1] += overflow;
        }
    }
    for(size_t j = a.size(); j < b.size(); j++)  // adding left number digits
    {
        result_vct[vector_size-j-1] += stoi(b.substr(b.size()-j-1, 1));
        if(result_vct[vector_size-j-1] >= 10) // checking overflow
        {
            temp = result_vct[vector_size-j-1] % 10;
            overflow =  result_vct[vector_size-j-1] / 10;
            result_vct[vector_size-j-1] = temp;
            result_vct[vector_size-j-1-1] += overflow;
        }
    }
  
  // delete unused vector space
  while(result_vct[0] == 0 && result_vct.size() != 1)
      result_vct.erase(result_vct.begin());
  
  // convert vector to string
  stringstream strstream;
  for (size_t k = 0; k < result_vct.size(); k++)
        strstream << result_vct[k];

  return strstream.str();
}