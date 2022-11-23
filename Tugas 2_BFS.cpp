#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Graph {
    protected:
        int a;
        list<int> adj[100];
        int pred[100];
        int dist[100];

    public:
        Graph(int len) {
            a = len;
        }

        void addEdge(int b, int a){
            adj[b].push_back(a);
        }

        void showGraph(){
            for (int i = 0; i < a; i++)
            {
                list<int>::iterator it;
                cout << i << " ";
                for(it = adj[i].begin(); it != adj[i].end(); ++it){
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

        void BFS(int start){
            cout << "=======" << endl;
            bool visited[100];
            for (int i = 0; i < a; i++)
            {
                visited[i] = false;
                pred[i] = -1;
                dist[i] = -1;
            }
            
            queue<int> q;
            visited[start] = true;
            dist[start] = 0;

            list<int>::iterator it;
            q.push(start);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {
                    int index = *it;
                    if(!visited[index])
                    {
                        visited[index] = true;
                        q.push(index);
                        dist[index] = dist[curr] + 1;
                        pred[index] = curr;

                    }
                }
            }

            for (int i = 0; i < a; i++)
            {
                cout << dist[i] << " " << pred[i] << endl;
            }
            
        }
};


int main(){
    Graph graph1(5);

    graph1.addEdge( 4, 2);
    graph1.addEdge( 4, 3);
    graph1.addEdge( 2, 1);
    graph1.addEdge( 2, 3);
    graph1.addEdge( 1, 3);
    graph1.addEdge( 0, 1);
    
    graph1.showGraph();

    graph1.BFS(0);
}