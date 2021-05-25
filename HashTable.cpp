//Joseph Larson - gha3bn - 3/29/21 - HashTable.cpp

#include <string>
#include <iostream>
#include "HashTable.h"

using namespace std;

bool checkPrime(unsigned int p);
int getNextPrime(unsigned int n);

HashTable::HashTable(){
  size = getNextPrime(5);
  elements = 0;
  table.resize(size);
}

HashTable::HashTable(unsigned int m){
  int nextPrime =  getNextPrime(m);
  size = nextPrime;
  table.resize(size);
}

HashTable::~HashTable() {
}

/*
    Dan J Bernstein's djb2 algorithm as implemented by Tu Vo
 https://medium.com/swlh/hash-tables-in-c-with-the-djb2-algorithm-21f14ba7ca88

   Reduced collisions from 1.7 billion to 5297, reducing time requirement for
   search() funtion massively
*/

unsigned int HashTable::computeHash(string const& s){
  
  unsigned int hash;
  int c;
    
  hash = 5381;
  for(auto x: s){
    c = x;
    hash = hash * 33 + c;
  }
  return (hash % size);

  

  
}

void HashTable::insertValue(string const& s){
  if(isValidString(s)){
    unsigned int key = computeHash(s);
    table[key].push_front(s);
  }
}

bool HashTable::search(string const& s){
  bool exists = false;
  unsigned int key = computeHash(s);
  list<string>::iterator it;
  for(it = table[key].begin(); it != table[key].end(); it++){
    if(it->compare(s) == 0){
      exists = true;
      break;
    }
  }

  return exists;
  
}
/*

*/
int HashTable::collisionsDetected(){
  return collisions;
}

bool HashTable::isValidString(string const& s){
  bool isValid = true;
  if(s.length() < 3) return false;
  for(int i = 0; i < s.length(); i++){
    int v = (int)(s.at(i));
    if(v < 65 || v > 122 || (v > 90 && v < 97)){
      isValid = false;
      break;
    }
  }

  return isValid;
  
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
