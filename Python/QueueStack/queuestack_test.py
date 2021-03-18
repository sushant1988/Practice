import unittest
from queuestack import *

class QueueStackTest(unittest.TestCase):
  def test_fn_stack_with_min(self):
    items : list = [5, 8, 4, 3, 2, 2, 6, 1, 7]
    stack: StackWithMin = StackWithMin()

    expected: list = [5, 5, 4, 3, 2, 2, 2, 1, 1]
    for idx, item in enumerate(items):
      stack.push(item)
      self.assertEqual(stack.min(), expected[idx])

    idx = -1
    for item in reversed(expected):
      self.assertEqual(stack.min(), item)
      self.assertEqual(stack.pop(), items[idx])
      idx -= 1
    pass

  def test_fn_my_queue(self):
    items : list = [5, 8, 4, 3, 2, 2, 6, 1, 7]
    queue: MyQueue = MyQueue()

    for item in items:
      queue.push(item)

    idx = 0
    while(not queue.is_empty()):
      self.assertEqual(queue.pop(), items[idx])
      idx += 1
    pass

  def test_fn_sort_stack(self):
    items : list = [5, 8, 4, 3, 2, 2, 6, 1, 7]
    stack: StackWithMin = StackWithMin()
    for item in items:
      stack.push(item)

    st = sort_stack(stack)
    expected: list = [1, 2, 2, 3, 4, 5, 6, 7, 8]
    for item in expected:
      self.assertEqual(st.pop(), item)


if __name__ == '__main__':
  unittest.main()