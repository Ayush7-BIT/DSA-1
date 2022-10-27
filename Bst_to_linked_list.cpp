//1
#include <iostream>
#include<climits>
#include <queue>
using namespace std;

class node {
	public:
	int data;
	node* left;
	node* right;
	node(int d): data(d) {
		left = right = NULL;
	}
};

node* InsertInBST(node* root, int d) {
	if (root == NULL) {
		root = new node(d);
		return root;
	}
	if (root->data >= d) {
		root->left = InsertInBST(root->left, d);
	}
	else {
		root->right = InsertInBST(root->right, d);
	}
	return root;
}

node* createBST() {
	node* root = NULL;
	int d;
	cin >> d;
	if (d == -1) return root;

	while (d != -1) {
		 root = InsertInBST(root, d);
		 cin >> d;
	}
	return root;
}


void preorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


void inorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}





node* searchBST(node* root, int key) {
	if (!root) {
		return NULL;
	}

	if (root->data == key) {
		return root;
	}
	else if (root->data > key) {
		return searchBST(root->left, key);
	}
	else {
		return searchBST(root->right, key);
	}
}



class LinkedList {
    public: 
        node *head, * tail;
};
LinkedList BSTtoLL(node* root)
{
    LinkedList l;
    //base case
    if(!root){
        l.head =l.tail=NULL;
        return l;
    }
    //recursive case
    //agar left right dono nahi hai to
    if(!root -> left and !root -> right ){
        l.head = l.tail = root;
		return l;
    }
    //agar right hai only
    else if( !root -> left and root -> right){
        LinkedList rightLL= BSTtoLL(root-> right );
        root->right = rightLL.head;
        l.head= root;
        l.tail=rightLL.tail;
        return l;
    }
    //agar left ho only 
    else if(root->left and !root-> right){ 
        LinkedList leftLL= BSTtoLL(root-> left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //agar dono side hai nodes
    else{
        LinkedList leftLL = BSTtoLL( root->left);
        LinkedList rightLL = BSTtoLL( root->right);  
		leftLL.tail->right=root;
		root->right=rightLL.head;
		l.head=leftLL.head;
		l.tail=rightLL.tail;
		return l;
    }
}
void printLL( node* head){
    while (head)
    {
        cout<<head->data<<"->";
        head=head->right;
    }
    cout<< "NULL\n";
    
}


int main() {
	// 8 3 10 1 6 14 4 7 13 -1
	node* root = createBST();

	// preorder(root);
	// cout << endl;
	// inorder(root);
	// cout << endl;
	// postorder(root);
	// cout << endl;
	// printRange(root, 6, 13);
	// cout << endl;
	// levelOrderTraversal(root);

	// node* ans = searchBST(root, 1);
	// if (!ans) {
	// 	cout << "Not Found\n";
	// }
	// else {
	// 	cout << "Found: " << ans->data << endl;
	// }

	// if (isBST(root)) {
	// 	cout << "BST hai\n";
	// }
	// else {
	// 	cout << "BST Nahi hai\n";
	// }

	// Pair x = isBalanced(root);
	// if (x.balanced) {
	// 	cout << "BST Balanced hai\n";
	// }
	// else {
	// 	cout << "BST Balanced Nahi hai\n";
	// }
    LinkedList l= BSTtoLL(root);
    printLL(l.head);

	return 0;
}