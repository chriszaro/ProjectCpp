#include <iostream>
#include "bintree.h"
#include "bintreeavl.h"
#include "hashtable.h"
#include "sarray.h"
#include "usarray.h"

#include <cstring>
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

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
		
    cout<<s<<endl;
  }

  File.close(); //Κλείνεις το αρχείο
}
  