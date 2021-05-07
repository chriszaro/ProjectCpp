//Υλοποίηση 2) ταξινομημένος πίνακας
#ifndef sarr_h
#define sarr_h
#include "arr.h"
class sarr : public arr
{
  public:
		sarr():arr(){}; //μπορεί και να μην χρειάζεται
		void insert(char*s, int);
		int find(char* s);
		int binarySearch(word *b, char* s, int low, int high);
};
#endif