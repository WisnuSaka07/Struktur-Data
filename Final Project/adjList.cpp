#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Graph {
private:
    int s;
    vector<list<int>> adj;  
public:
    Graph(int s) {
        this->s = s;
        adj.resize(s);
    }
   
    void addEdge(int s, int r){
        adj[s].push_back(r);
    }
 
    void toPrint() {
    for (int i = 0; i < s; i++) {
      cout << i << " --> ";
      for (auto adjecent: adj[i]) {
          cout << adjecent << " ";
      }
      cout << "/\n";
    }
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
 
    g.toPrint();
 
    return 0;
}
