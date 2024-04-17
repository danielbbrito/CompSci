class Arquivo:
    def __init__(self, nome, ocorrencias_palavra):
        self._nome = nome
        self._ocorrencias_palavra = ocorrencias_palavra
        
    def __str__(self):
        return f"Arquivo de nome {self._nome} e com {self._ocorrencias_palavra} ocorrências da palavra"
    
    def get_nome(self):
        return self._nome

    def get_ocorrencias_palavra(self):
        return self._ocorrencias_palavra
    
    def set_ocorrencias_palavra(self, n):
        self._ocorrencias_palavra = n
