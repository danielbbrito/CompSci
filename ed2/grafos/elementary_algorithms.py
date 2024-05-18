import math
import heapq
from queue import Queue, PriorityQueue
from collections import deque
from graph import Graph, Node, NodeColors

def main():
    weighted = int(input("Grafo valorado (1-sim 2-nao)? "))
    directed = int(input("Grafo direcionado (1-sim 2-nao)? "))
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
                weight = float(input("Weight: "))
                graph.add_edge(node1, node2, weight)
            else:
                graph.add_edge(node1, node2)
        except EOFError:
            break

    print("Selecione o algoritmo para rodar:")
    print("1-BFS\n2-DFS\n3-TOPOSORT\n4-SCC\n5-Dijkstra")
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
            print(f"Caminho de {s} ate {v}: ", end="")
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
        print(f" {topology[i]}", end="")
    print()

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
            print(f"SCC #{i}:", end="")
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

    

    



if __name__ == "__main__":
    main()