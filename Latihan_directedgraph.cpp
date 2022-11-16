#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int V; 

	t<int>> adj;
public:
	Graph(int V); 

	
	void addEdge(int v, int w);

	
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
	
	vector<bool> visited;
	visited.resize(V,false);

	
	list<int> queue;

	
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		
		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}


int main()
{
	Graph g(5);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.addEdge(0, 1);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 4) \n";
	g.BFS(4);

	return 0;
}

