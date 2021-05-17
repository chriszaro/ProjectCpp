//Υλοποίηση 3) δυαδικό δένδρο αναζήτησης
#ifndef bst_h
#define bst_h
#include <string>
#include <fstream>
using namespace std;

class BST //BinarySearchTree, Δυαδικό Δένδρο Αναζήτησης
{
	private: 
		BST *left, *right; //οι δείκτες στο αριστερό και δεξί παιδί
	protected:
		string w;
		int t;
	public:
		//κατασκευαστές
    BST();
    BST(string);

    bool search(BST*, string);
		BST* Insert(BST*, string); //εισαγωγή
		BST* Delete(BST*, string);

    void Inorder(BST*, ofstream&);
		void Postorder(BST*, ofstream&);
		void Preorder(BST*, ofstream&);

};
#endif