#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

// defining graph
class Graph
{
	int v;
	list<pair<int,int> > *adj;
	
	public: 
		Graph(int v);
		void addEdge(int u, int v, int w);
		void shortestPath(int s);
};


// allocating memory
Graph::Graph(int v)
{
	this->v = v;
	adj = new list<pair<int,int> > [v];	
}

// adding edge
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

// find shortest paths to all nodes from source vertex
void Graph::shortestPath(int src)
{
	set<pair<int,int> > s;
	vector<int> dist(v,INF);
	
	s.insert(make_pair(0,src));
	dist[src] = 0;
	
	while(!s.empty())
	{
		pair<int,int> temp = *(s.begin());
		s.erase(s.begin());
		int u = temp.second;
		
		list<pair<int,int> > :: iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i)
		{
			int x = (*i).first;
			int wt = (*i).second;
			
			if(dist[x]>(dist[u]+wt))
			{
				if(dist[x]!=INF) s.erase(s.find(make_pair(dist[x],x)));
				dist[x] = dist[u]+wt;
				s.insert(make_pair(dist[x],x));
			}
		}	
	}
	
	cout<<"vertex"<<" "<<"minimum distance from it\n";
	for(int i=0;i<v;++i)
		cout<<"  "<<i<<"  "<<dist[i]<<"\n";
}

// NOTE: vertices have values 1 to n.
int main()
{
	int n; int e; // verices and edges
	cin>>n>>e;
	Graph g(n);
	for(int i=1;i<=e;i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		g.addEdge(a, b, c);
	}
	g.shortestPath(0); // change src accordingly...
	return 0;	
} 
