import random


class Node:
    def __init__(self, d):
        self.__left = [None]
        self.__right = [None]
        self.__data = d
    @property
    def left(self):
        return self.__left[0]

    @left.setter
    def left(self, value):
        self.__left[0] = value
    @property
    def right(self):
        return self.__right[0]

    @right.setter
    def right(self, value):
        self.__right[0] = value
    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, value):
        self.__data = value
class Tree:
    def __init__(self, m):
        self.__root = Tree.__makeTree(m, 0, len(m))
    @property
    def root(self):
        return self.__root

    @root.setter
    def root(self, value):
        self.__root = value
    def __crawlPrint(self, node, pos):
        print(node.data, end='')
        if node.left:
            pos.append([len(str(node.data)), '|'])
        if node.right:
            print(' -> ', end='')
            self.__crawlPrint(node.right, pos)
        if node.left:
            pos[-1][1] = ' '
            print('')
            for k in range(2):
                for el in pos[:-1]:
                    for _ in range(el[0] - 1):
                        print(' ', end='')
                    print(el[1], end='')
                    print('    ', end='')
                for _ in range(pos[-1][0] - 1):
                    print(' ', end='')
                print('|', end='')
                if k == 0:
                    print('')
            print(' -> ', end='')
            self.__crawlPrint(node.left, pos)
            pos.pop()

    def print(self):
        self.__crawlPrint(self.root, [])

    @staticmethod
    def __makeTree(m, f, n):
        if not n:
            return None
        p = Node(m[f])
        nl = n//2
        nr = n - nl - 1
        p.left = Tree.__makeTree(m, f + 1, nl)
        p.right = Tree.__makeTree(m, f + 1 + nl, nr)
        return p

t = Tree([random.randint(0, 20) for _ in range(20)])
t.print()
