from collections import deque
from queue import Queue
import sys

''' Implement stack with Min element at any time
CTC 3.2
'''
class StackWithMin:
  stack_min: deque = deque  # doubly linklist has all list operations
  stack_item: Queue = None   # FIFO Queue

  def __init__(self):
    self.stack_item = Queue()

  def put(self, element):
    self.stack_item.put(element)
    if element <= self.min():
      self.stack_min.append(element)

  def pop(self):
    pop_element = self.stack_item.get()
    if pop_element == min():
      self.stack_min.pop()

  def min(self):
    if len(self.stack_min) == 0:
      return sys.maxsize

    return self.stack_min[-1]

  def peek(self):
    if(len(self.stack_item) != 0):
      return self.stack_item[-1]

    else return None

  def is_empty(self):
    return len(self.stack_item) == 0


''' MyQueue implement queue two stacks
CTC 3.4
'''
class MyQueue:
  stack_new: deque = None
  stack_old: deque = None
  def __init__(self):
    self.stack_new = deque()
    self.stack_old = deque()

  def size(self):
    return len(self.stack_new) + len(self.stack_old)

  # push always to new stack
  def push(self, data):
    self.stack_new.append(data)

  def pop(self):
    self.stack_shift()
    self.stack_old.pop()

  def stack_shift(self):
    if len(self.stack_old) == 0:
      # pop from new stack and push to old stack
      while(len(self.stack_new) != 0):
        self.stack_old.append(self.stack_new.pop())

  def peek(self):
    self.stack_shift()
    self.stack_old[-1]

  def is_empty(self):
    return self.size() == 0

'''Sort stack with smallest item on top of stack
CTC 3.5
time complexity:O(N2)
space: O(N)
'''
def sort_stack(stack: StackWithMin):
  r = StackWithMin()
  while(not stack.is_empty()):
    tmp = stack.pop()
    while(not r.is_empty() and r.peek() > tmp):
      stack.push(r.pop())

    r.push(tmp)

  #move everything from r to s
  while(not r.is_empty()):
    stack.push(r.pop())

