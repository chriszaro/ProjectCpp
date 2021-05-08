//Υλοποίηση 1) αταξινόμητος πίνακας
#ifndef arr_h
#define arr_h
#include "ex2.h"

class arr //κλάση αταξινόμητου
{
	protected:
		int size;
		word *b;
		int c;
	public:
		arr()
		{
			size=0;
			b=new word[size];
			c=0;
		}
		~arr()
		{
			delete [] b;
		}

		//αυτά θα φύγουν στην τελική έκδοση
		string getB(int i){return b[i].w;};
		int getT(int i){return b[i].t;};
		int getC(){return c;};
		//τέλος
		
		virtual void insert(string);
		virtual int find(string);
		void del(string);
};
#endif