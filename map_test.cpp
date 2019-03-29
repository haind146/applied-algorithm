//
// Created by haind on 27/03/2019.
//

// map::clear
#include <iostream>
#include <map>

int main ()
{
  std::map<int,bool> mymap;

  mymap[1]=true;
  mymap[2]=true;
  mymap[3]=true;

  std::cout << mymap[3];
  return 0;
}