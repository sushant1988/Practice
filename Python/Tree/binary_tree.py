from tree_node import BinaryNode
from collections import deque
import sys

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

  def post_order_recursive(self):
    def post_order(root: BinaryNode):
      if root:
        post_order(root.left)
        post_order(root.right)
        print(root.data, end= " ")
    post_order(self.root)
    pass

  def pre_order_iterative(self):
    stack: deque = deque()
    stack.append(self.root)
    while(len(stack) > 0):
      temp = stack.pop()
      if temp.right: stack.append(temp.right)
      if temp.left: stack.append(temp.left)
      print(temp.data, end=" ")
    pass

  '''
  0 mean not yet processed
  1 mean processed
  '''
  def in_order_iterative(self):
    stack: deque = deque()
    stack.append((self.root.right, 0))
    stack.append((self.root, 1))
    stack.append((self.root.left, 0))
    while(len(stack) > 0):
      temp: tuple(BinaryNode, int) = stack.pop()
      if (temp[1] > 0):
        print(temp[0].data, end=" ")
      else:
        if temp[0].right: stack.append((temp[0].right, 0))
        stack.append((temp[0], 1))
        if temp[0].left: stack.append((temp[0].left, 0))
    pass

  def in_order_iterative_withoutstate(self):
    stack = deque()


  def post_order_iterative(self):
    stack: deque = deque()
    stack.append((self.root, 1))
    stack.append((self.root.right, 0))
    stack.append((self.root.left, 0))
    while(len(stack) > 0):
      temp: tuple(BinaryNode, int) = stack.pop()
      if (temp[1] > 0):
        print(temp[0].data, end=" ")
      else:
        stack.append((temp[0], 1))
        if temp[0].right: stack.append((temp[0].right, 0))
        if temp[0].left: stack.append((temp[0].left, 0))
    pass

  '''
    O(N) where n is number of nodes in tree
    space O(N) due to recursive solution
  '''
  def max_height(self) -> int:
    def max_height(node: BinaryNode):
      if not node:
        return 0

      return max(max_height(node.left), max_height(node.right)) + 1

    return max_height(self.root)

  '''
    O(N) solution to iterative all nodes. O(N) space to use queue
  '''
  def height_iterative(self) -> int:
    queue: deque = deque()
    queue.append(self.root)
    height = 0
    while True:
      nodeCount = len(queue)
      if nodeCount == 0:
        return height

      height += 1
      while(nodeCount > 0):
        temp = queue.popleft()
        if temp.left: queue.append(temp.left)
        if temp.right: queue.append(temp.right)
        nodeCount -= 1
    return 0

  '''
  O(N2) worst case
  '''
  def is_balanced(self) -> bool:
    def height(node: BinaryNode)-> int:
      if not node:
        return 0
      return max(height(node.left), height(node.right)) + 1

    def is_balanced(node: BinaryNode) -> bool:
      if not node:
        return True
      lhs = height(node.left)
      rhs = height(node.right)
      return (abs(lhs - rhs) <= 1) and is_balanced(node.left) and is_balanced(node.right)

    return is_balanced(self.root)

  ''' CTC 4.4
  O(N) height in the same recusion rather than calling height
  A balanced binary tree, also referred to as a height-balanced binary tree,
  is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1.
  '''
  def is_balanced_optimized(self):
    def is_balanced_optimized(node: BinaryNode)-> (int, bool):
      if not node:
        return 0, True

      lhs, l_balance = is_balanced_optimized(node.left)
      if not l_balance: return 0, False # if any of subtree is not balance don;t check other side

      rhs, r_balance = is_balanced_optimized(node.right)

      # if left or right subtree is not balanced no need to calculate height or anything else
      if r_balance:
        return max(lhs, rhs) + 1, abs(lhs-rhs) <= 1

      return 0, False

    height, is_balance = is_balanced_optimized(self.root)
    return is_balance

  def print_level_order(self):
    queue: deque = deque()
    queue.append(self.root)
    while(len(queue) > 0):
      temp = queue.popleft()
      print(temp.data, end=" ")
      if temp.left:  queue.append(temp.left)
      if temp.right: queue.append(temp.right)
    pass

  ''' CTC 4.5 check if Binary tree is BST
      time complexity: O(N) due to recusion space complexity will be O(log N) in balanced tree
  '''
  def check_if_bst(self):
    def check_if_bst(node: BinaryNode, min, max):
      if node:
        if node.data < min or node.data > max:
          return False

        if not check_if_bst(node.left, min, node.data) or not check_if_bst(node.right, node.data, max):
          return False

      return True

    return check_if_bst(self.root, -sys.maxsize+1, sys.maxsize)

if __name__ == '__main__':
  items=[1,2,3,4,5,0,0,8, 0, 12]
  tree = BinaryTree()
  tree.create_binary_tree_from_array_recursive(items)
  tree.pre_order_recursive()
  print("")
  tree.pre_order_iterative()
  print("")
  tree.in_order_recursive()
  print("")
  tree.in_order_iterative()
  print("")
  tree.post_order_recursive()
  print("")
  tree.post_order_iterative()
  print("")

  print("Max Height ", tree.max_height())
  print("Max Height ", tree.height_iterative())
  print(tree.is_balanced_optimized())
  items = [1,2,3,4,5,6,7]
  tree = BinaryTree()
  tree.create_binary_tree_from_array_recursive(items)
  tree.in_order_iterative()
  print(tree.check_if_bst())

