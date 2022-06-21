import math
import random
class Hashclose:
    def __init__(self, size):
        self.size = size
        self.hashVal = size
        self.table = []
        for i in range(size):
            self.table.append([None, None])
    def print(self):
        for el in self.table:
            if el[0]:
                print(f'HKEY: {self.hash(el[0])}', el)
        print(f'SIZE: {self.size}')
    def hash(self, key):
        return key % self.hashVal

    def __increaseTable(self):
        self.table += [[None, None] for i in range(self.size)]
        self.size *= 2

    def __decreaseTable(self):
        table = []
        for i in range(self.size // 2):
            table.append(self.table[i])
        self.table = table

    def update(self, key, value):
        hkey = self.hash(key)
        while self.table[hkey][0] != key and self.table[hkey][0]:
            hkey += 3
            if hkey > self.size // 2:
                self.__increaseTable()
        self.table[hkey] = [key, value]

    def ramove(self, key):
        hkey = self.hash(key)
        while hkey < self.size and self.table[hkey][0] != key:
            hkey += 3
        if hkey > self.size:
            raise Exception
        self.table[hkey] = [None, None]
        lastIndexWithValue = 0
        for i, el in enumerate(self.table[::-1]):
            if el[0]:
                lastIndexWithValue = i
                break
        if lastIndexWithValue < self.size // 4:
            self.__decreaseTable()

ht = Hashclose(10)
for i in range(30):
    ht.update(random.randint(0, 40), f'{ascii(i + 60)}')
ht.print()