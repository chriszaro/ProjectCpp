//Υλοποίηση 1) αταξινόμητος πίνακας
#ifndef arr_h
#define arr_h
#include "ex2.h"
class arr //κλάση αταξινόμητου
{
	protected:
		int size;
		word *b;
		int c=0;
	public:
		arr();

		//αυτά θα φύγουν στην τελική έκδοση
		char* getB(int i){return b[i].w;};
		int getT(int i){return b[i].t;};
		int getC(){return c;};
		//τέλος
		
		virtual void insert(char*s);
		virtual int find(char* s);
		void del(char*s);
};
#endif