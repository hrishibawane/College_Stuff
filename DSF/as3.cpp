#include <iostream>
#define MAX(a, b) (a > b ? a : b)
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node *root, *newroot;

class Tree
{
public:

	Tree() {root = newroot = NULL;}
	Node* search(Node* temp, int n);
	void insert(int n, int p, char c);
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	void leafnodes(Node*);
	int depth(Node*);
	Node* copytree(Node*, Node*);

};

Node* Tree :: search(Node* temp, int p)
{
	if(temp==NULL) return NULL;

	if(temp->data==p) return temp;
	
	Node* tl = search(temp->left, p);
	Node* tr = search(temp->right, p);

	if(tl!=NULL) return tl;
	else if(tr!=NULL) return tr;
	else return NULL;

}

void Tree :: insert(int n, int p, char c)
{
	Node* temp = new Node;
	temp->data = n;
	temp->left = temp->right = NULL;

	if(root==NULL) 
	{
		root=temp;
		return;
	}

	Node* x = root;
	Node* curr = search(x, p);
	if(curr==NULL)
	{
		cout<<"Required Node not present :(\n"<<endl;
		return;
	}

	if(c=='l' && curr->left==NULL) curr->left = temp;

	if(c=='r' && curr->right==NULL) curr->right = temp;
}

void Tree :: inorder(Node* temp)
{
	if(temp==NULL) return;

	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}

void Tree :: preorder(Node* temp)
{
	if(temp==NULL) return;

	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}

void Tree :: postorder(Node* temp)
{
	if(temp==NULL) return;

	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}

void Tree :: leafnodes(Node* temp)
{
	if(temp==NULL) return;

	if(temp->left==NULL && temp->right==NULL) cout<<temp->data<<" ";
	leafnodes(temp->left);
	leafnodes(temp->right);
}

int Tree :: depth(Node* temp)
{
	if(temp==NULL) return 0;

	int ld = depth(temp->left);
	int rd = depth(temp->right);
	return MAX(ld, rd) + 1;
}

Node* Tree :: copytree(Node* root, Node* newroot)
{
	if(root==NULL) return NULL;
	else
	{
		newroot = new Node;
		newroot->data = root->data;

		newroot->left = copytree(root->left, newroot->left);
		newroot->right = copytree(root->right, newroot->right);
	}
	return newroot;
}

int main()
{
	Tree t;
	int ch, n, p;
	char c;
	while(1)
	{
		cout<<"\n1. Insert\n2. Display Inorder\n3. Display Preorder\n4. Display Postorder\n5. Display Leafnodes\n6. Depth\n7. Create Copy\n8. Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter data to be entered: ";
					cin>>n;
					cout<<"Enter parent node: ";
					cin>>p;
					cout<<"Enter whether left child or right child(l/r): ";
					cin>>c;
					t.insert(n, p, c);
					break;

			case 2: cout<<"Inorder: ";
					t.inorder(root);
					break;

			case 3: cout<<"Preorder: ";
					t.preorder(root);
					break;

			case 4: cout<<"Postorder: ";
					t.postorder(root);
					break;

			case 5: cout<<"Leafnodes: ";
					t.leafnodes(root);
					break;

			case 6: cout<<"Depth: "<<t.depth(root)<<endl;
					break;

			case 7: t.copytree(root, newroot);
					cout<<"Success\n";
					break;

			case 8: return 0;
		}
	}
}





