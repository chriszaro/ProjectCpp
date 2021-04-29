#include <iostream>
#include "ex.h"
#include <cstring> //Για μέγεθος συμβολοσειρών, σύγκριση κτλ
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

#include "arr.h" // δεν έχω δοκιμάσει αν δουλεύει το delete
#include "sarr.h" //ούτε εδώ, επίσης το 0 μπαίνει στην 1η θέση

//#include "bintree.h"
//#include "bintreeavl.h"
//#include "hash.h"


int main()
{
	arr a;
	sarr b;
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

		if (strcmp(s,"\0"))
		{
			int fa = a.find(s);
			int fb = b.find(s);
			if (fa==-1)
				a.insert(s);
			if (fb!=-1)
				b.insert(s,fb);

		}
	}

  File.close(); //Κλείνεις το αρχείο

	ofstream oa, ob;
    oa.open("oa.txt",ios::out);
		ob.open("ob.txt",ios::out);
    if (oa.is_open() && ob.is_open())
    {
				for (int i=0; i<a.getC(); i++)
        {
            oa<<a.getB(i)<<endl<<a.getT(i)<<endl<<endl;
        }
        for (int i=0; i<b.getC(); i++)
        {
            ob<<b.getB(i)<<endl<<b.getT(i)<<endl<<endl;
        }
    }
	oa.close();
}
  