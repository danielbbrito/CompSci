import math
import datetime
from queue import PriorityQueue

# Lidar com voos intermediarios

class Graph:
    def __init__(self, directed=False, weighted=False):
        self._directed = directed
        self._adjlist = {}
        self._adjmatrix = []
        self._vertexlist = set()
        self._weighted = weighted

    def add_vertex(self, node):
        self._vertexlist.add(node)

    def vertices(self):
        return self._vertexlist
    
    def add_edge(self, node1, node2, weight=None):
        self.add_vertex(node1)
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
    def __init__(self, label, type):
        self._label = label
        self._parent = None
        self._distance = math.inf
        self._type = type
    def __lt__(self, other):
        return isinstance(other, Node) and self._distance < other._distance
    
    def __gt__(self, other):
        return isinstance(other, Node) and self._distance > other._distance
    
    def __eq__(self, other):
        return isinstance(other, Node) and self._label == other._label and self._type == other._type
    
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
    
    def set_type(self, t):
        self._type = t

    def get_type(self):
        return self._type
    
class Flight(Node):
    def __init__(self, label, type, takeoff_time=None, arrival_time=None):
        super().__init__(label, type)
        self._origin = None
        self._destination = None
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
    

class City(Node):
    def __init__(self, label, type):
        super().__init__(label, type)
        self._arrival_time = None

    def set_arrival_time(self, t):
        self._arrival_time = t
    
    def get_arrival_time(self):
        return self._arrival_time


def main():
    graph = Graph(True, True)

    flights_leaving = dict()

    flights_arriving = dict()
    # Read flight information file
    with open("ed2/grafos/airport/cmp1099-trabalho-grafo_dijkstra-arquivo_voos.txt", "r+") as FILE:
        for line in FILE:
            line = line.split(" ")
            flight = line[0]
            
            origin = City(line[1], "Origem")

            for v in graph.get_adjlist():
                if v == origin:
                    origin = v
                    break
            takeoff = line[2]

            flight_object = Flight(flight, "Origem")
            flight_object.set_origin(line[1])
            flight_object.set_takeoff_time(takeoff)
            graph.add_edge(origin, flight_object, 0)

            if line[1] in flights_leaving.keys():
                flights_leaving[line[1]].append(flight_object)
            else:
                flights_leaving[line[1]] = [flight_object]

            # Handle intermediate cities
            intermediates = False

            for i in range(2, len(line) - 2):
                if line[i][0].isalpha():    
                    intermediate_origin = City(line[i], "Origem")
                    available = False
                    for v in graph.get_adjlist():
                        if v == intermediate_origin:
                            available = True
                            intermediate_origin = v
                            break

                    flight_intermediate_origin = Flight(flight, "EscalaOrigem")
                    flight_intermediate_origin.set_origin(line[i])
                    flight_intermediate_origin.set_arrival_time(line[i + 1])
                    time = time_difference(flight_object.get_arrival_time(), line[i + 1])
                    graph.add_edge(flight_object, flight_intermediate_origin, time)
                    
                    if line[i] in flights_arriving.keys():
                        flights_arriving[line[i]].append(flight_intermediate_origin)
                    else:
                        flights_arriving[line[i]] = [flight_intermediate_origin]

                    # Connect arrival to every other flight in the origin
                    fs = flights_leaving.get(line[i], [])

                    for f in fs:
                        time = time_difference(flight_intermediate_origin.get_arrival_time(), f.get_takeoff_time())
                        if time >= 30:
                            graph.add_edge(flight_intermediate_origin, f, time)
                        else:
                            time = time_difference(f.get_arrival_time(), flight_object.get_takeoff_time())
                            graph.add_edge(flight_intermediate_origin, f, time)

                    intermediate_destination = City(line[i], "Destino")
                    available = False
                    for v in graph.get_adjlist():
                        if v == intermediate_destination:
                            available = True
                            intermediate_destination = v
                            break
                    
                    flight_intermediate_destination = Flight(flight, "EscalaDestino")
                    flight_intermediate_destination.set_origin(line[i])
                    flight_intermediate_destination.set_takeoff_time(line[i + 2])
                    
                    if line[i] in flights_leaving.keys():
                        flights_leaving[line[i]].append(flight_intermediate_destination)
                    else:
                        flights_leaving[line[i]] = [flight_intermediate_destination]

                    # Connect intermediate final flight to every other intermediate destination flight
                    fs = flights_arriving.get(line[i], [])
                    
                    for f in fs:

                        time = time_difference(f.get_arrival_time(), flight_intermediate_destination.get_takeoff_time())

                        if time >= 30:
                            graph.add_edge(f, flight_intermediate_destination, time)
                        
                        else:
                            time = time_difference(flight_intermediate_destination.get_takeoff_time(), f.get_arrival_time())
                            graph.add_edge(f, flight_intermediate_destination, time)


                    time = time_difference(line[i + 1], line[i + 2])
                    graph.add_edge(flight_intermediate_origin, flight_intermediate_destination, time)
                    graph.add_edge(intermediate_origin, flight_intermediate_destination, 0)
                    graph.add_edge(flight_intermediate_origin, intermediate_destination, 0)
                    intermediates = True
                  
            destination = City(line[len(line) - 2], "Destino")
            for v in graph.get_adjlist():
                if v == destination:
                    destination = v
                    break

            landing = line[len(line) - 1]

            flight_destination = Flight(flight, "Destino")
            flight_destination.set_destination(destination)
            flight_destination.set_arrival_time(landing)

            if line[len(line) - 2] in flights_arriving.keys():
                flights_arriving[line[len(line) - 2]].append(flight_destination)
            else:
                flights_arriving[line[len(line) - 2]] = [flight_destination]

            if intermediates:
                time = time_difference(line[len(line) - 3], landing)
                graph.add_edge(flight_intermediate_destination, flight_destination, time)
            else:
                time = time_difference(takeoff, landing)
                graph.add_edge(flight_object, flight_destination, time)

            graph.add_edge(flight_destination, destination, 0)

            # Connect destination flight to new flights
            fs = flights_arriving.get(line[1], [])

            
            for f in fs:
                time = time_difference(f.get_arrival_time(), flight_object.get_takeoff_time())
                if time >= 30:
                    graph.add_edge(f, flight_object, time)
                else:
                    time = time_difference(flight_object.get_takeoff_time(), f.get_arrival_time())
                    graph.add_edge(f, flight_object, time)
                

            # Conect destination flight to origin flights
            fs = flights_leaving.get(line[len(line) - 2], [])
            for f in fs:
                time = time_difference(flight_destination.get_arrival_time(), f.get_takeoff_time())
                if time >= 30:
                    graph.add_edge(flight_destination, f, time)
                else:
                    time = time_difference(f.get_takeoff_time(), flight_destination.get_arrival_time())
                    graph.add_edge(flight_destination, f, time)
                

            
    # Read origin and destination cities
    while True:
        origin = input("Cidade de origem: ")

        found = False
        for v in graph.vertices():
            if v.get_label() == origin and v.get_type() == "Origem":
                origin = v
                found = True
                break
        
        if not found:
            print("Não existem voos saindo da cidade informada")
            continue
        else:
            break

    while True:
        destination = input("Cidade de destino: ")
        found = False

        for v in graph.vertices():
            if v.get_label() == destination and v.get_type() == "Destino":
                destination = v
                found = True
                break
        
        if not found:
            print("Não existem voos chegando na cidade informada")
            continue
        else:
            break

    
    if dijkstra(graph, origin, destination):
        print(f"Origem: {origin.get_label()}")
        print(f"Destino: {destination}")
        print(f"Distancia: {destination.get_distance()}")

        flight_list = {}
        get_flight_path(graph, origin, destination, flight_list)
        
        for flight in flight_list:
            print(flight_list[flight])


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
    start.set_arrival_time(None)
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
    if start is None or end is None:
        return 0
    
    start_hours, start_minutes = start.split(":")
    end_hours, end_minutes = end.split(":")

    st = int(start_hours) * 60 + int(start_minutes)
    ed = int(end_hours) * 60 + int(end_minutes)

    if ed >= st:
        difference = ed - st
    else:
        # If the end time is on the next day
        difference = (24 * 60 - st) + ed

    return difference

