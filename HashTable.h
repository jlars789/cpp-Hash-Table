//Joseph Larson - gha3bn - 3/29/21 - HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class HashTable {

 public:

  HashTable();
  HashTable(unsigned int size);
  
  ~HashTable();

  unsigned int computeHash(string const& s);

  void insertValue(string const& s);

  string retrieveValue(unsigned int key);

  bool search(string const& s);

  int collisionsDetected();
  

 private:

  vector<list<string>> table;
  unsigned int size;
  int collisions;
  int elements;

  bool isValidString(string const& s);

  
};


#endif
