#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int> > &g, bool visited[], int i, stack<int> &s)
{
	visited[i] = true;	
	for(int j=0;j<g[i].size();j++)
	{
		if(visited[g[i][j]]==false)
		{
			topoSort(g, visited, g[i][j], s);
		}
	}	
	s.push(i);	
}

int main()
{
	// test cases
	int t;
	cin>>t;
	while(t--)
	{
		// inputs 
		int e, v;
		cin>>e>>v;
		int a[2*e];
		for(int i=0;i<(2*e);i++) cin>>a[i];
		
		// create graph
		vector<vector<int> > g(v);
		for(int i=0;i<(2*e);i=i+2) g[a[i]].push_back(a[i+1]);
		
		// solution
		bool visited[v] = {false};    	
		stack<int> s;
		for(int i=0;i<v;i++)
			if(visited[i]==false)
				topoSort(g, visited, i, s);
											
		// output
		while(!s.empty())
		{
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<"\n";	
	}
	return 0;
}
