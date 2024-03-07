from manim import *
import csv
import os
config.disable_caching = True


class GraphSceneUtils(Scene):

    def set_vertex_color(self, vertex, color: color, animate=True):
        """
        Define a cor de um vértice (nó)
        """
        if animate:
            self.play(
                vertex[0].animate.set_color(color), 
                vertex[1].animate.set_color(WHITE)
                )
            return
        
        self.add(vertex.set_color(color), vertex[1].set_color(WHITE))
        return
    
    def set_edge_color(self, edge, color: color, animate=True):
        """
        Define a cor de uma aresta. Não funciona atualmente
        """

        if animate:
            self.play(edge.animate.set_color(color))
            self.wait()
            return

        self.add(edge.set_color(color))
        self.wait()
        return

    def build_adjacency_list(self, edge_list: list, is_directed=False) -> dict:
        """
        Cria uma lista de adjacência com base em uma lista de arestas
        """
        al = {}

        for x, y in edge_list:
            if x in al:
                al[x].append(y)
            else:
                al[x] = [y]

            if not is_directed:
                if y in al:
                    al[y].append(x)
                else:
                    al[y] = [x]

        return al

    def read_file_input(self, filename: str):
        """
        Lê um arquivo csv com os dados das arestas do grafo desejado. Retorna uma lista de arestas e uma lista de vértices em forma de tupla.
        """
        edge_list = []
        vertices = []

        __location__ = os.path.realpath(
        os.path.join(os.getcwd(), os.path.dirname(__file__)))
        
        with open(os.path.join(__location__, filename), 'r+') as file:
            reader = csv.reader(file)
            for x in reader:

                for i in range(len(x)):
                    x[i] = int(x[i])

                    if x[i] not in vertices:
                        vertices.append(x[i])

                if tuple(x) not in edge_list:
                    edge_list.append(tuple(x))

        return (edge_list, vertices)
    



