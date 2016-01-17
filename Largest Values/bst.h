/* File: bst.h       

  Header file for a binary search tree class

*/


class bst
{

	public:
		bst(); //basic constructor
		~bst(); //basic destructor


		class node
		{
			public:
				int data;
				node* left;
				node* right;				
		};

	public:
		node* root;
		void insert ( int k );
		void insert_helper ( node* root, int k ); //inserts k into BST
		int the_root(); // returns the value in root
		bool search_helper (node* root, int t);
		bool search( int t ); //searches for t in BST
};


//Constructors and Destructors:
/*------------------------------------------------------------------------------------*/

bst::bst() {

	root = NULL;
	
}

bst::~bst() {

	delete root;

}

//Methods:
/*-----------------------------------------------------------------------------------------*/

//Insert k into the BST (taken from lectures): 
void bst::insert ( int k ) {


	if (root == NULL) {

		node* temp = new node;
		temp->data = k;
		temp->right = NULL;
		temp->left = NULL;

		root = temp;

		return;
	}
	else {

		insert_helper(root, k );
	}

	
}

void bst::insert_helper( node* root, int k ) {

	if ( k <= root->data ) {
		if (root->left != NULL) {
			insert_helper ( root->left, k );
		}
		else {
			node* keyl = new node;
			keyl->data = k;
			keyl->right= NULL;
			keyl->left = NULL;

			root->left = keyl;
		}
	}

	else {
		if (root->right != NULL) {
			insert_helper ( root->right, k );
		}
		else {
			node* keyr = new node;
			keyr->data = k; 
			keyr->right = NULL;
			keyr->left = NULL;

			root->right = keyr;

		}
	}
}

//Returns True when t is found in the BST and otherwise False (taken from lectures)
bool bst::search (int t) {

	if (root == NULL) {
		return false;
	}

	else search_helper (root, t);
}

bool bst::search_helper (node* root, int t) {
	if (t == root->data) {
		return true;
	}

	else if ( t < root->data && root->left != NULL) {
		return search_helper(root->left, t);
	}

	else if (t > root->data && root->right != NULL) {
		return search_helper(root->right, t);
	}

	else {
		return false;
	}
}

//PRE: BST CANNOT BE EMPTY (it will segfault if you do)
int bst::the_root() {

	int blah = root->data;
	return blah;	
}