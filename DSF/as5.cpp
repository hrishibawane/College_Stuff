#include <iostream>
#define MAX 50
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

class BST
{
	Node* root;
public:
	BST() {root=NULL;}
	Node* getroot() {return root;}
	void create();
	Node* insert(Node*, Node*);
	Node* search(Node*, int);
	void mirror();
	void iterInorder();
	void iterPreorder();
	void iterPostorder();
	void levelOrder();
	Node* deleteNode(Node*, int);
};

void BST :: create()
{
	int n, x;
	cout<<"Enter no. of nodes: ";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Enter value: ";
		cin>>x;
		Node* temp = new Node;
	    temp->data = x;
	    temp->left = temp->right = NULL;
		root = insert(root, temp);
	}
}

Node* BST :: insert(Node* root, Node* temp)
{
	if(root==NULL) return temp;
	
	if(temp->data < root->data) 
		root->left = insert(root->left, temp);
	if(temp->data > root->data) 
		root->right = insert(root->right, temp);
		
	return root;
}

Node* BST :: search(Node* root, int key)
{
	if(root==NULL || root->data==key) return root;
	
	if(key<root->data) 
		return search(root->left, key);
	if(key>root->data)
		return search(root->right, key);
		
	return NULL;
}

void BST :: mirror()
{
	Node* q[MAX];
	int front=-1, rear=-1;
	q[++rear] = root;

	while(front!=rear)
	{
		Node* curr = q[++front];

		Node* temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;

		if(curr->left) q[++rear] = curr->left;
		if(curr->right) q[++rear] = curr->right;
	}
}

void BST :: iterInorder()
{
	Node* temp = root;
	Node* stack[MAX];
	int top = -1;
	do
	{
		while(temp!=NULL)
		{
			stack[++top] = temp;
			temp = temp->left;
		}
		temp = stack[top--];
		cout<<temp->data<<" ";
		temp = temp->right;
	} while(temp!=NULL || top!=-1);

}

void BST :: iterPreorder()
{
    if(root==NULL) return;

    Node* stack[MAX];
    int top=-1;
    stack[++top] = root;

    while(top!=-1)
    {
        Node* temp = stack[top--];
        cout<<temp->data<<" ";

        if(temp->right) stack[++top] = temp->right;
        if(temp->left) stack[++top] = temp->left;
    }
}

void BST :: iterPostorder()
{
	if(root==NULL) return;
    
    Node* temp = root;
    Node* stack[MAX];
    int top=-1;
    do
    {
        while(temp)
        {
            if(temp->right) stack[++top] = temp->right;

            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];

        if(temp->right && stack[top]==temp->right)
        {
            top--;
            stack[++top] = temp;
            temp = temp->right;
        }
        else
        {
            cout<<temp->data<<" ";
            temp = NULL;
        }
    } while(top!=-1);
}

void BST :: levelOrder()
{
	Node* q[MAX];
	int front=0, rear=-1;
	q[++rear] = root;
	q[++rear] = NULL;
	int lvl = 1;
	while(front!=rear)
	{
		Node* temp = q[front++];
		if(temp==NULL)
		{
			if(q[front]!=NULL) q[++rear]=NULL;
			lvl++;
		}
		else
		{
			cout<<"Level "<<lvl<<" - "<<temp->data<<endl;
			if(temp->left) q[++rear] = temp->left;
			if(temp->right) q[++rear] = temp->right;
		}
	}
}

Node* BST :: deleteNode(Node* temp, int key)
{
    if(temp==NULL) return temp;

    if (key < temp->data)
        temp->left = deleteNode(temp->left, key);
    else if (key > temp->data)
        temp->right = deleteNode(temp->right, key);
    else
    {
        if (temp->left==NULL)
        {
            Node* curr = temp->right;
            delete temp;
            return curr;
        }
        else if (temp->right == NULL)
        {
            Node* curr = temp->left;
            delete temp;
            return curr;
        }


        Node* curr = temp->right;
        while(curr->left!=NULL)
        	curr = curr->left;

        temp->data = curr->data;

        temp->right = deleteNode(temp->right, curr->data);
    }
    return temp;
}



int main()
{
	BST b;
	Node* temp;
	int ch, key;
	while(1)
	{
		cout<<"1. Create\n2. Search\n3. Iterative inorder\n4. Iterative preorder\n5. Iterative postorder\n6. LevelOrder\n7. Delete Node\n8. Mirror\n9. Exit\n";
		cin>>ch;

		switch(ch)
		{
			case 1: b.create(); break;

			case 2: cout<<"Enter node to search: ";
					cin>>key;
					temp = b.search(b.getroot(), key);
					temp ? cout<<"Found\n" : cout<<"Not Found\n";
					break;

			case 3: b.iterInorder(); cout<<endl;
					break;

			case 4: b.iterPreorder(); cout<<endl;
					break;

			case 5: b.iterPostorder(); cout<<endl;
					break;

			case 6: b.levelOrder(); cout<<endl;
					break;

			case 7: cout<<"Enter node to delete: ";
					cin>>key;
					temp = b.deleteNode(b.getroot(), key);
					break;

			case 8: b.mirror(); break;

			case 9: return 0;
		}
	}
}


