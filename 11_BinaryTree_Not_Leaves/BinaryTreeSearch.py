import random
class Node:
    def __init__(self, d):
        self.__data = d
        self.__left = []
        self.__right = []

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, d):
        self.__data = d

    @property
    def left(self):
        return self.__left

    @left.setter
    def left(self, l):
        self.__left = l

    @property
    def right(self):
        return self.__right

    @right.setter
    def right(self, r):
        self.__right = r


class Tree:
    def __init__(self):
        self.__root = None

    @property
    def root(self):
        return self.__root

    @root.setter
    def root(self, node):
        self.__root = node

    def __crawlPrint(self, node, pos):
        print(node.data, end='')
        if node.left:
            pos.append([len(str(node.data)), '|'])
        if node.right:
            print(' -> ', end='')
            self.__crawlPrint(node.right[0], pos)
        if node.left:
            pos[-1][1] = ' '
            print('')
            for k in range(2):
                for el in pos[:-1]:
                    for _ in range(el[0] - 1):
                        print(' ', end='')
                    print(el[1], end='')
                    print("    ", end='')
                for _ in range(pos[-1][0] - 1):
                    print(' ', end='')
                print('|', end='')
                if k == 0:
                    print('')
            print(' -> ', end='')
            self.__crawlPrint(node.left[0], pos)
            pos.pop()


    def print(self):
        self.__crawlPrint(self.root, [])

    def insert(self, d):
        if not self.root:
            self.root = Node(d)
        else:
            stop = False
            cur = self.root
            while not stop:
                if d < cur.data:
                    if not cur.left:
                        cur.left.append(Node(d))
                        stop = True
                    else:
                        cur = cur.left[0]
                if d >= cur.data:
                    if not cur.right:
                        cur.right.append(Node(d))
                        stop = True
                    else:
                        cur = cur.right[0]


t = Tree()
for i in range(0, 10):
    t.insert(random.randint(1, 100))
t.print()

