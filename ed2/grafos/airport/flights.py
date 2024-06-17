import math
import datetime
from queue import PriorityQueue


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
        if node1.get_label() not in self._vertexlist.keys():
            self.add_vertex(node1)
        
        if node2.get_label() not in self._vertexlist.keys():
            self.add_vertex(node2)

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
        self._label = label
        self._parent = None
        self._distance = math.inf

    def __lt__(self, other):
        return isinstance(other, Node) and self._distance < other._distance
    
    def __gt__(self, other):
        return isinstance(other, Node) and self._distance > other._distance
    
    def __eq__(self, other):
        return isinstance(other, Node) and self._label == other._label
    
    def __hash__(self):
        return hash(self._label)
    
    def __str__(self):
        return self._label
    
    def get_label(self):
        return self._label
    
    def set_parent(self, p):
        self._parent = p
    
    def get_parent(self):
        return self._parent
    
    def set_distance(self, d):
        self._distance = d

    def get_distance(self):
        return self._distance
    
class Flight(Node):
    def __init__(self, label, takeoff_time=None, arrival_time=None):
        super().__init__(label)
        self._origin = None
        self._destination = None
        self._intermediates = []
        self._takeoff_time = takeoff_time
        self._arrival_time = arrival_time
    
    def set_takeoff_time(self, tm):
        self._takeoff_time = tm
    
    def get_takeoff_time(self):
        return self._takeoff_time

    def set_arrival_time(self, tm):
        self._arrival_time = tm

    def get_arrival_time(self):
        return self._arrival_time

    def set_origin(self, o):
        self._origin = o

    def get_origin(self):
        return self._origin
    
    def set_destination(self, d):
        self._destination = d

    def get_destination(self):
        return self._destination
    
    def add_intermediate(self, i):
        self._intermediates.append(i)

    def set_intermediates(self, i):
        self._intermediates = i

    def get_intermediates(self):
        return self._intermediates

class City(Node):
    def __init__(self, label):
        super().__init__(label)


def main():
    graph = Graph(True, True)

    # Read flight information file
    with open("cmp1099-trabalho-grafo_dijkstra-arquivo_voos.txt", "r+") as FILE:
        for line in FILE:
            line = line.split(" ")
            flight = Flight(line[0])
            
            origin = City(line[1])

            for v in graph.get_adjlist():
                if v == origin:
                    origin = v
                    break

            destination = City(line[len(line) - 2])
            takeoff = line[2]
            landing = line[len(line) - 1]
            flight.set_origin(origin)
            flight.set_destination(destination)
            flight.set_takeoff_time(takeoff)
            flight.set_arrival_time(landing)


            # Calculate flight weight and find intermediate airports
            times = [takeoff]
            intermediates = []
            for i in range(4, len(line)):
                if line[i][0].isdigit():
                    times.append(line[i].replace("\n", ""))
            
            for i in range(3, len(line) - 2):
                if line[i][0].isalpha():
                    intermediates.append((line[i], line[i+1], line[i+2]))
            
            flight.set_intermediates(intermediates)

            duration = 0
            for i in range(1, len(times)):
                duration += time_difference(times[i - 1], times[i])

            # Populate graph
            graph.add_edge(origin, flight, 0)
            graph.add_edge(flight, destination, duration)         

    # Read origin and destination cities
    while True:
        origin = input("Cidade de origem: ")

        if origin in graph.vertices().keys():
            origin = graph.vertices()[origin]
            break
        else:
            print()
            print("Não existem voos saindo da cidade informada")
            print()
            continue

    while True:
        destination = input("Cidade de destino: ")
        if destination in graph.vertices().keys():
            destination = graph.vertices()[destination]
            break
        else:
            print()
            print("Não existem voos chegando da cidade informada")
            print()
            continue

    
    if dijkstra(graph, origin, destination):
        print(f"Origem: {origin.get_label()}")
        print(f"Destino: {destination}")
        print(f"Distancia: {destination.get_distance()}")

        flight_list = []
        get_flight_path(graph, origin, destination, flight_list)
        
        for flight in flight_list:
            label = flight.get_label()
            print(label, end=" ")

            origin = flight.get_origin()
            takeoff = flight.get_takeoff_time()
            print(origin, takeoff, end=" ")
            intermediates = flight.get_intermediates()

            for intermediate, t, a in intermediates:
                print(intermediate, t, a, end=" ")

            destination = flight.get_destination()
            landing = flight.get_arrival_time()
            print(destination, landing)


    else:
        print("Não existem voos para esse destino a partir da cidade especificada")

    return

def initialize_single_source(G: Graph, s: Node):
    for v in G.get_adjlist():
        v.set_parent(None)
        v.set_distance(math.inf)

    s.set_parent(s)
    s.set_distance(0)  

def dijkstra(graph: Graph, start: City, end: City):
    initialize_single_source(graph, start)
    adjlist = graph.get_adjlist()

    visited = {}

    for v in adjlist.keys():
        visited[v] = False

    pq = PriorityQueue()
    pq.put((start.get_distance(), start))

    while not pq.empty():
        u_dist, u = pq.get()

        if u is end:
            return True
        
        if visited[u]:
            continue

        visited[u] = True
        for v, w in adjlist[u]:
            if v.get_distance() > u_dist + w:
                v.set_distance(u_dist + w)
                v.set_parent(u)
                pq.put((v.get_distance(), v))

    return False

def time_difference(start, end):
    start_hours, start_minutes = start.split(":")
    end_hours, end_minutes = end.split(":")

    st = int(start_hours) * 60 + int(start_minutes)
    ed = int(end_hours) * 60 + int(end_minutes)

    difference = abs(ed - st)

    return difference

def get_flight_path(G: Graph, s: Node, v: Node, flight_list: list):
    if v == s:
        return
    else:
        get_flight_path(G, s, v.get_parent(), flight_list)
        if isinstance(v, Flight):
            flight_list.append(v)

if __name__ == "__main__":
    main()