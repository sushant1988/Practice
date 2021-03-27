class BinaryNode:
  def __init__(self, data):
    self.data = data
    self.left = self.right = None

  def __str__(self):
    return str(self.data)


class N_AryNode:
  def __init__(self, data):
    self.data = data
    self.child: list = None

  def __str__(self):
    return str(self.data)