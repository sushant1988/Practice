from tree_node import BinaryNode
from collections import deque

class BST:
  def __init__(self):
    self.root = None

  def copy(self, root_node: BinaryNode):
    self.root = root_node

  def create_bst_from_list(self, items:list):
    for item in items:
      self.insert_iterative(item)

  '''
  O(log N) insert recursive space O(N)
  '''
  def insert_recursive(self, data):
    def insert_recursive(root, data):
      if root is None:
        return BinaryNode(data)

      if root.data >= data:
        root.left = insert_recursive(root.left, data)
      else:
        root.right = insert_recursive(root.right, data)

      return root

    self.root = insert_recursive(self.root, data)

  ''' iterative
    O(log N) inset with space O(1)
  '''
  def insert_iterative(self, data):
    if self.root is None:
      self.root = BinaryNode(data)
      return

    temp = self.root
    while(True):
      if temp.data >= data:
        if temp.left: temp = temp.left
        else: temp.left = BinaryNode(data); return
      else:
        if temp.right: temp = temp.right
        else: temp.right = BinaryNode(data); return


  def in_order_recursive(self):
    def in_order(root: BinaryNode):
      if root:
        in_order(root.left)
        print(root.data, end= " ")
        in_order(root.right)

    in_order(self.root)
    pass

  def search(self, data)-> BinaryNode:
    temp = self.root
    while temp:
      if temp.data == data: return temp
      elif temp.data > data: temp = temp.left
      else: temp = temp.right

    return None

  '''
  serialize Tree
  O(N) time complexity
  '''
  def serialize(self)->str:
    def serialize(node, result: str)-> str:
      if not node:
        return ")"

      return result + str(node.data) + serialize(node.left, result) + serialize(node.right, result)
    return serialize(self.root, "")

  '''
    deserialize tree
    O(N) time complexity
  '''
  @classmethod
  def deserialize(cls, result):
    def deserialize(result, idx):
      if result[idx] == ')':
        return None, idx

      node = BinaryNode(result[idx])
      node.left, idxl = deserialize(result, idx+1)
      node.right, idxlr = deserialize(result, idxl+1)

      return node, idxlr

    return deserialize(result, 0)

  '''
    CTC: 4.2
    Time Complexity : O(N)
  '''
  @classmethod
  def createMininalBST(cls, input: list)-> BinaryNode:
    def createMinBST(input, start, end):
      if end < start:
        return None
      mid = (start + end) // 2
      node = BinaryNode(input[mid])
      node.left = createMinBST(input, start, mid-1)
      node.right = createMinBST(input, mid+1, end)
      return node

    return createMinBST(input, 0, len(input)-1)

  '''
    CTC: 4.3 : store list of child at each level in linklist
    time Complex: O(N) space: O(N) queue
  '''
  def tree_list_depth(self)->list:
    queue = deque()
    queue.append(self.root)
    result: list = []
    while(len(queue) > 0):
      node_count = len(queue)
      current_linklist = deque()
      while(node_count > 0):
        node = queue.popleft()
        current_linklist.append(node)
        if node.left: queue.append(node.left)
        if node.right: queue.append(node.right)
        node_count -= 1
      result.append(current_linklist)
    return result

if __name__ == '__main__':
  items: list = [4, 2, 1, 5, 3]
  tree = BST()
  tree.create_bst_from_list(items)
  tree.in_order_recursive()
  print(tree.search(7))
  result = tree.serialize()
  print(result)
  tree1 = BST()
  tree1.copy(BST.deserialize(result)[0])
  tree1.in_order_recursive()
  input = [0,1,2,3,4,5,6,7,8,9]
  tree_node = BST.createMininalBST(input)
  tree1 = BST()
  tree1.root = tree_node
  print()
  print(tree1.serialize())
  result = tree1.tree_list_depth()
  for item in result:
    for elem in item:
      print(elem, end=" ")
  #print(BST.serialize_cls(tree_node))



