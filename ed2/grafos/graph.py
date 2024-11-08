import math

class NodeColors:
    WHITE = 1
    GRAY = 2
    BLACK = 3

class Graph:
    def __init__(self, directed=False, weighted=False):
        self._directed = directed
        self._adjlist = {}
        self._adjmatrix = []
        self._vertexlist = {} # Guarda o label e o objeto associado
        self._weighted = weighted

    def add_vertex(self, node):
        self._vertexlist[str(node)] = node

    def vertices(self):
        return self._vertexlist
    
    def add_edge(self, node1, node2, weight=None):
        if self._weighted:
            if node1 in self._adjlist.keys():
                self._adjlist[node1].add((node2, weight))
            else:
                self._adjlist[node1] = set([(node2, weight)])
        else:
            if node1 in self._adjlist.keys():
                self._adjlist[node1].add(node2)
            else:
                self._adjlist[node1] = set([node2])

        
        if not self._directed:
            if self._weighted:
                if node2 in self._adjlist.keys():
                    self._adjlist[node2].add((node1, weight))
                else:
                    self._adjlist[node2] = set([(node1, weight)])
            
            else:
                if node2 in self._adjlist.keys():
                    self._adjlist[node2].add(node1)
                else:
                    self._adjlist[node2] = set([node1])
        else:
            if node2 not in self._adjlist.keys():
                self._adjlist[node2] = set()


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
        string = ""
        for v in self._adjlist:
            string += f"{v} ->"

            if self._weighted:
                for u, w in self._adjlist[v]:
                    string += f" ({u}, {w})"
            else:
                for u in self._adjlist[v]:
                    string += f" {u}"
            
            string += "\n"

        return string


class Node:
    def __init__(self, label):
        self.label = label
        self._color = NodeColors.WHITE
        self._parent = None
        self._discovered = None
        self._finished = None
        self._distance = math.inf

    def __str__(self):
        return str(self.label)
    
    def __eq__(self, other):
        return isinstance(other, Node) and self.label == other.label
    
    def __hash__(self):
        return hash(self.label)
    
    def name(self):
        return self.label
    
    def set_parent(self, p):
        self._parent = p

    def get_parent(self):
        return self._parent
    
    def discovered(self, t):
        self._discovered = t

    def get_discovered(self):
        return self._discovered
    
    def finished(self, t):
        self._finished = t

    def get_finished(self):
        return self._finished
    def set_color(self, c):
        self._color = c

    def color(self):
        return self._color
    
    def set_distance(self, d):
        self._distance = d
    
    def distance(self):
        return self._distance
        





        

    