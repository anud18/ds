import matplotlib.pyplot as plt
import networkx as nx
G = nx.Graph(nx.nx_pydot.read_dot("./complete.dot"))
# pos = nx.circular_layout(G)
# nx.draw(G, pos = pos, with_labels = False)
# plt.show()
UG = G.to_undirected()
print(nx.number_connected_components(UG), "connected components")

options = {
    "node_color": "black",
    "node_size": 1,
    "edge_color": "gray",
    "linewidths": 0,
    "width": 0.1,
}
nx.draw_circular(UG, **options)
plt.show()

