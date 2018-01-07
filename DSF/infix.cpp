#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
	public:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head;
	Stack(){head=NULL;}
	void push(int x);
	void pop();
	T top();
	bool isempty();
	void display();
};

template <class T> void Stack<T> :: push(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = (head==NULL) ? NULL : head;
	head = temp;
}

template <class T> void Stack<T> :: pop()
{
	Node* temp = head;
	head = head->next;
	delete temp;
}

template <class T> T Stack<T> :: top() {return head->data;}

template <class T> bool Stack<T> :: isempty() {return (head==NULL);}

template <class T> void Stack<T> :: display()
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

//Member functions end

int precede(char c)
{
	if(c=='^') return 3;
	if(c=='*' || c=='/' || c=='%') return 2;
	if(c=='+' || c=='-') return 1;
	if(c=='(') return 0;
	return -1;
}

string infixToPost(string str)
{
	int len = str.length();
	Stack<char> s;
	string res = "";

	for(int i=0; i<len; i++)
	{
		if(isalnum(str[i])) res+=str[i];
		else if(str[i]=='(') s.push(str[i]);
		else if(str[i]==')')
		{
            while(!s.isempty() && s.top()!='(')
                res += s.top(), s.pop();

            s.pop();
		}
		else
		{
			while(!s.isempty() && precede(str[i]) <= precede(s.top()))
				res += s.top(), s.pop();

			s.push(str[i]);
		}
	}

	while(!s.isempty())
		res+=s.top(), s.pop();

	return res;
}

int evalPost(string post)
{
	Stack<int> p;
	int len = post.length();
	for(int i=0; i<len; i++)
	{
		if(isalpha(post[i])) 
		{
			int x;
			cout<<"Enter value for "<<post[i]<<": "<<endl;
			cin>>x;
			p.push(x);
		}
		else
		{
			int y = p.top();
			p.pop();
			int x = p.top();
			p.pop();
			if(post[i]=='+') p.push(x+y);
			else if(post[i]=='-') p.push(x-y);
			else if(post[i]=='*') p.push(x*y);
			else if(post[i]=='/') p.push(x/y);
			else if(post[i]=='%') p.push(x%y);
			else if(post[i]=='^') p.push(x^y);
		}
	}
	return p.top();
}

string reverse(string str)
{
	int len = str.length();
	for(int i=0; i<=len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	return str;
}

int main()
{
	#ifndef CP
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string str;
	cin>>str;
	string post = infixToPost(str);
	cout<<"Postfix: "<<post<<endl;

	cout<<"Result: "<<evalPost(post)<<endl;

	/*
	string rs = reverse(str);
	for(int i=0; i<rs.length(); i++)
	{
		if(rs[i]=='(') rs[i]=')';
		else if(rs[i]==')') rs[i]='(';
	}

	string pre = infixToPost(rs);
	pre = reverse(pre);
	cout<<"Prefix: "<<pre<<endl;
	*/
	
}