def get_flight_path(G: Graph, s: Node, v: Node, flight_list: dict):
    if v == s:
        return
    else:
        get_flight_path(G, s, v.get_parent(), flight_list)
        if isinstance(v, Flight):
            if v.get_type() == "Origem":
                st = f"{v.get_label()} {v.get_origin()} {v.get_takeoff_time()}"
                flight_list[v.get_label()] = st
            elif v.get_type() == "EscalaOrigem":
                if v.get_label() in flight_list.keys():
                    flight_list[v.get_label()] = flight_list[v.get_label()] + f" {v.get_origin()} {v.get_arrival_time()}"
                else:
                    flight_list[v.get_label()] = f"{v.get_label()} {v.get_origin()} {v.get_arrival_time()}"
            
            elif v.get_type() == "EscalaDestino":
                if v.get_label() in flight_list.keys():
                    flight_list[v.get_label()] = flight_list[v.get_label()] + f" {v.get_arrival_time()}"
                else:
                    flight_list[v.get_label()] = f"{v.get_label()} {v.get_origin()} {v.get_takeoff_time()}"

            else:
                flight_list[v.get_label()] = flight_list[v.get_label()] + f" {v.get_destination()} {v.get_arrival_time()}"


def compare_times(t1: str, t2: str):
    h1, m1 = t1.split(":")
    h2, m2 = t2.split(":")
    h1 = int(h1)
    h2 = int(h2)
    m1 = int(m1)
    m2 = int(m2)

    if h1 < h2:
        return 1
    
    elif h2 < h1:
        return 2
    
    else:
        if m1 < m2:
            return 1
        else:
            return 2

if __name__ == "__main__":
    main()