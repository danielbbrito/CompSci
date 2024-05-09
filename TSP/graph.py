class Graph:
    def __init__(self, directed=False, ACO=False):
        self.adjlist = {}
        self.directed = directed
        self.ACO = ACO

    def add_edge(self, node1, node2, weight, pheromones=1):
        if node1 in self.adjlist.keys():
            if not self.ACO:
                self.adjlist[node1].append((node2, weight))
            else:
                self.adjlist[node1].append((node2, weight, pheromones))

        else:
            if not self.ACO:
                self.adjlist[node1] = [(node2, weight)]
            else:
                self.adjlist[node1] = [(node2, weight, pheromones)]

        if not self.directed:
            if node2 in self.adjlist.keys():
                if not self.ACO:
                    self.adjlist[node2].append((node1, weight))
                else:
                    self.adjlist[node2].append((node1, weight, pheromones))

            else:
                if not self.ACO:
                    self.adjlist[node2] = [(node1, weight)]
                else:
                    self.adjlist[node2] = [(node1, weight, pheromones)]

    def get_adjacents(self, node):
        return self.adjlist.get(node, None)
    
    #def update_node_count(self):
     #   self.node_count += 1

    def print_adjlist(self):
        print(self.adjlist)
        return
    
    def get_adjlist(self):
        return self.adjlist
