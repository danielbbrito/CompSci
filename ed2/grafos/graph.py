class NodeColors:
    WHITE = 1
    GRAY = 2
    BLACK = 3

class Graph:
    def __init__(self, directed=False):
        self._directed = directed
        self._adjlist = {}
        self._adjmatrix = []

    def add_edge(self, node1, node2, weight=1):
        """
        O(1) edge insertion
        """
        if node1 in self._adjlist.keys():
            self._adjlist[node1].add((node2, weight))
        else:
            self._adjlist[node1] = set((node2, weight))

        
        if not self._directed:
            if node2 in self._adjlist.keys():
                self._adjlist[node2].add((node1, weight))
            else:
                self._adjlist[node2] = set((node1, weight))

    def build_adjacency_matrix(self):
        """
        Only use this when the adjacency list is complete,
        otherwise it might generate an incorrect result.
        Should run in O(|v^2|).
        """
        # Creates a matrix
        self._adjmatrix = [len(self._adjlist) * [None for i in range(len(self._adjlist))]]

        for i in self._adjlist.keys():
            for j in self._adjlist[i]:
                self._adjmatrix[i][j] = 1
    
    def get_adjlist(self):
        return self._adjlist

    
    def __str__(self):
        """
            Creates a string representation of the adjacency list
        """

        return str(self._adjlist)


class Node:
    def __init__(self, label):
        self.label = label
        self._color = NodeColors.WHITE
        self.parent = None
        self._discovered = None
        self._finished = None

    def set_parent(self, p):
        self.parent = p

    def discovered(self, t):
        self._discovered = t

    def get_discovered(self):
        return self._discovered
    
    def finished(self, t):
        self._finished = t

    def set_color(self, c):
        self._color = c

    def color(self):
        return self._color
        





        

    