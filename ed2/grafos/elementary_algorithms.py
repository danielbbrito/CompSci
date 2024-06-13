import math
from queue import Queue, PriorityQueue
import heapq

class UnionFind:
    def __init__(self, vertices):
        self.parent = {v: v for v in vertices}
        self.rank = {v: 0 for v in vertices}

    def find(self, item):
        if self.parent[item] == item:
            return item
        else:
            self.parent[item] = self.find(self.parent[item])
            return self.parent[item]

    def union(self, set1, set2):
        root1 = self.find(set1)
        root2 = self.find(set2)

        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

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

def main():
    weighted = int(input(f"{bcolors.HEADER}Grafo valorado (1-sim 2-nao)? "))
    directed = int(input("Grafo direcionado (1-sim 2-nao)? "))
    print(bcolors.ENDC)

    graph = Graph(directed=True if directed == 1 else False, 
                  weighted=True if weighted == 1 else False)

    while True:
        try:
            node1 = int(input("Node 1: "))
            node2 = int(input("Node 2: "))
            node1 = Node(node1)
            node2 = Node(node2)

            if str(node1) in graph.vertices().keys():
                node1 = graph.vertices()[str(node1)]
            else:
                graph.vertices()[str(node1)] = node1

            if str(node2) in graph.vertices().keys():
                node2 = graph.vertices()[str(node2)]
            else:
                graph.vertices()[str(node2)] = node2

            print()

            if weighted == 1:
                weight = float(input(f"{bcolors.OKBLUE}Weight: "))
                graph.add_edge(node1, node2, weight)
            else:
                graph.add_edge(node1, node2)
        except EOFError:
            break
    
    print()
    print(f"{bcolors.BOLD}Selecione o algoritmo para rodar:{bcolors.ENDC}")
    print(f"{bcolors.OKGREEN}1-BFS\n2-DFS\n3-TOPOSORT\n4-SCC\n5-Dijkstra{bcolors.ENDC}")
    algo = int(input("Escolha:"))
    if algo == 1:
        initial = int(input("Vertice de inicio: "))
        s = None
        for v in graph.get_adjlist():
            if v.name() == initial:
                s = v
                break
        
        BFS(graph, s)

    if algo == 2:
        DFS(graph)

    if algo == 3:
        topological_sort(graph)

    if algo == 4:
        strongly_connected_components(graph)
    
    if algo == 5:
        initial = int(input("Vertice de inicio: "))
        s = None
        for v in graph.get_adjlist():
            if v.name() == initial:
                s = v
                break
        
        dijkstra(graph, s)

    print(bcolors.ENDC)

def initialize_single_source(G: Graph, s: Node):
    for v in G.get_adjlist():
        v.set_color(NodeColors.WHITE)
        v.set_parent(None)
        v.set_distance(math.inf)

    s.set_color(NodeColors.GRAY)
    s.set_parent(s)
    s.set_distance(0)  


def BFS(G: Graph, s: Node):
    adjlist = G.get_adjlist()
    for v in adjlist.keys():
        v.set_color(NodeColors.WHITE)
        v.discovered(math.inf)
        v.set_parent(None)

    s.set_color(NodeColors.GRAY)
    s.discovered(0)
    s.set_parent(None)

    queue = Queue()
    queue.put(s)

    while not queue.empty():
        current = queue.get()

        for v in adjlist[current]:
            if v.color() == NodeColors.WHITE:
                v.discovered(current.get_discovered() + 1)
                v.set_parent(current)
                v.set_color(NodeColors.GRAY)
                queue.put(v)

        
        current.set_color(NodeColors.BLACK)

    for v in adjlist:
        if v != s:
            print(f"{bcolors.HEADER}Caminho de {s} ate {v}: {bcolors.ENDC}", end="")
            print_path(G, s, v)
            print()

def print_path(G: Graph, s: Node, v: Node):
    if v == s:
        print(f"{s} ", end="")
    elif v.get_parent() is None:
        print("Nao existe caminho")
    else:
        print_path(G, s, v.get_parent())
        print(f"{v} ", end="")

def DFS(G: Graph):
    # First, clear all nodes (O(V))
    adjlist = G.get_adjlist()

    for v in adjlist.keys():
        v.set_color(NodeColors.WHITE)

    global time
    time = 0
    for v in adjlist.keys():
        if v.color() == NodeColors.WHITE: # Run dfs to create a depth-first forest
            dfs_run(G, v)

    print(f"Tempo total: {time}")

    for v in adjlist.keys():
        print(f"{bcolors.HEADER}Vertice: {v}", end="")
        print(f"{bcolors.OKGREEN} Tempo descoberta: {v.get_discovered()}", end="")
        print(f"{bcolors.FAIL} Tempo de finalizacao: {v.get_finished()}")
    
    print(bcolors.ENDC)



def dfs_run(G: Graph, u: Node, topo=False):
    # Update time and set discovery time
    global time
    time += 1
    
    u.discovered(time)

    # Set discovered node to gray
    u.set_color(NodeColors.GRAY)


    for v in G.get_adjlist()[u]:
        if v.color() == NodeColors.WHITE:
            # Set parent of the next node to visit
            v.set_parent(u)

            # Go deeper into the graph
            dfs_run(G, v, True if topo else False)
    
    # Update time and set finished time

    time += 1
    u.finished(time)

    # Set finished node to Black
    u.set_color(NodeColors.BLACK)

    if topo == True:
        topology.insert(0, u)



def topological_sort(G: Graph):
    adjlist = G.get_adjlist()

    for v in adjlist.keys():
        v.set_color(NodeColors.WHITE)

    global topology
    topology = []

    global time
    time = 0
    for v in adjlist.keys():
        if v.color() == NodeColors.WHITE: # Run dfs to create a depth-first forest
            dfs_run(G, v, True)
    
    print(topology[0], end="")
    
    for i in range(1, len(topology)):
        print(f"{bcolors.BOLD} {topology[i]}", end="")
    print(bcolors.ENDC)

