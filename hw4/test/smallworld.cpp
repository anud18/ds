#include<bits/stdc++.h>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>
using namespace std;

enum files_e { dax_h, yow_h, boz_h, zow_h, foo_cpp,
    foo_o, bar_cpp, bar_o, libfoobar_a,
    zig_cpp, zig_o, zag_cpp, zag_o,
    libzigzag_a, killerapp, N };
const char* name[] = { "dax.h", "yow.h", "boz.h", "zow.h", "foo.cpp",
    "foo.o", "bar.cpp", "bar.o", "libfoobar.a",
    "zig.cpp", "zig.o", "zag.cpp", "zag.o",
    "libzigzag.a", "killerapp" };

int main(int,char*[])
{

    typedef pair<int,int> Edge;
    //Edge used_by[] = {
    //Edge(dax_h, foo_cpp), Edge(dax_h, bar_cpp), Edge(dax_h, yow_h),
    //Edge(yow_h, bar_cpp), Edge(yow_h, zag_cpp),
    //Edge(boz_h, bar_cpp), Edge(boz_h, zig_cpp), Edge(boz_h, zag_cpp),
    //Edge(zow_h, foo_cpp),
    //Edge(foo_cpp, foo_o),
    //Edge(foo_o, libfoobar_a),
    //Edge(bar_cpp, bar_o),
    //Edge(bar_o, libfoobar_a),
    //Edge(libfoobar_a, libzigzag_a),
    //Edge(zig_cpp, zig_o),
    //Edge(zig_o, libzigzag_a),
    //Edge(zag_cpp, zag_o),
    //Edge(zag_o, libzigzag_a),
    //Edge(libzigzag_a, killerapp)
    //};

            //property< vertex_color_t, default_color_type >,
            //property< edge_weight_t, int >
                //> Graph;
    //Graph g(used_by, used_by + nedges, weights, 999);

    //write_graphviz(std::cout, g, make_label_writer(name));
    typedef boost::adjacency_list<> Graph;
typedef boost::small_world_iterator<boost::minstd_rand, Graph> SWGen;
  boost::minstd_rand gen;
  // Create graph with 100 nodes
  Graph g(SWGen(gen, 100, 1), SWGen(), 100);

    
    
    
    
    
    
    write_graphviz(std::cout, g );

}
