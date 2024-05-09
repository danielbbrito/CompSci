from graph import Graph
import xml.etree.ElementTree as ET
import math

# This needs work, the pheromone matrix is required, I don't think it'll be ready on time
def get_probability(G: Graph, origin, city, weight, pheromones):
    alpha = 1
    beta = 1

    weight_heuristic = 1 / weight
    Pk = math.pow(weight_heuristic, beta) * math.pow(pheromones, alpha)

    denominator = 0
    for ct, w, p, in G[origin]:
        if ct != city:
            denominator += math.pow(1 / w, beta) * math.pow(p, alpha)

    Pk = Pk / denominator

    return Pk


def build_ant_solutions(G: Graph):
    # Each ant k Computes a set Ak consisting of feasible expansions, meaning path and total cost of the given path
    solutions = []

    for ant in range(len(G)):
        solution = []
        visited = [False * len(G)]
        visited[ant] = True
        current_city = ant
        solution.append(current_city)

        cost = 0
        completed_tour = False
        while not completed_tour: # For potentially each city
            completed_tour = True
            next_city = (None, None, None, -1) # City, weight, pheromones, probabiltiy

            for city, weight, pheromones in G[current_city]:
                # Time to choose next city
                if not visited[city]:
                    completed_tour = False
                    probability = get_probability(G, current_city, city, weight, pheromones)

                    if next_city[3] < probability:
                        next_city = (city, weight, pheromones, probability)

            if not completed_tour:
                solution.append(next_city[0])
                cost += next_city[1]
                current_city = next_city[0]
            else:
                for ct, w, p in G[current_city]:
                    if ct == ant:
                        solution.append(ct)
                        cost += w
                        break
        
        solutions.append((ant, solution, cost))

    return solutions

def update_pheromones():
    pass
def ACO_TSP(G: Graph):
    while True:
        solutions = build_ant_solutions(G)
        update_pheromones(solutions)

    
    return
def main():
    instance = ET.parse("a280.xml")
    root = instance.getroot()
    xml_graph = root.find("graph")
    
    graph = Graph(ACO=True)
    i = 0
    for vertex in xml_graph.findall("vertex"):
        for edge in vertex.findall("edge"):
            graph.add_edge(i, edge.text, edge.attrib["cost"])
        
        i += 1
    
    ACO_TSP(graph)
    


if __name__ == "__main__":
    main()