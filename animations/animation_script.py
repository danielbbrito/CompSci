from manim import *


class DFS(Scene):
    def construct(self):
        vertices = [1, 2, 3, 4, 5, 6, 7]
        edges = [(1, 2), (1, 3), (2, 3), (2, 5), (3, 4), (4, 5), (5, 6), (6, 7)]
        
        adjacency_list = {}
        
        graph = Graph(vertices, edges, layout="kamada_kawai", vertex_config={"color": BLUE, "radius": 0.1, "fill_opacity": 1})
        for a, b in edges:
            if a not in adjacency_list:
                adjacency_list[a] = set()
                
            adjacency_list[a].add(b)
                
            if b not in adjacency_list:
                adjacency_list[b] = set()
                
            adjacency_list[b].add(a)
            
        self.play(Create(graph))
        self.wait()
                
class MovingVertices(Scene):
    def construct(self):
        vertices = [1, 2, 3, 4]
        edges = [(1, 2), (2, 3), (3, 4), (1, 3), (1, 4)]
        g = Graph(vertices, edges)
        self.play(Create(g))
        self.wait()
        self.play(g[1].animate.move_to([1, 1, 0]),
                  g[2].animate.move_to([-1, 1, 0]),
                  g[3].animate.move_to([1, -1, 0]),
                  g[4].animate.move_to([-1, -1, 0]))
        self.wait()          