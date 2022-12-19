#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    protected:
        int v;
        vector<vector<int>> adj;
        vector<int> dfsResult;
        int dfsWeight;

    public:
        Graph(int len) {
            v = len;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
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

        void DFS(int TitikAwal, int Tujuan){
            cout << endl;
            cout << "DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(TitikAwal, Tujuan, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Bobot = " << dfsWeight << endl;
        }

        void solveDFS(int TitikAwal, int Tujuan, vector<int> path, vector<bool> visited, int currWeight){
            if(TitikAwal == Tujuan) {
                path.push_back(Tujuan);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[TitikAwal] = true;
            path.push_back(TitikAwal);
            bool flag = false;
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[TitikAwal][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[TitikAwal][it];
                    flag = true;
                    solveDFS(it, Tujuan, path, visited, wtemp);
                }
            }
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
    Matrix.DFS(TitikAwal, Tujuan);
 
    return 0;
}