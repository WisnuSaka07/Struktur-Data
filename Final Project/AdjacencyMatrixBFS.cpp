#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
  private:
  bool** adjMatrix;
  int a;
  
  public:
  Graph(int a) {
    this->a = a;
    adjMatrix = new bool*[a];
    for (int i = 0; i < a; i++) {
      adjMatrix[i] = new bool[a];
      for (int j = 0; j < a; j++)
        adjMatrix[i][j] = false;
    }
  }

  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
  }

  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  void toString() {
    for (int i = 0; i < a; i++) {
      cout << i << " : ";
      for (int j = 0; j < a; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  void bfs(int s, int r) {
        vector<bool> visited(a, false);
        vector<int> q;
        q.push_back(s);
        
        visited[s] = true;
        
        while (!q.empty()) {
            s = q[0];
            cout << s << endl;
            if(s == r) return;
            q.erase(q.begin());
            for (int i = 0; i < a; i++) {
                if (adjMatrix[s][i] == 1 && (!visited[i])) {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
  }

  ~Graph() {
    for (int i = 0; i < a; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() 
{
  Graph g(21);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 20);
    g.addEdge(2, 4);
    g.addEdge(3, 16);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 16);
    g.addEdge(5, 7);
    g.addEdge(6, 10);
    g.addEdge(6, 14);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 11);
    g.addEdge(10, 12);
    g.addEdge(11, 12);
    g.addEdge(12, 13);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.addEdge(15, 17);
    g.addEdge(16, 18);
    g.addEdge(17, 18);
    g.addEdge(18, 19);
    g.addEdge(19, 20);
 
    g.bfs(0, 12);
  
}
