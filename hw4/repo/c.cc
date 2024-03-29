#include <boost/config.hpp>
#include <iostream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

// define visitor for discover_vertex event

template <class Vertex, class Tag>
struct target_visitor : public default_dijkstra_visitor
{
 target_visitor(Vertex u) : v(u) { }

 template <class Graph>
 void examine_vertex(Vertex u, Graph& g)
 {
  if( u == v ) {
   throw(-1);
  }
 }
private:
 Vertex v;
};

template <class Vertex, class Tag>
target_visitor<Vertex, Tag>
target_visit(Vertex u, Tag) {
 return target_visitor<Vertex, Tag>(u);
}


int main(int argc, char** argv)
{
 typedef adjacency_list < listS, vecS, directedS,
  no_property, property < edge_weight_t, int > > graph_t;
 typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
 typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;
 typedef std::pair<int, int> Edge;

 const int num_nodes = 5;
 enum nodes { A, B, C, D, E };
 char name[] = "ABCDE";
 Edge edge_array[] =
 {
  Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E),
     Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B)
 };
  int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 1 };
 int num_arcs = sizeof(edge_array) / sizeof(Edge);

 graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
 property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);

 std::vector<vertex_descriptor> p(num_vertices(g));
 std::vector<int> d(num_vertices(g));

 // choose source and target
 vertex_descriptor src = vertex(A, g);
 vertex_descriptor targ = vertex(C, g);


 try {
  dijkstra_shortest_paths(g, src,
      predecessor_map(&p[0]).distance_map(&d[0]).visitor(target_visit(targ,
      on_examine_vertex())));
 }
 catch( ... ) {
 }


 std::cout << "distances and parents:" << std::endl;
 graph_traits < graph_t >::vertex_iterator vi, vend;
 for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
  std::cout << "distance(" << name[*vi] << ") = " << d[*vi] << ", ";
  std::cout << "parent(" << name[*vi] << ") = " << name[p[*vi]] << std::endl;
 }

    system("PAUSE");
 return EXIT_SUCCESS;
}
