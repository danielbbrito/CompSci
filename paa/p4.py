from manim import *
from manim_slides import Slide

class ShortestPathPresentation(Slide):
    def construct(self):
        # Slide 1: Título e Objetivo
        title = Text("Caminho de menor duração de voos entre duas cidades", font_size=36)
        subtitle = Text("Daniel Ribeiro de Brito", font_size=24).next_to(title, DOWN)
        self.play(Write(title), Write(subtitle))
        self.wait()  # Wait indefinitely until manually advanced

        # Slide 2: Definição do Problema
        self.clear()  # Clear previous slide contents
        problem_title = Text("Definição do Problema", font_size=32)
        problem_text = Text(
            "Dado um conjunto de dados contendo voos:\n"
            "1. Cada voo conecta duas cidades, com possíveis conexões.\n"
            "2. Possui horários de partida e chegada.\n"
            "Objetivo: Encontrar o caminho mais curto entre uma origem A e um destino B.",
            font_size=24,
            line_spacing=1.5
        ).scale(0.7).next_to(problem_title, DOWN, buff=0.5)
        
        self.play(Write(problem_title), Write(problem_text))
        self.wait()  # Wait indefinitely

        title = Text("Complexidade do Algoritmo de Dijkstra", font_size=50).to_edge(UP)
        
        title = Text("Fase de Inicialização", font_size=50).to_edge(UP)
        
        # Initialization Details
        init_details = Tex(
            r"""
            \textbf{Passos de Inicialização:}
            \begin{itemize}
                \item Definir distâncias iniciais: $O(V)$
                \item Criar fila de prioridade: $O(V)$
                \item Vértice fonte: distância $0$
                \item Outros vértices: distância $\infty$
            \end{itemize}
            
            \textbf{Complexidade:} $O(V)$
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        # Visualization of Initialization
        vertex_group = VGroup()
        for i in range(5):
            vertex = Circle(radius=0.3, color=BLUE)
            vertex.shift(RIGHT * i)
            vertex_group.add(vertex)
        
        vertex_group.next_to(init_details, DOWN)
        
        # Annotations
        source_label = Text("Fonte", font_size=20, color=RED).next_to(vertex_group[0], DOWN)
        other_label = Text("Outros", font_size=20, color=BLUE).next_to(vertex_group[1], DOWN)
        
        # Animations
        self.play(Write(title))
        self.play(Write(init_details))
        self.play(Create(vertex_group), Write(source_label), Write(other_label))
        self.wait()

        # Slide 4: Código do Algoritmo
        self.clear()  # Clear previous slide contents
        code_title = Text("Código do Algoritmo", font_size=50).to_edge(UP)
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
        self.play(Write(code_snippet))
        self.wait()  # Wait indefinitely

        # Slide 5: Resultados com Grafo Gerado
        self.clear()  # Clear previous slide contents
        results_title = Text("Resultados - Grafo Gerado", font_size=50).to_edge(UP)
        
        # Criar o grafo sem labels diretamente nas arestas
        graph = Graph(
            vertices=["A", "B", "C", "D", "E"],
            edges=[
                ("A", "B"), ("B", "C"), ("A", "D"), 
                ("D", "E"), ("C", "E")
            ],
            layout="spring"
        ).scale(1.2).to_edge(DOWN)

        # Adicionar labels manualmente nas arestas
        edge_labels = {
            ("A", "B"): "1h",
            ("B", "C"): "2h",
            ("A", "D"): "3h",
            ("D", "E"): "1h",
            ("C", "E"): "1.5h"
        }
        
        labels = []
        for edge, label in edge_labels.items():
            start, end = edge
            
            # Use get_vertices() and calculate midpoint
            start_vertex = graph.vertices[start]
            end_vertex = graph.vertices[end]
            
            # Calculando o ponto médio entre os dois vértices
            mid_point = (start_vertex.get_center() + end_vertex.get_center()) / 2
            
            # Criando o rótulo da aresta
            edge_label = Text(label, font_size=24).move_to(mid_point)
            labels.append(edge_label)
        
        self.play(Write(results_title))
        self.play(Create(graph))
        
        # Exibir os labels das arestas
        for label in labels:
            self.play(Write(label))
        self.wait()  # Wait indefinitely

        # Slide Final: Agradecimentos
        self.clear()  # Clear previous slide contents
        conclusion = Text("Obrigado!", font_size=50).to_edge(UP)
        self.play(Write(conclusion))
        self.wait()  # Wait indefinitely


class SlideOne(Slide):
    def construct(self):
        title = Text("Caminho de menor duração de voos entre duas cidades", font_size=36)
        subtitle = Text("Daniel Ribeiro de Brito", font_size=24).next_to(title, DOWN)
        self.play(Write(title), Write(subtitle))
        self.wait()  # Wait indefinitely until manually advanced

class SlideTwo(Slide):
    def construct(self):
        problem_title = Text("Definição do Problema", font_size=32)
        problem_text = Text(
            "Dado um conjunto de dados contendo voos na forma\n"
            "[Código] [Origem] 00:44 [Destino] 03:25\n"
            "Ou\n"
            "[Código] [Origem] 07:19 [Conexão] 10:38 11:30 [Destino] 12:40\n"
            "Encontrar o caminho mais curto entre uma origem A e um destino B.",
            font_size=24,
            line_spacing=1.5
        ).scale(0.7).next_to(problem_title, DOWN, buff=0.5)
        
        self.play(Write(problem_title), Write(problem_text))
        self.wait()  # Wait indefinitely


# class SlideThree(Slide):
#     def construct(self):
#         title = Text("Complexidade do Algoritmo de Dijkstra", font_size=50).to_edge(UP)
        
#         title = Text("Fase de Inicialização", font_size=50).to_edge(UP)
        
#         # Initialization Details
#         init_details = Tex(
#             r"""
#             \begin{itemize}
#                 \item Definir distâncias iniciais: $O(|V|)$
#                 \item Criar fila de prioridade: $O(|V|)$
#                 \item Vértice fonte: distância $0$
#                 \item Outros vértices: distância $\infty$
#             \end{itemize}
            
#             \textbf{Complexidade:} $O(|V|)$
#             """, 
#             font_size=35
#         ).next_to(title, DOWN)
        
        
#         # Animations
#         self.play(Write(title))
#         self.play(Write(init_details))
        
#         self.wait()


class SlideFour(Slide):
    def construct(self):
        # Clear previous contents
        self.clear()
        
        # Title
        title = Text("Operações da Fila de Prioridade", font_size=50).to_edge(UP)
        
        # Priority Queue Operations with Complexity
        pq_details = Tex(
            r"""
            \textbf{Operações na Fila de Prioridade com Heap Binária:}
            \begin{itemize}
                \item Inserção: $O(\log |V|)$
                \item Extrair Mínimo: $O(\log |V|)$
                \item Diminuir Chave: $O(\log |V|)$
            \end{itemize}
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        nodes = [
            Circle(radius=0.3, color=BLUE).move_to((0, 0, 0)),  # Root
            Circle(radius=0.3, color=BLUE).move_to((-1.5, -1, 0)),  # Left child
            Circle(radius=0.3, color=BLUE).move_to((1.5, -1, 0)),  # Right child
            Circle(radius=0.3, color=BLUE).move_to((-2.5, -2, 0)),  # Left-left child
            Circle(radius=0.3, color=BLUE).move_to((-0.5, -2, 0)),  # Left-right child
            Circle(radius=0.3, color=BLUE).move_to((0.5, -2, 0)),   # Right-left child
            Circle(radius=0.3, color=BLUE).move_to((2.5, -2, 0)),   # Right-right child
        ]
        
        # Labels for the nodes
        labels = [
            Text("10", font_size=20).move_to(nodes[0].get_center()),
            Text("20", font_size=20).move_to(nodes[1].get_center()),
            Text("15", font_size=20).move_to(nodes[2].get_center()),
            Text("30", font_size=20).move_to(nodes[3].get_center()),
            Text("40", font_size=20).move_to(nodes[4].get_center()),
            Text("50", font_size=20).move_to(nodes[5].get_center()),
            Text("60", font_size=20).move_to(nodes[6].get_center()),
        ]
        
        # Edges connecting the nodes
        edges = [
            Line(nodes[0].get_bottom(), nodes[1].get_top(), color=GRAY),
            Line(nodes[0].get_bottom(), nodes[2].get_top(), color=GRAY),
            Line(nodes[1].get_bottom(), nodes[3].get_top(), color=GRAY),
            Line(nodes[1].get_bottom(), nodes[4].get_top(), color=GRAY),
            Line(nodes[2].get_bottom(), nodes[5].get_top(), color=GRAY),
            Line(nodes[2].get_bottom(), nodes[6].get_top(), color=GRAY),
        ]
        
        # Grouping everything
        tree = VGroup(*nodes, *edges, *labels).next_to(pq_details, DOWN)
        
            
        # Animations
        self.play(Write(title))
        self.play(Write(pq_details))
        self.play(Create(tree))
        self.wait()


# class SlideFive(Slide):
#     def construct(self):
#         self.clear()
        
#         # Title
#         title = Text("Relaxamento de Arestas", font_size=50).to_edge(UP)
        
#         # Edge Relaxation Details
#         edge_details = Tex(
#             r"""
#             \textbf{Processo de Relaxamento:}
#             \begin{itemize}
#                 \item Examinar todas as arestas adjacentes de um vértice.
#                 \item Atualizar a distância mais curta se uma aresta melhora o caminho.
#                 \item Repete para todos os vértices.
#             \end{itemize}
            
#             \textbf{Análise da Complexidade:}
#             \begin{itemize}
#                 \item A fila de prioridade (heap binária) requer $O(\log V)$ para inserir ou atualizar cada vértice.
#                 \item Cada aresta é relaxada uma vez, resultando em $O(E)$ operações de relaxamento.
#                 \item Portanto, a complexidade total é $O((V + E) \cdot \log V)$:
#             \end{itemize}
#             """, 
#             font_size=35
#         ).next_to(title, DOWN)
#         self.play(Write(title))
#         self.play(Write(edge_details))
#         self.wait()

class SlideSix(Slide):
    def construct(self):
        self.clear()
        
        # Title
        title = Text("Operação: Inicialização", font_size=50).to_edge(UP)
        
        # Initialização
        initialization_details = Tex(
            r"""
            \textbf{Inicialização:} $O(|V|)$
            \begin{itemize}
                \item Todas as distâncias são inicializadas como infinito ($\infty$), exceto a origem.
                \item A fila de prioridade é preenchida inicialmente com os vértices e suas distâncias.
            \end{itemize}
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        # Animations
        self.play(Write(title))
        self.play(Write(initialization_details))
        self.wait()

class SlideSeven(Slide):
    def construct(self):
        self.clear()
        
        # Title
        title = Text("Operações: Extrair Mínimo", font_size=50).to_edge(UP)
        
        # Extrair Mínimo
        extract_min_details = Tex(
            r"""
            \textbf{Extrair Mínimo:} $O(|V| \cdot \log |V|)$
            \begin{itemize}
                \item Cada vértice é removido da fila de prioridade uma única vez.
                \item Em uma heap binária, a operação de remoção custa $O(\log |V|)$.
            \end{itemize}
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        # Animations
        self.play(Write(title))
        self.play(Write(extract_min_details))
        self.wait()

class SlideEight(Slide):
    def construct(self):
        self.clear()
        
        # Title
        title = Text("Operação: Relaxamento", font_size=50).to_edge(UP)
        
        # Relaxamento de Arestas
        relaxation_details = Tex(
            r"""
            \textbf{Relaxamento de Arestas:} $O(|E| \cdot \log |V|)$
            \begin{itemize}
                \item Cada aresta é relaxada uma única vez durante o algoritmo.
                \item Relaxar uma aresta pode levar a uma atualização na fila de prioridade.
                \item Atualização na fila de prioridade custa $O(\log |V|)$.
            \end{itemize}
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        # Animations
        self.play(Write(title))
        self.play(Write(relaxation_details))
        self.wait()

class SlideNine(Slide):
    def construct(self):
        self.clear()
        
        # Title
        title = Text("Complexidade Total", font_size=50).to_edge(UP)
        
        # Total Complexity Explanation (Adjacency List)
        total_complexity_details = Tex(
            r"""
            \textbf{Complexidade Total:} $O((|V| + |E|) \cdot \log |V|)$
            \begin{itemize}
                \item A complexidade total é a soma das complexidades das operações:
                    \begin{itemize}
                        \item Inicialização: $O(|V|)$
                        \item Extrair Mínimo: $O(|V| \cdot \log |V|)$
                        \item Relaxamento de Arestas: $O(|E| \cdot \log |V|)$
                    \end{itemize}
            \end{itemize}
                        
            \vspace{1cm}
            
            \textbf{Portanto:}
            \[
            O(|V|) + O(|V| \cdot \log |V|) + O(|E| \cdot \log |V|) = O((|V| + |E|) \cdot \log |V|)
            \]
            """, 
            font_size=35
        ).next_to(title, DOWN)
        
        # Animations
        self.play(Write(title))
        self.play(Write(total_complexity_details))
        self.wait()


class SlideTen(Slide):
    def construct(self):
        self.clear()

        # Title
        title = Text("Código do Algoritmo de Dijkstra (Parte 1)", font_size=50).to_edge(UP)

        # First Part of the Code for Dijkstra
        code_part1 = Code(
            code=r"""
def dijkstra(graph: Graph, start: City, end: City):
    initialize_single_source(graph, start)
    adjlist = graph.get_adjlist()

    visited = {}

    for v in adjlist.keys():
        visited[v] = False

    pq = PriorityQueue()
    pq.put((start.get_distance(), start))
            """,
            language="Python",
            font_size=18,  # Font size reduced to fit
            line_spacing=0.3,
            background="window",
            style="monokai"
        ).next_to(title, DOWN, buff=0.5)

        # Animations
        self.play(Write(title))
        self.play(Write(code_part1))
        self.wait()


class SlideEleven(Slide):
    def construct(self):
        self.clear()

        # Title
        title = Text("Código do Algoritmo de Dijkstra (Parte 2)", font_size=50).to_edge(UP)

        # Second Part of the Code for Dijkstra
        code_part2 = Code(
            code=r"""
    while not pq.empty():
        u_dist, u = pq.get()

        if u == end:
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
            """,
            language="Python",
            font_size=18,  # Font size reduced to fit
            line_spacing=0.3,
            background="window",
            style="monokai"
        ).next_to(title, DOWN, buff=0.5)

        # Animations
        self.play(Write(title))
        self.play(Write(code_part2))
        self.wait()

class SlideTwelve(Slide):
    def construct(self):
        self.clear()

        # Title
        title = Text("Resultado do Algoritmo de Dijkstra", font_size=50).to_edge(UP)

        # Input Details (Origem, Destino, Distância)
        input_details = Tex(
            r"""
            \textbf{Origem:} Goiânia \\
            \textbf{Destino:} Varsóvia \\
            \textbf{Distância:} 134 minutos / 2:14 horas\\
            """, 
            font_size=35
        ).next_to(title, DOWN)

        # Flight Information
        flight_details = Tex(
            r"""
            \textbf{Rota Encontrada:} \\
            \textbf{ALITALIA3478:} Goiânia 09:17 → Lima 09:44 \\
            \textbf{KLM7143:} Lima 11:00 → Varsóvia 11:31
            """, 
            font_size=35
        ).next_to(input_details, DOWN)

        # Animations
        self.play(Write(title))
        self.play(Write(input_details))
        self.play(Write(flight_details))
        self.wait()




           

