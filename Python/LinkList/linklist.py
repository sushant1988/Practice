from collections import deque

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

  # print link list
  def __str__(self):
    data=""
    temp = self.head
    while(temp is not None):
      data += str(temp.data) + "->"
      temp = temp.next

    return data[:-2]

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
      fast: LinkList = self.head.next

      while(fast is not None and fast.next is not None):
        if (slow == fast or fast.next == slow):
          return True
        slow = slow.next
        fast = fast.next.next

    return False

  ''' Time Complexity = O(1)
      Space Complexity = Constant
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


  ''' Partition linklist by x  CTC 2.4
  '''
  def partition_linklist(self, x):
    head: LinkList = self.head
    tail: LinkList = self.head
    temp:LinkList = self.head

    while(temp is not None):
      next: LinkList = temp.next
      if(temp.data < 5):
        temp.next = head
        head = temp
      else:
        tail.next = temp
        tail = temp
      temp = next
    tail.next = None
    self.head = head
    pass

  ''' Palindrome : linklist  CTC 2.6
      find middle element using fast slow pointer and store in stack and
      then compare second half of linklist with stack
      space(O(N/2)) and time O(N)
  '''
  def is_palindrome(self) -> bool:
    fast: LinkList = self.head
    slow: LinkList = self.head

    stack: deque = deque()
    while(fast is not None and fast.next is not None):
      stack.append(slow.data)
      fast = fast.next.next
      slow = slow.next

    if fast is not None:
      slow = slow.next

    while (slow is not None):
      if slow.data != stack.pop():
        return False
      slow = slow.next

    return True

  ''' Find Intersection between two different length linklist CTC 2.7
      Time = O(2(N) + 2(M)), Space = Constant
  '''
  @classmethod
  def find_intersection(cls, link1, link2):
    temp1: LinkList = link1.head
    temp2: LinkList = link2.head

    link1_len = 0
    while(temp1 is not None):
      link1_len += 1
      temp1 = temp1.next

    link2_len = 0
    while(temp2 is not None):
      link2_len += 1
      temp2 = temp2.next

    diff = abs(link1_len - link2_len)
    temp1 = link1.head
    temp2 = link2.head
    if(link2_len > link1_len):
      while(diff > 0):
        temp2 = temp2.next
        diff -= 1
    else:
      while(diff > 0):
        temp1 = temp1.next
        diff -= 1

    while(temp1 is not None and temp2 is not None):
      if (temp1 == temp2):
        return temp1
      temp1 = temp1.next
      temp2 = temp2.next

    return None

  ''' Add two linklist with different length [1 -> 2 -> 3] and [4 -> 3]  123 + 43 =  
  '''
  @classmethod
  def add_two_linklist(cls, link1, link2):
    pass



