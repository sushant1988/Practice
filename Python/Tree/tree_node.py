class BinaryNode:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None


class N_AryNode:
  def __init__(self, data):
    self.data = data
    self.child: list = None