#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;

    public:
        Graph(int len) {
            v = len;
            list<int> l;
            adj.assign(v+1, l);
            vector<int> vec (v+1, 0);
        }

        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void BFS(int TitikAwal, int Tujuan){
            cout << endl;
            cout << "BFS" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[TitikAwal] = 0;
            q.push(TitikAwal);
            visit[TitikAwal] = true;

            while (!q.empty())
            {
                int curr = q.front();
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++)
                {

                    if(weight[make_pair(curr, *it)] + dist[curr] < dist[*it]){
                        dist[*it] = weight[make_pair(curr, *it)] + dist[curr];
                        domain[*it] = curr;
                        q.push(*it);
                        for (int i = 1; i <= v; i++)
                        {
                            if(dist[i] < 10000 )
                                cout << dist[i] << " ";
                            else 
                                cout << ". ";
                        }
                        cout << endl;
                    }
                }
                q.pop();
            }

            for (int i = 1; i <= v ; i++)
            {
                cout << domain[i] << " ";
            }
            cout << endl;
            

            vector<int> result;
            int i = Tujuan;
            while(true){
                result.push_back(i);
                if(i == TitikAwal) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << result[i] << " ";
            }
            
            cout << endl << "Bobot = " << dist[Tujuan] << endl;
            
        }

};

int main() {

int V = 21;
    Graph List(V);
 
    List.addEdge(0, 1, 1);
    List.addEdge(1, 2, 2);
    List.addEdge(1, 3, 4);
    List.addEdge(1, 20, 3);
    List.addEdge(2, 4, 5);
    List.addEdge(3, 16, 7);
    List.addEdge(4, 5, 1);
    List.addEdge(4, 6, 6);
    List.addEdge(4, 16, 10);
    List.addEdge(5, 7, 7);
    List.addEdge(6, 10, 10);
    List.addEdge(6, 14, 7);
    List.addEdge(7, 8, 2);
    List.addEdge(8, 9, 5);
    List.addEdge(9, 11, 3);
    List.addEdge(10, 12, 3);
    List.addEdge(11, 12, 9);
    List.addEdge(12, 13, 4);
    List.addEdge(13, 14, 3);
    List.addEdge(14, 15, 6);
    List.addEdge(15, 16, 9);
    List.addEdge(15, 17, 2);
    List.addEdge(16, 18, 2);
    List.addEdge(17, 18, 4);
    List.addEdge(18, 19, 1);
    List.addEdge(19, 20, 8);
      
    int TitikAwal, Tujuan;
    cout << "TitikAwal : " << endl;
    cin >> TitikAwal;
    cout << "Tujuan : " << endl;
    cin >> Tujuan;
    List.BFS(TitikAwal, Tujuan);
     
    return 0;

}