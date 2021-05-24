#include <iostream>
#include <fstream> //file stream, για να διαβάζεις αρχεία
using namespace std;

#include "clear.h"
#include "sarr.h" //εισάγει την κλάση των 2 πινάκων //ΔΕΝ ΕΧΩ ΔΟΚΙΜΑΣΕΙ ΑΝ ΔΟΥΛΕΥΕΙ Η ΔΙΑΓΡΑΦΗ
#include "avl.h"

int main()
{
	BST d, *root = nullptr, *pos;
	AVL e, *avlroot=nullptr, *pos2;
	string s;

	ifstream File; //Το File είναι η μεταβλητή που έχει το αρχείο.

  File.open("small-file.txt"); //Ανοίγει το αρχείο

  if (!File) //Ελέγχεις ότι υπάρχει το αρχείο και κατάφερε να το ανοίξει
  {
    cerr << "Unable to open file";
		return 1;
  }
	else
	{
		do
		{
			File >> s;
			s=clear(s);
		}
		while(s.empty());

		root=d.Insert(root, s);
		avlroot=e.Insert(avlroot, s);
		
		while (File >> s) //Διαβάζεις από το αρχείο, λέξη λέξη
		{
			s=clear(s); //την καθαρίζεις από σκουπίδια (αφήνει μόνο τα γράμματα)

			if (!s.empty()) //αποκλείεις συμβολοσειρές αριθμών και συμβόλων
			{
				if (!d.search(root, s, pos))
					d.Insert(root, s);
				if (!e.search(avlroot, s, pos2))	
					avlroot=e.Insert(avlroot, s);
			}
		}

		File.close(); //Κλείνεις το αρχείο
	}

	ofstream a, b, c, f, g, h;
	a.open("preorder.txt");
	b.open("inorder.txt");
	c.open("postorder.txt");
	f.open("preorder1.txt");
	g.open("inorder1.txt");
	h.open("postorder1.txt");
	if (a.is_open() && b.is_open() && c.is_open() && f.is_open() && g.is_open() && h.is_open())
	{
		d.Preorder(root, a);
		d.Inorder(root, b);
		d.Postorder(root, c);
		e.Preorder(avlroot, f);
		e.Inorder(avlroot, g);
		e.Postorder(avlroot, h);

	}
	a.close();
	b.close();
	c.close();
	f.close();
	g.close();
	h.close();
}

/*int main()
{
	arr a;
	sarr b;
  string s;

	ifstream File; //Το File είναι η μεταβλητή που έχει το αρχείο.

  File.open("small-file.txt"); //Ανοίγει το αρχείο

  if (!File) //Ελέγχεις ότι υπάρχει το αρχείο και κατάφερε να το ανοίξει
  {
    cerr << "Unable to open file";
		return 1;
  }
	else
	{
		while (File >> s) //Διαβάζεις από το αρχείο, λέξη λέξη
		{
			s=clear(s); //την καθαρίζεις από σκουπίδια (αφήνει μόνο τα γράμματα)

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
				oa<<a.getB(i)<<" "<<a.getT(i)<<endl;
			for (int i=0; i<b.getC(); i++)
				ob<<b.getB(i)<<" "<<b.getT(i)<<endl;
		}
		oa.close();
	}
}*/