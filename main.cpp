#include <iostream>
#include "extra.h"
#include <cstring> //Για μέγεθος συμβολοσειρών, σύγκριση κτλ
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

//#include "bintree.h"
//#include "bintreeavl.h"
//#include "hashtable.h"
//#include "sarray.h"
//#include "usarray.h"

int main()
{

  char *s;
  s=new char;
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

    cout<<s<<endl;
  }

  File.close(); //Κλείνεις το αρχείο
}
  