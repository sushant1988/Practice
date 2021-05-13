import sys
import heapq

MAX_INT = sys.maxsize
# Min & Max Heap
class Heap:
  def __init__(self, max_heap: bool = False):
    self.bucket = []
    self.max_heap = max_heap

  def build_heap(self, input: list):
    for x in input:
      self.bucket.append(x)

    for i in range (0, len(self.bucket)// 2):
      self.heapify(i)

  def parent(self, idx: int):
    return idx // 2

  def left_child(self, idx: int):
    return idx * 2 + 1 if (idx * 2 + 1) < len(self.bucket) else -1

  def right_child(self, idx: int):
    return idx * 2 + 2 if (idx * 2 + 2) < len(self.bucket) else -1

  def heapify(self, idx: int):
    left_child = self.left_child(idx)
    right_child = self.right_child(idx)

    # find out of 3 variable
    swap_idx = idx
    if self.max_heap:
      # if left_child != -1 and self.bucket[parent] < self.bucket[left_child]:
      #   parent = left_child
      # if right_child != -1 and self.bucket[parent] < self.bucket[right_child]:
      #   parent = right_child
      swap_idx = max([idx, left_child, right_child], key=lambda x: self.bucket[x] if x != -1 else -(MAX_INT))
    else:
      swap_idx = min([idx, left_child, right_child], key=lambda x: self.bucket[x] if x != -1 else MAX_INT)

    if swap_idx != idx:
      #swap
      self.bucket[swap_idx], self.bucket[idx] = self.bucket[idx], self.bucket[swap_idx]
      self.heapify(swap_idx)

  def pop(self):
    if len(self.bucket) > 0:
      #swap with last element
      self.bucket[len(self.bucket)-1], self.bucket[0] = self.bucket[0], self.bucket[len(self.bucket)-1]
      return self.bucket.pop()

  def peek(self):
    if len(self.bucket) > 0:
      return self.bucket[0]
    return None

'''
Find K largest element
Time Complexity : O(K) + O((N-K)logK)
Space COmplexity: O(K)
'''
def find_K_largest_element(input: list, K: int):
  min_heap = []

  # create heap of size K
  for i in range(0, K):
    min_heap.append(input[i])

  # convert into a min heap
  heapq.heapify(min_heap)

  for i in range (K, len(input)):
    if min_heap[0] < input[i]:  # if less then replace with min element
      min_heap[0] = input[i]
      heapq.heapify(min_heap)

  return min_heap

if __name__== '__main__':
  heap = Heap(True)
  heap.build_heap([3, 1, 9, 5, 4])
  print(heap.pop())
  print(find_K_largest_element([3, 1, 9, 5, 4, 10, 2, 7, 6], 4))
