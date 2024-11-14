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


def kruskal(graph):
    mst = []
    edges = graph[1]

    edges.sort()

    uf = UnionFind(graph[0])

    # Kruskal's Algorithm
    for edge in edges:
        weight, node1, node2 = edge

        # Check if the selected edge forms a cycle
        if uf.find(node1) != uf.find(node2):
            uf.union(node1, node2)
            mst.append(edge)

    return mst

def main():
    V = ["L", "CM", "NY", "Pa", "Pe", "T"]
    E = [
    (5558, "L", "CM"), (5558, "CM", "L"),  
    (3469, "L", "NY"), (3469, "NY", "L"),  
    (214, "L", "Pa"), (214, "Pa", "L"),    
    (5074, "L", "Pe"), (5074, "Pe", "L"),  
    (5959, "L", "T"), (5959, "T", "L"),    
    (2090, "CM", "NY"), (2090, "NY", "CM"),
    (5725, "CM", "Pa"), (5725, "Pa", "CM"),
    (7753, "CM", "Pe"), (7753, "Pe", "CM"),
    (7035, "CM", "T"), (7035, "T", "CM"),  
    (3636, "NY", "Pa"), (3636, "Pa", "NY"),
    (6844, "NY", "Pe"), (6844, "Pe", "NY"),
    (6757, "NY", "T"), (6757, "T", "NY"),  
    (5120, "Pa", "Pe"), (5120, "Pe", "Pa"),
    (6053, "Pa", "T"), (6053, "T", "Pa"),  
    (1307, "Pe", "T"), (1307, "T", "Pe")
]
    graph = [V, E]
    mst = kruskal(graph)
    print(mst)

if __name__ == "__main__":
    main()