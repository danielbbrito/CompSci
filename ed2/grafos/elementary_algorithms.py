import math
from collections import deque
from graph import Graph, Node, NodeColors

def main():
    graph = Graph()

    while True: # Change to only take Node objects
        try:
            node1 = input("Node 1: ")
            node2 = input("Node 2")
            weight = float(input("Weight: "))
            graph.add_edge(node1, node2, weight)
        except EOFError:
            break

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
    """
    If no end node is provided,
    generates a DFS spanning tree
    """

    # First, clear all nodes (O(V))
    adjlist = G.get_adjlist()

    for v in adjlist.keys():
        v.set_color(NodeColors.WHITE)

    global time
    time = 0
    for v in adjlist.keys():
        if v.color() == NodeColors.WHITE: # Run dfs to create a depth-first forest
            dfs_run(G, v)


def dfs_run(G: Graph, u: Node):
    # Update time and set discovery time
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





if __name__ == "__main__":
    main()