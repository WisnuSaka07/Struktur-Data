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
        vector<int> dfsResult;
        int dfsWeight;

    public:
        Graph(int len) {
            v = len;
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
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
            list<int>::iterator it;
            for ( it = adj[TitikAwal].begin(); it != adj[TitikAwal].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(TitikAwal, *it)];
                    solveDFS(*it, Tujuan, path, visited, wtemp);
                }
            }
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
    List.DFS(TitikAwal, Tujuan);
 
    return 0;
}