#include <iostream>
#include <list>

using namespace std;

// graph class using adjacency list
class Graph
{
    int V;
    list<int> *adj;
public:
    // constructor
    Graph(int V);

    // function to add an edge to graph
    void add_edge(int v, int w);

    // prints BFS traversal from a given source s
    void breadth_first_search(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::breadth_first_search(int s)
{
    // mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    // create a queue for breadth first search
    list<int> queue;

    // mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // get all adjacent vertices of the dequeued
        // vertex s. if a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    g.breadth_first_search(2);

    return 0;
}