def strongly_connected_components(G: Graph):
    adjlist = G.get_adjlist()

    global finish_times
    finish_times = []
    for v in adjlist:
        if v.color() == NodeColors.WHITE:
            scc_dfs(G, v, 1)

    # Compute transpose
    GT = Graph(directed=True, weighted=False)
    for v in adjlist:
        for u in adjlist[v]:
            GT.add_edge(u, v)

    for v in GT.get_adjlist():
        v.set_color(NodeColors.WHITE)
    
    global SCC
    SCC = []
    i = 0
    for v in finish_times:
        if v.color() == NodeColors.WHITE:
            i += 1
            scc_dfs(GT, v, 2)
            print(f"{bcolors.OKGREEN}SCC #{i}:{bcolors.ENDC}", end="")
            for node in SCC:
                print(f" {node}", end="")
            print()

            SCC.clear()

def scc_dfs(G: Graph, u: Node, p: int):

    u.set_color(NodeColors.GRAY)

    for v in G.get_adjlist()[u]:
        if v.color() == NodeColors.WHITE:
            # Set parent of the next node to visit
            v.set_parent(u)

            # Go deeper into the graph
            scc_dfs(G, v, p)
    
    u.set_color(NodeColors.BLACK)

    if p == 1:
        finish_times.insert(0, u)
    
    if p == 2:
        SCC.insert(0, u)


def dijkstra(G: Graph, s: Node):
    """
    Implementacao do algoritmo de dijkstra
    """
    initialize_single_source(G, s)
    adjlist = G.get_adjlist()
    # Set dos vertices ja finalizados
    visited = {}

    for v in adjlist.keys():
        visited[v] = False

    pq = PriorityQueue()
    pq.put((s.distance(), s))

    while not pq.empty():
        u_dist, u = pq.get()

        if visited[u]:
            continue

        visited[u] = True

        for v, w in adjlist[u]:
            if v.distance() > u_dist + w:
                v.set_distance(u_dist + w)
                v.set_parent(u)
                pq.put((v.distance(), v))

def bellman_ford(G: Graph, s: Node):
    initialize_single_source(G, s)
    adjlist = G.get_adjlist()

    for i in range(len(adjlist) - 1):
        modified = False
        for v in adjlist.keys():
            if v.distance() != math.inf:
                for u, w in adjlist[v]:
                    if u.distance() > v.distance() +  w:
                        u.set_distance(v.distance() + w)
                        modified = True
        
        if not modified:
            break

    for v in adjlist.keys():
        for u, w in adjlist[v]:
            if u.distance() > v.distance() + w:
                return False
    
    return True

def kruskal(graph):
    mst = []
    edges = []

    # Extract all edges from the graph
    for node in graph.get_adjlist():
        for neighbor in graph.get_adjlist()[node]:
            if graph._weighted:
                edges.append((neighbor[1], node, neighbor[0]))  # (weight, node1, node2)
            else:
                edges.append((1, node, neighbor))  # Assuming weight is 1 if not weighted

    # Sort edges by weight
    edges.sort()

    # Create a union-find structure to keep track of components
    uf = UnionFind(graph.vertices())

    # Kruskal's Algorithm
    for edge in edges:
        weight, node1, node2 = edge

        # Check if the selected edge forms a cycle
        if uf.find(node1) != uf.find(node2):
            uf.union(node1, node2)
            mst.append(edge)

    return mst

def prim(graph, start_node):
    mst = []
    visited = set()
    min_heap = []

    # Add all edges of the start node to the min heap
    def add_edges(node):
        visited.add(node)
        for neighbor in graph.get_adjlist()[node]:
            if graph._weighted:
                weight = neighbor[1]
                neighbor_node = neighbor[0]
            else:
                weight = 1
                neighbor_node = neighbor
            if neighbor_node not in visited:
                heapq.heappush(min_heap, (weight, node, neighbor_node))

    # Initialize with the start node's edges
    add_edges(start_node)

    # Prim's Algorithm
    while min_heap:
        weight, node1, node2 = heapq.heappop(min_heap)
        if node2 not in visited:
            visited.add(node2)
            mst.append((weight, node1, node2))
            add_edges(node2)

    return mst

def bfs(graph, source, sink, parent):
    visited = set()
    queue = [source]
    visited.add(source)

    while queue:
        u = queue.pop(0)
        for v, capacity in graph[u]:
            if v not in visited and capacity > 0:
                queue.append(v)
                visited.add(v)
                parent[v] = u
                if v == sink:
                    return True
    return False


def ford_fulkerson(graph, source, sink):
    parent = {}
    max_flow = 0
    adjlist = graph.get_adjlist()

    # Create a residual graph and fill the residual graph with given capacities
    residual_graph = {u: {} for u in adjlist}
    for u in adjlist:
        for v, capacity in adjlist[u]:
            residual_graph[u][v] = capacity
            if v not in residual_graph:
                residual_graph[v] = {}
            if u not in residual_graph[v]:
                residual_graph[v][u] = 0
    
    # Augment the flow while there is a path from source to sink
    while bfs(residual_graph, source, sink, parent):
        path_flow = float('Inf')
        s = sink

        while s != source:
            path_flow = min(path_flow, residual_graph[parent[s]][s])
            s = parent[s]

        # update residual capacities of the edges and reverse edges along the path
        v = sink
        while v != source:
            u = parent[v]
            residual_graph[u][v] -= path_flow
            residual_graph[v][u] += path_flow
            v = parent[v]

        max_flow += path_flow

    return max_flow


if __name__ == "__main__":
    main()