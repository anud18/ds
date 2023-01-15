// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
#include <boost/heap/fibonacci_heap.hpp>

using namespace boost::heap;
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;


typedef pair<int, int> PII;
typedef boost::heap::fibonacci_heap<
PII,
    boost::heap::compare<std::greater<PII> > > MyHeap;



// To add an edge
void addEdge(vector<pair<int, int> > adj[], int u, int v,
        int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Prints shortest paths from src to all other vertices
void shortestPath(vector<pair<int, int> > adj[], int V,
        int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    MyHeap	pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
       distances are not finalized) */
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // Get all adjacent of u.
        for (auto x : adj[u]) {
            // Get vertex label and weight of current
            // adjacent of u.
            int v = x.first;
            int weight = x.second;

            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    //for (int i = 0; i < V; ++i)
        //printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
    unsigned int seed = 1 + 100*1;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(0,999);

    int V = 1000;
    vector<iPair> adj[V];

    int i = 0;
    int max = 1500;
    for(; i < 1000; ++i){
        addEdge(adj, i % 1000 , (i + 1) % 1000, 1);
    }
    for(; i < max; ++i)
        addEdge(adj, r_val(gen) % 1000 , r_val(gen) % 1000, 1);

    for(int j = 0 ; j < 500; ++j)
        shortestPath(adj, V, j);

    return 0;
}
