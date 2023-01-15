import matplotlib.pyplot as plt
import networkx as nx
G = nx.Graph(nx.nx_pydot.read_dot("./complete.dot"))
pos = nx.circular_layout(G)
nx.draw(G, pos = pos, with_labels = False, node_size = 2)
plt.show()

