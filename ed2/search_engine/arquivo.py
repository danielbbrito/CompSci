class Arquivo:
    def __init__(self, nome, ocorrencias_palavra):
        self._nome = nome
        self._ocorrencias_palavra = ocorrencias_palavra
    
    def __eq__(self, other):
        return isinstance(other, Arquivo) and self._nome == other._nome
    
    def __hash__(self):
        return hash(self._nome)
    
    def get_nome(self):
        return self._nome

    def get_ocorrencias_palavra(self):
        return self._ocorrencias_palavra
    
    def set_ocorrencias_palavra(self, n):
        self._ocorrencias_palavra = n
