#include <iostream>
#define MAX 50
#define INF 999
using namespace std;

class Prims
{
	int n, e, g[MAX][MAX], visit[MAX];
public:
	Prims();
	void readgraph();
	void display();
	void primsAlgo();
};

Prims :: Prims()
{
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			g[i][j] = (i==j) ? 0 : INF;

	for(int i=0; i<MAX; i++)
		visit[i]=0;
}

void Prims :: readgraph()
{
	cout<<"Enter no. of nodes & edges: ";
	cin>>n>>e;
	cout<<"Enter edges:\n";
	for(int i=0; i<e; i++)
	{
		int a, b, w;
		cin>>a>>b>>w;
		if(a!=b)
		{
			g[a][b] = w;
			g[b][a] = w;
		}
		else i--;
	}
}

void Prims :: primsAlgo()
{
	int mst=0;
	visit[0] = 1;
	for(int c=0; c<n-1; c++)
	{
		int minVal = INF, src, dest;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(visit[i] && !visit[j] && g[i][j]<minVal)
				{
					minVal = g[i][j];
					src = i;
					dest = j;
				}
			}
		}
		visit[dest] = 1;
		mst+=minVal;
		cout<<src<<" --> "<<dest<<" = "<<minVal<<endl;
	}

	cout<<"Prims MST Value: "<<mst<<endl;
}

void Prims :: display()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	Prims p;
	p.readgraph();
	//p.display();
	p.primsAlgo();
}
