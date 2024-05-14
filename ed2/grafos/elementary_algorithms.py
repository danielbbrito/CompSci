import math
import heapq
from queue import Queue, PriorityQueue
from collections import deque
from graph import Graph, Node, NodeColors

def main():
    weighted = int(input("Grafo valorado (1-sim 2-nao)? "))
    graph = Graph(directed=True, weighted=True if weighted == 1 else False)

    while True:
        try:
            node1 = int(input("Node 1: "))
            node2 = int(input("Node 2: "))
            print()
            node1 = Node(node1)
            node2 = Node(node2)

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
        # TODO
        pass
    
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
        v.set_parent = None

    s.color(NodeColors.GRAY)
    s.discovered(0)
    s.set_parent(None)

    queue = deque()
    queue.appendleft(s)

    while len(queue) > 0:
        current = queue[0]
        queue.pop()

        for v in adjlist[current]:
            if v.get_discovered() > current.get_discovered() + 1:
                v.discovered(current.get_discovered() + 1)
                v.set_parent(current)
                v.set_color(NodeColors.GRAY)
                queue.appendleft(v)

        
        current.set_color(NodeColors.BLACK)



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
            dfs_run(G, v)
    
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
        print(f" -> {topology[i]}", end="")
    print()

    

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