#include <iostream>
#define MAX 20
using namespace std;

struct Node
{
	int a, b, wt;
};

class Kruskal
{
	int parent[MAX], n, e;
	Node edg[MAX], res[MAX];
public:
	Kruskal();
	void createGraph();
	void sort();
	int find(int);
	void kruskalAlgo();
	void display();
};

Kruskal :: Kruskal()
{
	for(int i=0; i<MAX; i++)
		parent[i]=-1;
}

void Kruskal :: createGraph()
{
	cout<<"Enter no. of nodes and edges: ";
	cin>>n>>e;
	cout<<"Enter edges with weights:\n";
	for(int i=0; i<e; i++)
		cin>>edg[i].a>>edg[i].b>>edg[i].wt;
}

void Kruskal :: sort()
{
	for(int i=0; i<e; i++)
		for(int j=0; j<e-i; j++)
			if(edg[j].wt>edg[j+1].wt)
			{
				Node temp = edg[j];
				edg[j] = edg[j+1];
				edg[j+1] = temp;
			}
}

int Kruskal :: find(int i)
{
	return (parent[i]==-1) ? i : find(parent[i]);
}

void Kruskal :: kruskalAlgo()
{
	sort();
	int k=0, i=0;
	while(k<n-1)
	{
		int v1=edg[i].a, v2=edg[i].b, w=edg[i].wt;
		int p1 = find(v1);
		int p2 = find(v2);
		i++;
		if(p1==p2) continue;
		parent[p2] = p1;
		res[k].a = v1;
		res[k].b = v2;
		res[k++].wt = w;
	}
}

void Kruskal :: display()
{
	cout<<"\nKruskal's MST:\n";
	for(int i=0; i<n-1; i++)
		cout<<res[i].a<<" "<<res[i].b<<" "<<res[i].wt<<endl;
}

int main()
{
	Kruskal k;
	k.createGraph();
	k.kruskalAlgo();
	k.display();
}