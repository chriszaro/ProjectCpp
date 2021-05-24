//Υλοποίηση 4) δυαδικό δένδρο αναζήτησης AVL
#include "avl.h"

AVL::AVL():BST() //λογικά δεν θα χρειαστεί κάπου
{
	h=0;
	left=right=nullptr;
}
 
AVL::AVL(string value):BST(value)
{
	h=1;
	left=right=nullptr;
}

//ύψος κόμβου
int AVL::getHeight(AVL* N)
{
	if (!N)
    return 0;
  return N->h;
}

// Get Balance factor of node N
int AVL::getBalance(AVL *N)
{
	if (!N)
		return 0;
	return (getHeight(N->left)) - getHeight(N->right);
}

AVL* AVL::rightRotate(AVL* y) //δεξιά περιστροφή
{
	AVL *x = y->left;
	AVL *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->h = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->h = max(getHeight(x->left), getHeight(x->right)) + 1;

	// Return new root
	return x;
}
 
// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
AVL* AVL::leftRotate(AVL* x)
{
	AVL *y = x->right;
	AVL *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->h = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->h = max(getHeight(y->left), getHeight(y->right)) + 1;

	// Return new root
	return y;
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
AVL* AVL::Insert(AVL* node, string key)
{
	/* 1. Perform the normal BST insertion */
	if (!node)
		return new AVL(key);

	if (key.compare(node->w) < 0)
		node->left = Insert(node->left, key);
	else if (key.compare(node->w) > 0)
		node->right = Insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->h = 1 + max(getHeight(node->left), getHeight(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key.compare(node->left->w)<0)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key.compare(node->right->w) > 0)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key.compare(node->left->w) > 0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key.compare(node->right->w) < 0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

bool AVL::search(AVL* root, string key, AVL* pos)
{
	if (!root) //αν δεν το βρήκε
		return false;

	if (key.compare(root->w)==0) //αν το στοιχείο είναι στην ρίζα που ελέγχεται τώρα
	{
		root->t++;
		pos=root;
		return true;
	}

	if (key.compare(root->w)>0) //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
		return search(root->right, key, pos);

	return search(root->left, key, pos); //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
}

void AVL::Inorder(AVL* root, ofstream &a) //ενδοδιατεταγμένη διάσχιση
{
	if (!root) {return;}
	Inorder(root->left, a);
	a << root->w << " " << root->t << endl;
	Inorder(root->right, a);
}

void AVL::Postorder(AVL* root, ofstream &a) //προδιατεταγμένη διάσχιση
{
	if (!root) {return;}
	Postorder(root->left, a);
	Postorder(root->right, a);
	a << root->w << " " << root->t << endl;
}

void AVL::Preorder(AVL* root, ofstream &a) //μεταδιατεταγμένη διάσχιση
{
	if (!root) {return;}
	a << root->w << " " << root->t << endl;
	Preorder(root->left, a);
	Preorder(root->right, a);
}

/* Given a non-empty binary search tree, 
return the node with minimum key value 
found in that tree. Note that the entire 
tree does not need to be searched. */
AVL* AVL::minValue(AVL* node)
{ 
    AVL* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left) 
      current = current->left; 
  
    return current; 
} 

// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
AVL* AVL::Delete(AVL* root, string key)
{ 
      
	// STEP 1: PERFORM STANDARD BST DELETE 
	if (!root) 
		return root; 

	// If the key to be deleted is smaller 
	// than the root's key, then it lies
	// in left subtree 
	if (key.compare(root->w) < 0) 
		root->left = Delete(root->left, key); 

	// If the key to be deleted is greater 
	// than the root's key, then it lies 
	// in right subtree 
	else if( key > root->w) 
		root->right = Delete(root->right, key); 

	// if key is same as root's key, then 
	// This is the node to be deleted 
	else
	{ 
		// node with only one child or no child 
		if(!root->left || !root->right) 
		{ 
			AVL *temp = root->left ? root->left : root->right; 

			// No child case 
			if (!temp) 
			{ 
				temp = root; 
				root = nullptr; 
			} 
			else // One child case 
			*root = *temp; // Copy the contents of the non-empty child 
			delete temp; 
		} 
		else
		{ 
			// node with two children: Get the inorder 
			// successor (smallest in the right subtree) 
			AVL* temp = minValue(root->right);

			// Copy the inorder successor's 
			// data to this node 
			root->w = temp->w; 

			// Delete the inorder successor 
			root->right = Delete(root->right,	temp->w); 
		} 
	} 

	// If the tree had only one node
	// then return 
	if (!root) 
		return root; 

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->h = 1 + max(getHeight(root->left), getHeight(root->right)); 

	// STEP 3: GET THE BALANCE FACTOR OF 
	// THIS NODE (to check whether this 
	// node became unbalanced) 
	int balance = getBalance(root); 

	// If this node becomes unbalanced, 
	// then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && getBalance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	return root; 
} 