class LinkListNode:
  def __init__(self, data):
      self.data = data
      self.next = None

class LinkList:
  def __init__(self):
      self.head = None
      self.rear = None

  @classmethod
  def to_list(cls, linklist):
    temp: LinkList = linklist.head
    lst = []
    while(temp is not None):
      lst.append(temp.data)
      temp = temp.next

    return lst

  # reverse linklist
  @classmethod
  def reverse_recursive_linklist(cls, head):
    if head.next is None:
      return head

    new_head = LinkList.reverse_recursive_linklist(head.next)
    head.next.next = head
    head.next = None

    return new_head

  def insert_at_front(self, data):
    new_node = LinkListNode(data)
    if self.head is None:
        self.head = new_node
        self.rear = self.head
    else:
        new_node.next = self.head
        self.head = new_node

  def insert_at_rear(self, data):
    new_node = LinkListNode(data)
    if self.rear is None:
        self.head = self.rear = new_node
    else:
        self.rear.next = new_node
        self.rear = new_node

  def print_linklist(self):
    temp = self.head
    print("[", end=" ")
    while(temp is not None):
        print(temp.data, end=" ")
        temp = temp.next
    print("]")

  def print_linklist(self):
    temp = self.head
    print("[", end=" ")
    while(temp is not None):
        print(temp.data, end=" ")
        temp = temp.next
    print("]")

  def find(self, data):
    temp = self.head
    while(temp is not None and temp.data != data):
      temp = temp.next

    return temp

  def to_list(self):
    temp = self.head
    lst = []
    while(temp is not None):
      lst.append(temp.data)
      temp = temp.next

    return lst

  ''' Mth to Last Element in LinkList PIE Page 50
      Time Complexity: O(N)
      Space Complexity: O(1)
  '''
  def find_mth_from_last_element(self, M: int):
    p1: LinkList = self.head
    p2: LinkList = self.head

    count = 0
    while(p1 is not None and count < M):
      p1 = p1.next
      count += 1

    if count < M:
      return None

    while(p1 is not None):
      p2 = p2.next
      p1 = p1.next

    return p2.data

  ''' Find Circular LinkList
      Time Complexity: O(N)
      Space Complexity: O(1) Constant
  '''
  def is_circular_list(self) -> bool:
    if self.head is not None:
      slow: LinkList = self.head
      fast: LinkList = self.head

      while(fast is not None and fast.next is not None):
        if (slow == fast or fast.next == slow):
          return True
        slow = slow.next
        fast = fast.next.next

    return False

  ''' Time Complexity = O(1)
  '''
  def reverse_iterative_linklist(self):
    prev: LinkList = None
    cur: LinkList = self.head
    next: LinkList = self.head.next

    while(next is not None):
      cur.next = prev
      prev = cur
      cur = next
      next = next.next

    cur.next = prev
    self.head = cur
    pass








