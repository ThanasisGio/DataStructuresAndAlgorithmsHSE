# python3
import sys, threading
from collections import deque, defaultdict
sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size
class Compute_tree_Height:
        def read(self):
                self.n = int(sys.stdin.readline())
                self.parent = list(map(int, sys.stdin.readline().split()))
        def compute_height(self):
                nodes = defaultdict(set)
                for i in range(self.n):
                    if self.parent[i] == -1: root = i
                    else: nodes[self.parent[i]].add(i)
                if nodes == None: return
                a, height, targ, act= deque([root]), 0, root, 0
                while a:
                    node = a.popleft()
                    if node == targ:
                        height, act = height + 1, 1
                    if nodes[node] != []:
                        for i, child in enumerate(nodes[node]):
                            a.append(child)
                        if act == 1 and a:
                            targ, act = a[-1], 0
                return height
def main():
  tree = Compute_tree_Height()
  tree.read()
  print(tree.compute_height())
threading.Thread(target = main).start()
