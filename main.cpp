#include <iostream>
#include "ex.h"
#include <string> //Για μέγεθος συμβολοσειρών, σύγκριση κτλ
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

#include "sarr.h" //εισάγει την κλάση των 2 πινάκων //ΔΕΝ ΕΧΩ ΔΟΚΙΜΑΣΕΙ ΑΝ ΔΟΥΛΕΥΕΙ Η ΔΙΑΓΡΑΦΗ

int main()
{
	arr a;
	sarr b;
  string s;

	ifstream File; //Το File είναι η μεταβλητή που έχει το αρχείο.

  File.open("small-file.txt"); //Ανοίγει το αρχείο

  if (!File) //Ελέγχεις ότι υπάρχει το αρχείο και κατάφερε να το ανοίξει
  {
    cerr << "Unable to open file";
  }
	else
	{
		while (File >> s) //Διαβάζεις από το αρχείο, λέξη λέξη
		{
			s=clear(s); //την καθαρίζεις από σκουπίδια

			if (!s.empty()) //αποκλείεις συμβολοσειρές αριθμών και συμβόλων
			{
				int fa = a.find(s); //αναζήτηση σε αταξηνόμητο
				if (fa==-1)
					a.insert(s);
				int fb=b.find(s);
				if (fb!=-1)
					b.insert(s,fb);
			}
		}

		File.close(); //Κλείνεις το αρχείο

		ofstream oa, ob;
		oa.open("oa.txt");
		ob.open("ob.txt");
		if (oa.is_open() && ob.is_open() )
		{
			for (int i=0; i<a.getC(); i++)
				oa<<a.getB(i)<<endl<<a.getT(i)<<endl<<endl;
			for (int i=0; i<b.getC(); i++)
				ob<<b.getB(i)<<endl<<b.getT(i)<<endl<<endl;
		}
		oa.close();
	}
}
  