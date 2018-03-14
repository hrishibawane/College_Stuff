#include <iostream>
#define MAX 50
#define INF 999
using namespace std;

class Graph
{
	int nodes, edges, src, wt[MAX][MAX], visit[MAX], dist[MAX], pred[MAX];
public:
	Graph(int, int);
	void createGraph();
	int getClosestNode(int);
	void initialize();
	void djikstra();
	void path(int);
	void dispDist();
	void disp();
	
};

Graph :: Graph(int n, int e)
{
	nodes=n; edges=e;
	for(int i=0; i<nodes; i++)
		for(int j=0; j<nodes; j++)
			wt[i][j] = (i==j) ? 0 : INF;
}

void Graph :: createGraph()
{
	for(int i=0; i<edges; i++)
	{
		int start, end, weight;
		cout<<"Enter start, end & weight: ";
		cin>>start>>end>>weight;
		wt[start][end] = weight;
	}
	
	cout<<"Enter source: ";
	cin>>src;
	if(src<0 || src>nodes-1)
	{
		cout<<"Node not in graph\n";
		return;
	}
	
}

void Graph :: initialize()
{
	for(int i=0; i<nodes; i++)
		visit[i]=0, dist[i]=INF, pred[i]=-1;
		
	dist[src]=0;
}

int Graph :: getClosestNode(int i)
{
	int minDist = INF, CN;
	for(; i<nodes; i++)
		if(!visit[i] && minDist>dist[i]) 
			minDist=dist[i], CN=i;
			
	return CN;
}

void Graph :: djikstra()
{
	initialize();
	for(int i=0; i<nodes; i++)
	{
		int CN = getClosestNode(i);
		visit[CN] = 1;
		
		for(int j=0; j<nodes; j++)
			if(!visit[j] && wt[CN][j]>0)
				if(dist[j]>dist[CN]+wt[CN][j])
				dist[j]=dist[CN]+wt[CN][j], pred[j]=CN;
	}
}

void Graph :: path(int i)
{
    if(pred[i]==-1) return;
 
    path(pred[i]);
 
    cout<<i<<" ";
}

void Graph :: dispDist()
{
	cout<<"Vertex\t"<<"Distance\t"<<"Path\t"<<endl;
	for(int i=0; i<nodes; i++)
	{
		cout<<src<<" - "<<i<<"\t"<<dist[i]<<"\t";
		path(i);
		cout<<endl;
	}
	
}

void Graph :: disp()
{
	for(int i=0; i<nodes; i++)
	{
		for(int j=0; j<nodes; j++)
			cout<<wt[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int n, e;
	cout<<"Enter nodes & edges: ";
	cin>>n>>e;
	Graph g(n, e);
	g.createGraph();
	g.djikstra();
	g.dispDist();
	//g.disp();
}






