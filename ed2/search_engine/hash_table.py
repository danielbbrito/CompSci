from math import pow, floor

class Node:
    def __init__(self, key, value):
        self._key = key
        self._value = value
    
    def get_key(self):
        return self._key
    
    def set_key(self, k):
        self._key = k

    def get_value(self):
        return self._value
    
    def set_value(self, v):
        self._value = v

class HashTable:
    def  __init__(self):
        self._size = 2 # Garante que o tamnho será sempre potência de base 2
        self.slots = [None] * self._size
        self.occupied = 0

    def h1(self, key: str):
        # Computar a string
        key_integer = 0
        for i in range(len(key)):
            key_integer += ((ord(key[i]) - 96) * pow(31, i)) % self._size

        return key_integer % self._size
        
    def h2(self, key):
        # Computar a string
        key_integer = 0
        for i in range(len(key)):
            key_integer += (ord(key[i]) - 96 * pow(31, i)) % (self._size - 1)

        return key_integer % (self._size - 1)


    def hash(self, key) -> int:
        for i in range(self._size):
            pos = floor((self.h1(key) + i * self.h2(key)) % self._size)

            if self.slots[pos] is None:
                return pos
            
            elif self.slots[pos].get_key() == key:
                return pos
        return -1
        
    def resize(self):
        # Cria nova lista para acomodar a tabela hash
        self._size *= 2
        new_slots = [None] * self._size

        # Rehash (O(n))
        for entry in self.slots:
            if entry is not None:
                # Roda o procedimento de inserção
                pos = -1
                for i in range(self._size):
                    pos = floor((self.h1(entry.get_key()) + i * self.h2(entry.get_key())) % self._size)

                    if new_slots[pos] is None:
                        break

                if pos < 0:
                    self.resize()
                    return
                
                new_slots[pos] = entry

        # Atualiza a tabela hash
        self.slots = new_slots.copy()

        return



    def insert(self, key, value):
        pos = self.hash(key)

        if pos < 0: # Existe a necessidade de extender a lista
            self.resize()
            pos = self.hash(key)

        if self.slots[pos] is None:
            self.occupied += 1
        self.slots[pos] = Node(key, value)
        return
    
    def search(self, key):
        pos = self.hash(key)

        if pos != -1 and self.slots[pos] is not None:
            return self.slots[pos].get_value()
        
        return None
    
    def contains(self, key):
        pos = self.hash(key)

        if pos != -1 and self.slots[pos] is not None:
            return True
        
        return False