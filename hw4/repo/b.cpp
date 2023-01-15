#include <boost/graph/adjacency_list.hpp>
#include <boost/property_map/property_map_iterator.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/d_ary_heap.hpp>
#include <bits/stdc++.h>
//#include <queue>
using namespace std;
using namespace boost;

//using G = boost::adjacency_list<>;
using G = adjacency_list< vecS, vecS, undirectedS,
            property< vertex_color_t, default_color_type >,
            property< edge_weight_t, int >
                >;
using V = G::vertex_descriptor;
using E = G::edge_descriptor;

namespace PoC {
    template <typename Graph> struct Wrapped : Graph {
        using Graph::Graph;
        Graph&       get()       { return *this; } 
        Graph const& get() const { return *this; } 
    };

    template <class Graph, class SourceInputIter, class DijkstraVisitor, class PredecessorMap,
              class DistanceMap, class WeightMap, class IndexMap, class Compare, class Combine,
              class DistZero, class ColorMap>
    inline void dijkstra_shortest_paths_no_init(Wrapped<Graph> const& g, SourceInputIter s_begin,
                                                SourceInputIter s_end, PredecessorMap predecessor,
                                                DistanceMap distance, WeightMap weight, IndexMap index_map,
                                                Compare compare, Combine combine, DistZero zero,
                                                DijkstraVisitor vis, ColorMap color) {
        using namespace boost;
        indirect_cmp<DistanceMap, Compare> icmp(distance, compare);

        using Vertex = typename graph_traits<Graph>::vertex_descriptor;

        // Now the default: use a d-ary heap
        boost::scoped_array<std::size_t> index_in_heap_map_holder;
        using IndexInHeapMapHelper   = detail::vertex_property_map_generator<Graph, IndexMap, std::size_t>;
        using IndexInHeapMap         = typename IndexInHeapMapHelper::type;
        using MutableQueue           = d_ary_heap_indirect<Vertex, 4, IndexInHeapMap, DistanceMap, Compare>;
        IndexInHeapMap index_in_heap = IndexInHeapMapHelper::build(g, index_map, index_in_heap_map_holder);
        MutableQueue   Q(distance, index_in_heap, compare);

        //std::cerr << "SEHE WAS HERE - pretend we use different MutableQueue" << std::endl;

        detail::dijkstra_bfs_visitor<DijkstraVisitor, MutableQueue, WeightMap, PredecessorMap, DistanceMap,
                                     Combine, Compare>
            bfs_vis(vis, Q, weight, predecessor, distance, combine, compare, zero);

        breadth_first_visit(g, s_begin, s_end, Q, bfs_vis, color);
    }
}

template <typename G>
    struct boost::graph_traits<PoC::Wrapped<G>> : graph_traits<G> {};
template <typename G, typename P>
    struct boost::graph_property<PoC::Wrapped<G>, P> : graph_property<G, P> {};

int main() {
    typedef pair<int,int> Edge;
    unsigned int seed = 1 + 100*1;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(0,999);

    int max = 10000;
    Edge used_by[max];
    const int nedges = max;
    int weights[nedges];
    int i = 0;
    for (; i < 1000; ++i) {
        used_by[i] = Edge(i % 1000, (i + 1) % 1000);
        weights[i] = 1;
    }
    for( ; i < max; ++i){
        used_by[i] = Edge(r_val(gen) % 1000, r_val(gen) % 1000);
        weights[i] = 10;
    }
    //cout << sizeof(used_by) / sizeof(Edge);
    //int weights[nedges];
    //std::fill(weights, weights + nedges, 1);

    PoC::Wrapped<G> g(used_by, used_by + nedges, weights, 999); 

    //print_graph(g);
    clock_t start, stop;
    start = clock();

    for(int j = 0; j < 1000; ++j){
    std::vector<V>         pred(num_vertices(g));
    std::vector<int>         dist(num_vertices(g));
    //boost::heap::binomial_heap <V> q;
    //boost::heap::d_ary_heap<V> q;
    boost::heap::fibonacci_heap<V> q;
    boost::typed_identity_property_map<G::vertex_descriptor> vid;
    dijkstra_shortest_paths( //
        g, vertex(j,g),
        boost::predecessor_map(make_iterator_property_map(pred.data(), vid))                           //
            .distance_map(make_iterator_property_map(dist.data(), vid)) //
            .max_priority_queue(q)                                    //
    );
    //cout << pred.size();
    //for(auto it: dist)
        //cout << it << ' ';
    //cout << endl;
    //cout << j << ' ' << dist[800] << endl;
    }
    stop = clock();
    cout <<  setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
 //graph_traits < G >::vertex_iterator vi, vend;
 //for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
  //std::cout << pred[*vi] << ", ";
 //}
    //std::deque<V> path;
    //auto src = 1;
    //for (V cur = num_vertices(g) - 1;; cur = pred[cur]) {
        //path.push_front(cur);
        //if (cur == src || cur == pred[cur])
            //break;
    //}
}
