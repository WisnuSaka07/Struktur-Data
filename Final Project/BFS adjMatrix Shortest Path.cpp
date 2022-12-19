#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    protected:
        int v;
        vector<vector<int>> adj;

    public:
        Graph(int len) {
            v = len;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            vector<int> vec (v+1, 0);
        }

        void addEdge(int u, int v, int w){
            adj[u][v] = w;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                    if(adj[i][j] == -1) cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";
                    
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
                for (int it = 1; it <= v; it++)
                {

                        if(adj[curr][it] != -1 && adj[curr][it] + dist[curr] < dist[it]){
                            dist[it] = adj[curr][it] + dist[curr];
                            domain[it] = curr;
                            q.push(it);
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
    Graph Matrix(V);
 
    Matrix.addEdge(0, 1, 1);
    Matrix.addEdge(1, 2, 2);
    Matrix.addEdge(1, 3, 4);
    Matrix.addEdge(1, 20, 3);
    Matrix.addEdge(2, 4, 5);
    Matrix.addEdge(3, 16, 7);
    Matrix.addEdge(4, 5, 1);
    Matrix.addEdge(4, 6, 6);
    Matrix.addEdge(4, 16, 10);
    Matrix.addEdge(5, 7, 7);
    Matrix.addEdge(6, 10, 10);
    Matrix.addEdge(6, 14, 7);
    Matrix.addEdge(7, 8, 2);
    Matrix.addEdge(8, 9, 5);
    Matrix.addEdge(9, 11, 3);
    Matrix.addEdge(10, 12, 3);
    Matrix.addEdge(11, 12, 9);
    Matrix.addEdge(12, 13, 4);
    Matrix.addEdge(13, 14, 3);
    Matrix.addEdge(14, 15, 6);
    Matrix.addEdge(15, 16, 9);
    Matrix.addEdge(15, 17, 2);
    Matrix.addEdge(16, 18, 2);
    Matrix.addEdge(17, 18, 4);
    Matrix.addEdge(18, 19, 1);
    Matrix.addEdge(19, 20, 8);
      
    int TitikAwal, Tujuan;
    cout << "TitikAwal : " << endl;
    cin >> TitikAwal;
    cout << "Tujuan : " << endl;
    cin >> Tujuan;
    Matrix.BFS(TitikAwal, Tujuan);
 
    return 0;
}