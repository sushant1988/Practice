from collections import deque

class LinkListNode:
  def __init__(self, data):
      self.data = data
      self.next = None

  def print(self):
    temp = self
    while temp:
      print(temp.data, end="->")
      temp = temp.next

  def to_list(self) -> list:
    result = []
    temp = self
    while temp:
      result.append(temp.data)
      temp = temp.next

    return result

class LinkList:
  def __init__(self):
      self.head = None
      self.rear = None

  @classmethod
  def to_list(cls, linklist):
    temp: LinkList = linklist.head
    lst = []
    while temp:
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
    while temp:
      data += str(temp.data) + "->"
      temp = temp.next

    return data[:-2]

  def find(self, data):
    temp = self.head
    while temp and temp.data != data:
      temp = temp.next

    return temp

  def to_list(self):
    temp = self.head
    lst = []
    while temp:
      lst.append(temp.data)
      temp = temp.next

    return lst

  def length(self):
    temp = self.head
    length = 0
    while temp:
      length += 1
      temp = temp.next

    return length

  ''' Mth to Last Element in LinkList PIE Page 50
      Time Complexity: O(N)
      Space Complexity: O(1)
  '''
  def find_mth_from_last_element(self, M: int):
    p1: LinkList = self.head
    p2: LinkList = self.head

    count = 0
    while p1 and count < M:
      p1 = p1.next
      count += 1

    if count < M:
      return None

    while p1:
      p2 = p2.next
      p1 = p1.next

    return p2.data

  ''' Find Circular LinkList
      Time Complexity: O(N)
      Space Complexity: O(1) Constant
  '''
  def is_circular_list(self) -> bool:
    if self.head:
      slow: LinkList = self.head
      fast: LinkList = self.head.next

      while fast and fast.next:
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

    while next:
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

    while temp:
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
    while fast and fast.next:
      stack.append(slow.data)
      fast = fast.next.next
      slow = slow.next

    if fast:
      slow = slow.next

    while slow:
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
    while temp1:
      link1_len += 1
      temp1 = temp1.next

    link2_len = 0
    while temp2:
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

    while temp1 and temp2:
      if (temp1 == temp2):
        return temp1
      temp1 = temp1.next
      temp2 = temp2.next

    return None

  ''' Add two linklist with different length [1 -> 2 -> 3] and [4 -> 3]  123 + 43 =
      limitation: can add number that can be represented by data type
  '''
  @classmethod
  def add_two_linklist(cls, link1, link2):
    l1 = link1.head
    l2 = link2.head

    s1 = s2 = 0
    while l1 or l2:
      if l1:
        s1 = s1 * 10 + l1.data
        l1 = l1.next
      if l2:
        s2 = s2 * 10 + l2.data
        l2 = l2.next

    s = s1 + s2

    link_nw = LinkList()
    while(s > 0):
      link_nw.insert_at_front(s%10)
      s = s//10

    return link_nw

  # add linklist of equal length  recursive
  @classmethod
  def add_two_linklist_equal_length(cls, head1: LinkListNode, head2: LinkListNode) -> (int, LinkListNode):
    if not head1 and not head2:
      return 0, None

    carry, prev_node = LinkList.add_two_linklist_equal_length(head1.next, head2.next)

    val = carry + head1.data + head2.data
    cur_node = LinkListNode(val % 10)
    cur_node.next = prev_node
    nw_carry = val // 10

    return nw_carry, cur_node

  # propogate carry from remaining part of lengthy linklist
  @classmethod
  def propogate_carry(cls, head: LinkListNode, end_node: LinkListNode, node_to_attach: LinkListNode, org_carry: int):
    if head.next == end_node:
      val = org_carry + head.data
      new_node = LinkListNode(val % 10)
      new_node.next = node_to_attach
      return val // 10, new_node

    prev_carry, prev_node = LinkList.propogate_carry(head.next, end_node, node_to_attach, org_carry)

    val = prev_carry + head.data
    cur_node = LinkListNode(val % 10)
    cur_node.next = prev_node

    return val // 10, cur_node

  ''' No Extra Space

  '''
  @classmethod
  def add_two_linklist_variable(cls, link1, link2):
    head1 = link1.head
    head2 = link2.head

    len1 = link1.length()  # O(N)
    len2 = link2.length() # O(N)

    carry, new_node = 0, None
    if (len2 == len1):
      carry, new_node = LinkList.add_two_linklist_equal_length(temp, head2) # O(N)
    else:
      # always first head1 is greater than head2 otherwise swap
      diff = abs(len1 - len2) # O(Diff)
      if len2 > len1:
        temp = head1
        head1 = head2
        head2 = head1

      last_node_long_list = temp = head1

      while diff > 0:
          temp = temp.next
          last_node_long_list = temp
          diff -= 1

      new_carry, node = LinkList.add_two_linklist_equal_length(temp, head2) # O(N)
      carry, new_node = LinkList.propogate_carry(head1, last_node_long_list, node, new_carry) # O(Diff)

    if carry > 0:
      nw_node = LinkListNode(carry)
      nw_node.next = new_node
      new_node = nw_node

    return new_node




