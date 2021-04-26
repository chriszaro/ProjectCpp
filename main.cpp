#include <iostream>
#include "ex.h"
#include <cstring> //Για μέγεθος συμβολοσειρών, σύγκριση κτλ
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

#include "arr.h"

//#include "bintree.h"
//#include "bintreeavl.h"
//#include "hash.h"
//#include "sarr.h"

int main()
{
	arr a;
  char *s=new char;

  ifstream File; //Το File είναι η μεταβλητή που έχει το αρχείο.

  File.open("test.txt"); //Ανοίγει το αρχείο

  if (!File) //Ελέγχεις ότι υπάρχει το αρχείο και κατάφερε να το ανοίξει
  {
    cerr << "Unable to open file";
    exit(1);   //Τερματίζει το πρόγραμμα
  }

  while (File >> s) //Διαβάζεις από το αρχείο, λέξη λέξη
  {
		s=removeNonLatin(s);

		int f = a.find(s);
	
		if (f==-1)
			a.insert(s);
  }

  File.close(); //Κλείνεις το αρχείο

	for (int i=0; i<a.getC(); i++)
	{
		cout<<a.getB(i)<<endl<<a.getT(i)<<endl<<endl;
	}
}
  