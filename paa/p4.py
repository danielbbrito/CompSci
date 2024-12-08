from manim import *
from manim_slides import Slide

class ShortestPathPresentation(Slide):
    def construct(self):
        # Slide 1: Título e Definição do Problema
        title = Text("Caminho Mais Curto entre Voos", font_size=50)
        subtitle = Text("Definição do Problema", font_size=36).next_to(title, DOWN)
        problem = Text(
            "Dado um conjunto de dados contendo voos,\n"
            "encontrar o caminho mais curto entre uma origem A e um destino B.",
            font_size=30
        ).next_to(subtitle, DOWN)
        self.play(Write(title), Write(subtitle))
        self.pause()
        self.play(FadeIn(problem))
        self.pause()
        self.play(FadeOut(title), FadeOut(subtitle), FadeOut(problem))

        # Slide 2: Complexidade do Algoritmo
        complexity_title = Text("Análise de Complexidade", font_size=50)
        dijkstra_complexity = Tex(
            r"""
            \textbf{Dijkstra (com Heap Binário)}:\\
            - Inserção/Atualização: $O(\log V)$\\
            - Relaxamento de Arestas: $O(E \cdot \log V)$\\
            - Processamento de Vértices: $O(V \cdot \log V)$\\
            \textbf{Complexidade Total:} $O((V + E) \cdot \log V)$
            """,
            font_size=32
        ).next_to(complexity_title, DOWN)
        self.play(Write(complexity_title))
        self.pause()
        self.play(FadeIn(dijkstra_complexity))
        self.pause()
        self.play(FadeOut(complexity_title), FadeOut(dijkstra_complexity))

        # Slide 3: Código do Algoritmo
        code_title = Text("Código do Algoritmo", font_size=50)
        code_snippet = Code(
            code="""
def dijkstra(graph, start):
    import heapq
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        current_dist, current_node = heapq.heappop(pq)
        if current_dist > dist[current_node]:
            continue
        for neighbor, weight in graph[current_node]:
            distance = current_dist + weight
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    return dist
            """,
            language="Python",
            font_size=22
        ).next_to(code_title, DOWN)
        self.play(Write(code_title))
        self.pause()
        self.play(FadeIn(code_snippet))
        self.pause()
        self.play(FadeOut(code_title), FadeOut(code_snippet))

        # Slide 4: Resultados
        results_title = Text("Resultados", font_size=50)
        example_graph = SVGMobject("graph_example.svg").scale(2).next_to(results_title, DOWN)
        self.play(Write(results_title))
        self.pause()
        self.play(FadeIn(example_graph))
        self.pause()
        self.play(FadeOut(results_title), FadeOut(example_graph))

        # Finalizar
        conclusion = Text("Obrigado!", font_size=50)
        self.play(Write(conclusion))
        self.pause()
