//Υλοποίηση 1) αταξινόμητος πίνακας
#include "arr.h"

void arr::insert(string &s) //εισαγωγή νέας λέξης
{
	if (c==size) //οι αυξήσεις που θα κάνουμε στον πίνακα θα είναι x2 θέσεις
	{
		word *temp= new word[2*size]; //ορίζουμε μεγαλύτερο πίνακα

		if(!temp)
		{
			cerr<<"!!!Memory Error!!!"<<endl;
		}
				
		for (int i=0; i<size; i++)
		{	
			temp[i].w=b[i].w;
			temp[i].t=b[i].t;
		}
		//memcpy(temp,b,size*sizeof(word)); //αντιγράφουμε τα δεδομένα

		delete [] b; //απελευθερώνουμε τον χώρο που έπιανε ο προηγούμενος πίνακας

		b = temp; //αντιγράφουμε την διεύθυνση του νέου πίνακα στον δείκτη μας
		size*=2; //αυξάνουμε το μέγεθος της size
	}
	b[c].w=s; //αντιγράφουμε συμβολοσειρά
	b[c].t=1; //αυξάνουμε επαναλήψεις
	//cout<<c<<endl;
	c++; //αυξάνουμε μετρητή
}

int arr::find(string &s) //αναζήτηση, δέχεται μία συμβολοσειρά για όρισμα
{
	for (int i=0; i<size; i++) //περνάει γραμμικά
	{
		if (b[i].w.compare(s)==0) //αν την βρει σε κάποιο κελί του πίνακα,
		{													
			b[i].t++;	//αυξάνει τις επαναλήψεις της λέξης
			return i; //επιστρέφει την θέση που το βρήκε, χωρίς ιδιαίτερο λόγο
		}
	}
	return -1; //διαφορετικά επιστρέφει τιμή φρουρό
}

void arr::del(string &s)
{
    int k=find(s);
    b[k].w=b[c-1].w;
    b[k].t=b[c-1].t;
    c--;
}