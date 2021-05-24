//Υλοποίηση 2) ταξινομημένος πίνακας
#include "sarr.h"

void sarr::insert(string &s, int p) //εισαγωγή νέας λέξης
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
	
	for (int i=c-1; i>=p; i--) //ξεκινάμε το i από αυτήν την θέση
	{
		b[i+1].w=b[i].w; //αντιγράφουμε μία προς μία τις λέξεις στην προηγούμενη θέση στον πίνακα, ουσιαστικα δεν "διαγράφουμε", αλλά κάνουμε overwrite
		b[i+1].t=b[i].t;
	}
	b[p].w=s; //αντιγράφουμε συμβολοσειρά
	b[p].t=1; //αυξάνουμε επαναλήψεις
	c++; //αυξάνουμε μετρητή
}

int sarr::binarySearch(word *b, string &s, int low, int high)//βρίσκει την θέση στην οποία πρέπει να εισαχθεί η λέξη για να παραμείνει ταξινομημένος
{
	if (high <= low)
		return (s.compare(b[low].w)>0) ? (low + 1) : low; // s>b[low].w

	int mid = (low + high) / 2; 

	if (s.compare(b[mid].w)==0)
		return mid + 1;

	if (s.compare(b[mid].w)>0)
		return binarySearch(b, s, mid + 1, high);

	return binarySearch(b, s, low,	mid - 1);
}

bool sarr::find(string &s, int pos) //αναζήτηση, δέχεται μία συμβολοσειρά για όρισμα
{
	if (c==0)
	{
		pos=0;
		return false;
	}
	int start=0; //αρχή του πίνακα που θα ψάξουμε
	int end=c-1; //"τέλος" του πίνακα
	int m;
	while (start<=end)
	{
		m=(start+end)/2; //παίρνουμε το μεσαίο στοιχείο
		if (b[m].w.compare(s)==0) //αν την βρει στο μεσαίο
		{													
			b[m].t++;	//αυξάνει τις επαναλήψεις της λέξης
			pos=m;
			return true;
		}
		else if (s.compare(b[m].w)>0) //αν η λέξη είναι μεγαλύτερη από την μεσαία, τότε θα ψάξουμε από την μέση του πίνακα προς το τέλος
		{
			start=m+1;
		}
		else //αν είναι μικρότερη, θα ψάξουμε από την μέση προς την αρχή
		{
			end=m-1;
		}
	}
	
	pos=binarySearch(b,s,0,c-1); //βρίσκει την θέση που πρέπει να μπει το στοιχείο
	return false;
};

void sarr::del(string &s) //διαγραφή καταχώρησης υπάρχουσας λέξης
{
	int k;
	find(s, k); //αναζήτηση για να βρούμε σε ποια θέση είναι η λέξη

	for (int i=k; i<c-1; i++) //ξεκινάμε το i από αυτήν την θέση
	{
		b[i].w=b[i+1].w; //αντιγράφουμε μία προς μία τις λέξεις στην προηγούμενη θέση στον πίνακα, ουσιαστικα δεν "διαγράφουμε", αλλά κάνουμε overwrite
		b[i].t=b[i+1].t;
	}
	b[c].w="";
	b[c].t=0;
}
