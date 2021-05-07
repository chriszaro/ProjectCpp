//Υλοποίηση 1) αταξινόμητος πίνακας
#include "arr.h"

arr::arr()
{
	size=50;
	b=new word[50];
}

void arr::insert(char*s) //εισαγωγή νέας λέξης
{
	if (c%50==0) //οι αυξήσεις που θα κάνουμε στον πίνακα θα είναι +50 θέσεις
	{
		word *temp= new word[size+50]; //ορίζουμε μεγαλύτερο πίνακα
		memcpy(temp,b,size*sizeof(word)); //αντιγράφουμε τα δεδομένα

		delete [] b; //απελευθερώνουμε τον χώρο που έπιανε ο προηγούμενος πίνακας

		b = temp; //αντιγράφουμε την διεύθυνση του νέου πίνακα στον δείκτη μας
		size+=50; //αυξάνουμε το μέγεθος της size
	}
	strcpy(b[c].w,s); //αντιγράφουμε συμβολοσειρά
	b[c].t=1; //αυξάνουμε επαναλήψεις
	c++; //αυξάνουμε μετρητή
}

int arr::find(char* s) //αναζήτηση, δέχεται μία συμβολοσειρά για όρισμα
{
	for (int i=0; i<size; i++) //περνάει γραμμικά
	{
		if (strcmp(b[i].w,s)==0) //αν την βρει σε κάποιο κελί του πίνακα,
		{													
			b[i].t++;	//αυξάνει τις επαναλήψεις της λέξης
			return i; //επιστρέφει την θέση που το βρήκε
		}
	}
	return -1; //διαφορετικά επιστρέφει τιμή φρουρό
}

void arr::del(char*s) //διαγραφή καταχώρησης υπάρχουσας λέξης
{
	int k= find(s); //αναζήτηση για να βρούμε σε ποια θέση είναι η λέξη

	for (int i=k; i<c-1; i++) //ξεκινάμε το i από αυτήν την θέση
	{
		strcpy(b[i].w,b[i+1].w); //αντιγράφουμε μία προς μία τις λέξεις στην προηγούμενη θέση στον πίνακα, ουσιαστικα δεν "διαγράφουμε", αλλά κάνουμε overwrite
		b[i].t=b[i+1].t;
	}
	strcpy(b[c].w,"");
	b[c].t=0;
}