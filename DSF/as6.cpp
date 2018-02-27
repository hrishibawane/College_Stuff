#include <iostream>
#include <limits.h>
#define MAX 20
using namespace std;

struct Node
{
	int vert, comm, month, frnd;
	Node* next;
};

struct Qnode
{
	int data;
	Qnode* next;
};

class Queue
{
public:
    Qnode *front, *rear;
    Queue() {front=rear=NULL;}
    void push(int);
    void pop();
    bool isempty();
};

void Queue :: push(int x)
{
	Qnode* p = new Qnode;
	p->data = x;
    p->next = NULL;
    if(front==NULL)
    {
        front = rear = p;
        return;
    }
    rear->next = p;
    rear = p;
}

void Queue :: pop()
{
    Qnode* temp = front;
    if(front==rear) rear=rear->next;
    front=front->next;
    delete temp;
}

bool Queue :: isempty() {return (front==NULL && rear==NULL);}

class Graph
{
	bool visit[MAX];
	Node* g[MAX];
	Node v[MAX];
	int n; 
public:
	Graph() {n=0;}
	void create();
	void insert(int, int);
	void birthMonth();
	void minMaxComm();
	void maxFriends();
	void bfs();
	void dfs_init();
	void dfs(int);
	void display();
	
};

void Graph :: create()
{
	int a, b, e;
	cout<<"Enter no. of vertices: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		g[i] = NULL;
		v[i].frnd = 0;
		cout<<"Enter birth month of "<<i<<" user: ";
		cin>>v[i].month;
		cout<<"Enter no. of comments: ";
		cin>>v[i].comm;
	}
	
	cout<<"Enter total no. of edges: ";
	cin>>e;
	for(int i=0; i<e; i++)
	{
		cout<<"Enter edge: ";
		cin>>a>>b;
		insert(a, b);
		insert(b, a);
		v[a].frnd++;
		v[b].frnd++;	
	}
	
}

void Graph :: insert(int a, int b)
{
	Node* temp;
	temp = new Node;
	temp->vert = b;
	temp->next = NULL;
	
	if(g[a]==NULL) g[a] = temp;
	else
	{
		Node* curr = g[a];
		while(curr->next!=NULL)
			curr = curr->next;
		
		curr->next = temp;
	}
}

void Graph :: birthMonth()
{
	int m;
	cout<<"Enter month: "; cin>>m;
	cout<<"Users having birthdays in "<<m<<" month: ";
	for(int i=0; i<n; i++)
		if(v[i].month==m) cout<<i<<" ";
	cout<<endl;
}

void Graph :: minMaxComm()
{
	int maxVal = INT_MIN, minVal = INT_MAX;
	int maxi, mini;
	for(int i=0; i<n; i++)
	{
		if(v[i].comm > maxVal) 
			maxVal=v[i].comm, maxi=i;
		if(v[i].comm < minVal) 
			minVal=v[i].comm, mini=i;
	}
	
	cout<<"Max no of comments are "<<maxVal<<" by user: "<<maxi<<endl;
	cout<<"Min no of comments are "<<minVal<<" by user: "<<mini<<endl;
}

void Graph :: maxFriends()
{
	int maxVal = INT_MIN, maxi;
	for(int i=0; i<n; i++)
		if(v[i].frnd > maxVal)
			maxVal=v[i].frnd, maxi=i;
	
	cout<<"User having max friends: "<<maxi<<"("<<maxVal<<")"<<endl;
}

void Graph :: bfs()
{
    cout<<"BFS: ";
    Queue q;

    for(int i=0; i<n; i++)
        visit[i]=0;

    q.push(0);
    while(!q.isempty())
    {
        int i = (q.front)->data;
        q.pop();
        if(visit[i]) continue;
        
        cout<<i<<" ";
        visit[i] = 1;
        Node* p = g[i];
        while(p!=NULL)
        {
            if(!visit[p->vert]) q.push(p->vert);
            p = p->next;
        }  
    }
    cout<<endl;
}

void Graph :: dfs_init()
{
    cout<<"DFS: ";
    for(int i=0; i<n; i++)
        visit[i]=0;
    
    dfs(0);
    cout<<endl;
}

void Graph :: dfs(int i)
{
    Node* p = g[i];
    visit[i] = 1;
    
    cout<<i<<" ";
    
    while(p!=NULL)
    {
        i = p->vert;
        if(!visit[i]) dfs(i);
        
        p = p->next;
    }
    
}

void Graph :: display()
{
	for(int i=0; i<n; i++)
	{
		cout<<i<<" - ";
		Node* temp = g[i];
		while(temp!=NULL)
		{
			cout<<temp->vert<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	Graph gp;
	int ch;
	while(1)
	{
		cout<<"1. Create Graph\n2. Display Graph\n3. Min & Max Comments\n4. Find users by birth month\n5. User having max friends\n6. BFS\n7. DFS\n8. Exit\n";
		cin>>ch;

		switch(ch)
		{
			case 1: gp.create();
					break;

			case 2: gp.display();
					break;

			case 3: gp.minMaxComm();
					break;

			case 4: gp.birthMonth();
					break;

			case 5: gp.maxFriends();
					break;

			case 6: gp.bfs();
					break;

			case 7: gp.dfs_init();
					break;

			case 8: return 0;
		}
	}
	 
}


