// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
#include <boost/heap/fibonacci_heap.hpp>
//#include <boost/heap/fibonacci_heap.hpp>

using namespace boost::heap;
using namespace std;

typedef pair<int, int> PII;
typedef boost::heap::fibonacci_heap<
PII,
    boost::heap::compare<std::greater<PII> > > MyHeap;
using Heap = boost::heap::fibonacci_heap<
PII,
    boost::heap::compare<std::greater<PII> > >;

const int nVecS = 1000;
const int z = 300;
#define INF 0x3f3f3f3f
int sum = 0;
unsigned int seed = 1 + 100*1;
mt19937 gen(seed);
uniform_int_distribution<> r_val(0,999);



// To add an edge
void addEdge(vector<PII> adj[], int u, int v,
        int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Prints shortest paths from src to all other vertices
void shortestPath(vector<PII> adj[nVecS], int V,
        int src, int target = -1)
{
    MyHeap	pq;

    vector<int> dist(V, INF);


    MyHeap::handle_type h[V];
    h[src] = pq.push(make_pair(0, src));
    dist[src] = 0;
    vector<bool> vis(V, false);
    //vector<int> vis(n, false);

    /* Looping till priority queue becomes empty (or all
       distances are not finalized) */
    while (!pq.empty()) {
        int u = pq.top().second;
        if(target != -1 && u == target){
            //cout << u << ' ' << dist[u] << endl;
            sum += dist[target];
            return;


        }

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
                if(dist[v] == INF)
                {
                    h[v] = pq.push(make_pair(dist[u] + weight, v));
                    //cout << "bb" << endl;
                
                }else
                {
                    //cout << "test"  << endl;
                    pq.increase(h[v], make_pair(dist[u] + weight, v));
                }
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Print shortest distances stored in dist[]
    //printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
    cout << i << ' ' << dist[i] << endl;
    if(target >= 0)
        sum += dist[target];
}
template<typename T , std::size_t N>
void add_x_edges(T (&adj)[N], int x, int wt){

    for (int times = 0; times < x; ++times) {
        int u = r_val(gen);
        int v = r_val(gen);
        bool tag = true;
        while(tag){
            tag = false;
            for(auto it : adj[u]){
                if ( u == v || it.first == v) {
                    u = r_val(gen);
                    v = r_val(gen);
                    tag = true;
                }
            }
        }
        addEdge(adj, u, v, wt);
    }

}

bool sampleFind(vector<PII> &sset, int a, int b){
    if(a == b)
        return true;
    PII tmp(a, b);
    PII _tmp(b, a);
    for(auto it : sset){
        if(it == tmp || it == _tmp)
            return true;
    }
    return false;

}

// Driver program to test methods of graph class
int main()
{

    vector<PII> adj[nVecS];

    // making above shown graph
    int i = 0;
    for(; i < nVecS; ++i){
        addEdge(adj, i % 1000 , (i + 1) % 1000, 1);
    }
    //
    int x = 0;
    int y = 100;
    for(; x < 10; ++x){
        sum = 0;
        if(x > 0)
            add_x_edges(adj, 1, y);

        vector<PII> sampleSet;
        for(int j = 0 ; j < z; ++j){
            int begin = r_val(gen);
            int end = r_val(gen);
            while (sampleFind(sampleSet, begin, end)){
                begin = r_val(gen);
                end = r_val(gen);
            }
            shortestPath(adj, nVecS, begin, end);
            sampleSet.push_back(make_pair(begin, end));
        }
        vector<PII>().swap(sampleSet);
        float out = (float) sum / z;
        cout <<  x << ' ' << out << endl;
    }
    return 0;
}
