//Υλοποίηση 2) ταξινομημένος πίνακας
#ifndef sarr_h
#define sarr_h
#include "arr.h"
class sarr : public arr
{
  public:
		void insert(char*s, int);
		int find(char* s);
};
#endif