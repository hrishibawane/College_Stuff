#include<iostream>
#include<cstring>
using namespace std;

template <class T>
class Stack
{
	struct node
	{
		T data;
		node *next;
	};
struct node *top;
string expr;
public:
Stack()
{
	top = NULL;
}

void getExp(string ex)
{
	expr = ex;
}

string inToPost()
{
	return inToPost(expr);
}

string inToPre()
{
	return inToPre(expr);
}

int evalPost()
{
	return evalPost(inToPost());
}

int evalPre()
{
	return evalPre(inToPre());
}


private:
int evalPost(string postfix)
{
	string temp = postfix, in="",infix="";
	int ans=0,mans=0,x=0;
	
	while(x<temp.length())
	{
		char t = temp.at(x);
		if(isOperator(t))
		{
			string te = "";
			char ch = pop();
			if(ch!='@')
			{
				te = t+te+ch;
				cout<<"Enter value of "<<ch<<": ";
				int ich1;
				cin>>ich1;
				ch=pop();
				if(ch!='@')
				{
					te = te+ch;
					in = in+te;
					push('@');
					cout<<"Enter the value of "<<ch<<": ";
					int ich2;
					cin>>ich2;
					ans = solve(ich1,t,ich2);
				}
				else
				{
					in = in+te;
					push('@');
					ans = solve(ans,t,ich1);
				}
			}
			else
			{
				in = t+in;
				ch = pop();
				if(ch!='@')
				{
					cout<<"Enter the value of  "<<ch<<": ";
					int ich3;
					cin>>ich3;
					ans = solve(ich3,t,ans);
				}
			}
		}
		else
		{
			if(isEmpty() && in!="")
			{
				push('@');
				infix = infix + in;
				in = "";
				mans +=ans;
			}
			push(t);
		}
		x++;
	}
	infix = infix+in;
	mans = mans + ans;
	return mans;
}

int evalPre(string prefix)
{
	Stack<char> s1;
	int i,preval;
	string poststr="";
	for(i=0;i<prefix.length();i++)
		s1.push(prefix.at(i));
		
	while(s1.isEmpty()!=true)
		poststr.append(1,s1.pop());
	
	preval = s1.evalPost(poststr);
	return preval;
}
	


int solve(int a,char op, int b)
{
	switch(op)
	{
		case '+': return (a+b);
		case '-': return (a-b);
		case '*': return (a*b);
		case '/': return (a/b);
		case '%': return (a%b);
	}
}

bool isOperator(char op)
{
	if(op=='+'||op=='-'||op=='*'||op=='/'||op=='%')
		return true;
	return false;
}

string inToPre(string itpr_exp)
{
	string expRev = reverse(itpr_exp);
	string revPost = inToPost(expRev);
	return reverse(revPost);
}

string reverse(string rev)
{
	string r = "";
	int l = rev.length()-1;
	for(int x=l;x>=0;x--)
	{
		char t = rev.at(x);
		if(t=='(')
			t=')';
		else if(t==')')
			t='(';
			
		r = r+t;
	}
	return r;
}

string inToPost(string itp_exp)
{
	string postfix = "";
	string temp = itp_exp;
	int x=0,y=0;
	int pr;
	while(x<temp.length())
	{
		char cu = temp.at(x);
		if(cu=='(')
		{
			push(cu);
			x++;
			continue;
		}
		else if(cu==')')
		{
			while(!isEmpty() && getTop()!='(')
				postfix = postfix + pop();
			char temp = pop();
			x++;
			continue;
		}
		else
		{
			pr = precedence(cu);
			if(pr==3)
				postfix = postfix + cu;
			else
			{
				if(isEmpty())
					push(cu);
				else
				{
					while(getTop()!='(' && pr>=precedence(getTop()))
						postfix = postfix+pop();
					push(cu);
				}
			}
		}
		x++;
	}
	while(!isEmpty())
		postfix = postfix + pop();
	return postfix;
}


int precedence(T op)
{
	if(op=='/'||op=='*'||op=='%')
		return 1;
	else if(op=='+'||op=='-')
		return 2;
	else
		return 3;
}

void push(T d)
{
	struct node *enter;
	if(isEmpty())
	{
		enter = new node;
		enter->data = d;
		enter->next = NULL;
		top = enter;
	}
	else
	{
		struct node *temp = new node;
		temp->data=d;
		temp->next=top;
		top = temp;
	}
}

T pop()
{
	if(isEmpty())
		cout<<"";
	else
	{
		T temp = top->data;
		top=top->next;
		return temp;
	}
}

bool isEmpty()
{
	if(top==NULL)
		return true;
	return false;
}

T getTop()
{
	if(isEmpty())
		cout<<""<<endl;
	else
		return top->data;
}
};

int main()
	{
	Stack <char> sll;
	int ch,ch1;
	string exp = "";
	
	do
	{
		cout<<"\n1)Enter expression\n2)Postfix\n3)Prefix\n4)Postfix Evaluate\n5)Prefix Evaluate"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"Enter the expression: "<<endl; 
				cin>>exp;
				sll.getExp(exp);
				break;
				
			case 2: if(exp!="")
					cout<<"Postfix Expression: "<<sll.inToPost()<<endl;
				else
					cout<<"Enter the expression first."<<endl;
				break;

			case 3: if(exp!="")
					cout<<"Prefix Expression: "<<sll.inToPre()<<endl;
				else
					cout<<"Enter the expression first."<<endl;
				break;
				
			case 4: if(exp!="")
				{	
					cout<<"Answer = "<<sll.evalPost()<<endl;
				}
				else
					cout<<"Enter the expression first."<<endl;
				break;

			case 5:  if(exp!="")
				{	
					cout<<"Answer = "<<sll.evalPre()<<endl;
				}
				else
					cout<<"Enter the expression first."<<endl;
				break;
				
			default: cout<<"Wrong option."<<endl;
		}
	}while(ch!=5);
	return 0;
}

