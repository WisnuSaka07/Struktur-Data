#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<pair<int, int> >* adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
 
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::shortestPath(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> >
        pq;
       
    vector<int> dist(V, INF);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
       
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
int main()
{
    int V = 21;
    Graph g(V);
 
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 20, 3);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 16, 7);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 6);
    g.addEdge(4, 16, 10);
    g.addEdge(5, 7, 7);
    g.addEdge(6, 10, 10);
    g.addEdge(6, 14, 7);
    g.addEdge(7, 8, 2);
    g.addEdge(8, 9, 5);
    g.addEdge(9, 11, 3);
    g.addEdge(10, 12, 3);
    g.addEdge(11, 12, 9);
    g.addEdge(12, 13, 4);
    g.addEdge(13, 14, 3);
    g.addEdge(14, 15, 6);
    g.addEdge(15, 16, 9);
    g.addEdge(15, 17, 2);
    g.addEdge(16, 18, 2);
    g.addEdge(17, 18, 4);
    g.addEdge(18, 19, 1);
    g.addEdge(19, 20, 8);
   
   
    g.shortestPath(0);
 
    return 0;
}
