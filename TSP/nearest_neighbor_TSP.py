from graph import Graph


def nearest_neighbor_TSP( G: Graph, start: int):
    completed_tour = False
    current = start
    visited = {start: True}
    distance = 0
    # Repete enquanto não for encontrado um tour
    while not completed_tour:
        adjacents = G.get_adjlist()
        adjacents = adjacents[current]
        adjacents = sorted(adjacents, key=lambda adjacents: adjacents[1])

        # Get nearest neighbor
        for nearest_neighbor in adjacents:
            if nearest_neighbor[0] not in visited.keys():
                visited[nearest_neighbor[0]] = True
                distance += nearest_neighbor[1]
                current = nearest_neighbor[0]
                break

        if len(G.adjlist) == len(visited):
            completed_tour = True
    
    for i in adjacents:
        if i[0] == start:
            distance += i[1]
            break
    
    return distance



def main():
    graph = Graph()

    #number_vertex = int(input("n: "))

    graph_info = {
    1: [(2, 10), (3, 15), (4, 20), (5, 25)],
    2: [(1, 10), (3, 35), (4, 25), (5, 30)],
    3: [(1, 15), (2, 35), (4, 30), (5, 20)],
    4: [(1, 20), (2, 25), (3, 30), (5, 15)],
    5: [(1, 25), (2, 30), (3, 20), (4, 15)]
    }

    for key in graph_info:
        vals = graph_info.get(key)

        for val in vals:
            graph.add_edge(key, val[0], val[1])

    
    print(nearest_neighbor_TSP(graph, 1))



if __name__ == "__main__":
    main()