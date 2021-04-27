//Υλοποίηση 2) ταξινομημένος πίνακας
#include "sarr.h"
void swap(word *b, int xp, int yp) 
{ 
    char* temp = new char;
		int t;
		strcpy(temp, b[xp].w);
		t=b[xp].t;
    strcpy(b[xp].w, b[yp].w);
		b[xp].t=b[yp].t;
		strcpy(b[yp].w, temp);
    b[yp].t= t; 
} 
  
// A function to implement bubble sort 
void bubbleSort(word *b, int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (strcmp(b[j].w,b[j+1].w)>0)
            swap(b, j, j+1);
}

int sarr::find(char* s) //αναζήτηση, δέχεται μία συμβολοσειρά για όρισμα
{
	int start=0; //αρχή του πίνακα που θα ψάξουμε
	int end=c; //"τέλος" του πίνακα
	int m;
	while (start<=end)
	{
		m=(start+end)/2; //παίρνουμε το μεσαίο στοιχείο
		if (strcmp(s,b[m].w)==0) //αν την βρει στο μεσαίο
		{													
			b[m].t++;	//αυξάνει τις επαναλήψεις της λέξης
			return -1; //επιστρέφει -1 όταν την βρίσκει
		}
		else if (strcmp(s,b[m].w)>0) //αν η λέξη είναι μεγαλύτερη από την μεσαία, τότε θα ψάξουμε από την μέση του πίνακα προς το τέλος
		{
			start=m+1;
		}
		else //αν είναι μικρότερη, θα ψάξουμε από την μέση προς την αρχή
		{
			end=m-1;
		}
	}
	return 1;
};

void sarr::insert(char*s, int p) //εισαγωγή νέας λέξης
{
	if (c%50==0) //οι αυξήσεις που θα κάνουμε στον πίνακα θα είναι +50 θέσεις
	{
		word *temp; //δημιουργούμε δείκτη σε νέο πίνακα

		temp = new word[size+50]; //ορίζουμε μεγαλύτερο πίνακα
		memcpy(temp,b,size*sizeof(word)); //αντιγράφουμε τα δεδομένα

		delete [] b; //απελευθερώνουμε τον χώρο που έπιανε ο προηγούμενος πίνακας

		b = temp; //αντιγράφουμε την διεύθυνση του νέου πίνακα στον δείκτη μας
		size+=50; //αυξάνουμε το μέγεθος της size
	}
	strcpy(b[p].w,s); //αντιγράφουμε συμβολοσειρά
	b[p].t++; //αυξάνουμε επαναλήψεις
	c++; //αυξάνουμε μετρητή
	bubbleSort(b, c);
}