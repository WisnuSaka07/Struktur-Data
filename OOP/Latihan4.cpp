#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void addEdge(int a, int b){
            if(adj.empty()) adj.push_back(a);
            adj.push_back(b);
        }

        void showList(){
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
};

class Graph {
    protected:
        int len;
        Vertex vertex[100];
        

    public:
        Graph(int _len) {
            len = _len;
        }

        AddEdgetoVertex(int a, int b){
            vertex[a].addEdge(a,b);
            vertex[b].addEdge(b,a);
        }

        showAllVertex(){
            for (int i = 0; i < len; i++)
            {
                vertex[i].showList();
            }
            
        }
};


int main(){
    Graph graph1(5);

    graph1.AddEdgetoVertex( 0, 1);
    graph1.AddEdgetoVertex( 0, 4);
    graph1.AddEdgetoVertex( 1, 2);
    graph1.AddEdgetoVertex( 1, 3);
    graph1.AddEdgetoVertex( 1, 4);
    graph1.AddEdgetoVertex( 2, 3);
    graph1.AddEdgetoVertex( 3, 4);

    graph1.showAllVertex();
}
