//Υλοποίηση 4) δυαδικό δένδρο αναζήτησης AVL
#ifndef avl_h
#define avl_h
#include "bst.h"

class AVL : protected BST
{
	int h;
	AVL *left, *right; //οι δείκτες στο αριστερό και δεξί παιδί
	public:
		//κατασκευαστές
    AVL();
    AVL(string);

		int getBalance(AVL*);
		int getHeight(AVL*);

		AVL* rightRotate(AVL*);
		AVL* leftRotate(AVL*);

    bool search(AVL*, string);
		AVL* Insert(AVL*, string); //εισαγωγή
		AVL* Delete(AVL*, string);
		AVL* minValue(AVL*);

    void Inorder(AVL*, ofstream&);
		void Postorder(AVL*, ofstream&);
		void Preorder(AVL*, ofstream&);

};
#endif