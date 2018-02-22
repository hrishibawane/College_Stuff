#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node
{
	char data[2];
	node *left, *right;
}node;

typedef struct stack
{
	node *arr;
	int flag;
}stack;

class ExpressionTree
{
	string str;
	public:
	ExpressionTree()
	{
		str[0]='\0';
	}
	node *create();
	void insert();
	void displayIn(node*);
	void displayPre(node*);
	void displayPost(node*);
	void non_recursive_inorder(node*);
	void non_recursive_preorder(node*);
	void non_recursive_postorder(node*);
	
class stack1
{
	public:
	stack data[30];
	int top;
	stack1(){ top =-1; }
	int empty()
	{ 
		if(top==-1) return 1;
		return 0;
	}
	void push(stack t){	data[++top] = t; }
	stack pop(){ return data[top--]; }
};
};

node* ExpressionTree :: create()
{
	node *root;
	int top = -1,i=0;
	node **stack = new node*[50];
	do
	{
		node *temp=new node;
		temp->data[0] = str[i];
		temp->left = NULL;
		temp->right = NULL;
		if(isalnum(str[i]))
			stack[++top] = temp;
		else
		{
			temp->right = stack[top--];
			temp->left = stack[top--];
			stack[++top] = temp;
		}
		i++;
	}while(str[i]!='\0');
	root = stack[top];
	return root;
}
	
void ExpressionTree::insert()
{
	cout<<"Enter postfix expression: "<<endl;
	cin>>str;
}

void ExpressionTree :: displayIn(node* root)
{
	if(root==NULL) return;
	
	displayIn(root->left);
	cout<<root->data<<" ";
	displayIn(root->right);
}

void ExpressionTree :: displayPre(node* root)
{
	if(root==NULL) return;
	
	cout<<root->data<<" ";
	displayPre(root->left);
	displayPre(root->right);
}

void ExpressionTree :: displayPost(node* root)
{
	if(root==NULL) return;
	
	displayPost(root->left);
	displayPost(root->right);
	cout<<root->data<<" ";
}

void ExpressionTree :: non_recursive_inorder(node *root)
{
	node *temp = root;
	node **stack = new node*[10];
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
	}while(temp!=NULL || top!=-1);
}

void ExpressionTree :: non_recursive_preorder(node* root)
{
	node *temp = root;
	node **stack = new node*[10];
	int top = -1;
	do
	{
		while(temp!=NULL)
		{
			stack[++top] = temp;
			cout<<temp->data<<" ";
			temp = temp->left;
		}
		temp = stack[top--];
		temp = temp->right;
	}while(temp!=NULL || top!=-1);
};

void ExpressionTree :: non_recursive_postorder(node* root)
{
	stack s;
	stack1 st;
	node *temp = root;
	node *temp1;
	while(temp!=NULL)
	{
		s.arr = temp;
		s.flag = 0;
		st.push(s);
		temp = temp->left;
	}
	while(!st.empty())
	{
		s=st.pop();
		if(s.flag==0)
		{
			s.flag=1;
			st.push(s);
			temp = s.arr;
			temp = temp->right;
			while(temp!=NULL)
			{
				s.arr = temp;
				s.flag = 0;
				st.push(s);
				temp = temp->left;
			}
		}
		else
		{
			temp1 = s.arr;
			cout<<temp1->data<<" ";
		}
	}
}
		
int main()
{
ExpressionTree e;
node *root=new node;
e.insert();
root = e.create();
cout<<"\nInorder Expression-> ";
e.displayIn(root);
cout<<"\nPreorder Expression-> ";
e.displayPre(root);
cout<<"\nPostorder Expression-> ";
e.displayPost(root);
cout<<"\nInorder Expression (Non-recursive)-> ";
e.non_recursive_inorder(root);
cout<<"\nPreorder Expression (Non-recursive)-> ";
e.non_recursive_preorder(root);
cout<<"\nPostorder Expression (Non-recursive)-> ";
e.non_recursive_postorder(root);

cout<<"\n\n";
return 0;
}


				
