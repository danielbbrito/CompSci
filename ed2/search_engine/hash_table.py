class Node:
    def __init__(self, key, value):
        self._key = key
        self._value = value

    @property
    def key(self):
        return self._key
    
    @key.setter
    def key(self, k):
        self._key = k

    @property
    def value(self):
        return self._value
    
    @value.setter
    def value(self, v):
        self._value = v

class HashTable:
    def  __init__(self):
        self.slots = []
        self._size
        self._q

    def multiply(self, key):
        return self._size * ()

    def put(self, k, val):


