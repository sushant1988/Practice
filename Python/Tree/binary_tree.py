from tree_node import BinaryNode
from collections import deque

class BinaryTree:
  def __init__(self):
    self.root = None

  def create_binary_tree_from_array_recursive(self, items: list):
    def create_binary_recursive(root: BinaryNode, items: list, idx: int):
      if idx >= len(items) or items[idx] == 0:
          return None
      else:
        root = BinaryNode(items[idx])
        root.left = create_binary_recursive(root.left, items, 2 * idx + 1)
        root.right = create_binary_recursive(root.right, items, 2 * idx + 2)
        return root

    if len(items) > 0:
      self.root = create_binary_recursive(self.root, items, 0)
    pass

  def in_order_recursive(self):
    def in_order(root: BinaryNode):
      if root:
        in_order(root.left)
        print(root.data, end= " ")
        in_order(root.right)

    in_order(self.root)
    pass

  def pre_order_recursive(self):
    def pre_order(root: BinaryNode):
      if root:
        print(root.data, end= " ")
        pre_order(root.left)
        pre_order(root.right)
    pre_order(self.root)
    pass

  def print_level_order(self):
    queue: deque = deque()
    queue.append(self.root)
    while(len(queue) > 0):
      temp = queue.popleft()
      print(temp.data, end=" ")
      if temp.left:  queue.append(temp.left)
      if temp.right: queue.append(temp.right)

    pass


if __name__ == '__main__':
  items=[1,2,3,4,5,0,7,8, 0, 12]
  tree = BinaryTree()
  tree.create_binary_tree_from_array_recursive(items)
  #tree.pre_order_recursive()
  tree.print_level_order()

