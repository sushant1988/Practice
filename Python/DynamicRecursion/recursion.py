import copy

''' CTC 8.2
Time Complexity: O(2^N+M)
'''
def get_path_in_grid_recursive(maze: list):
  def get_path(maze, row, col, path):
    if row < 0 or col < 0 or maze[row][col] == 1:
      return False

    is_origin: bool = True if row == 0 and col == 0 else False
    if is_origin or get_path(maze, row-1, col, path) or get_path(maze, row, col-1, path):
      path.append((row, col))
      return True

    return False

  if len(maze) == 0 or len(maze[0]) == 0:
    return None
  path = []
  N = len(maze)
  M = len(maze[0])
  if get_path(maze, N-1, M-1, path):
    return path

''' CTC 8.3
    recusively search on both left and right but we can skip bunch of elements
    A[5] = 3 as list is sort and A[4] can never be magic index so on left we need
    to find element from A[0].. A[3] and vice versa on right side
'''
def find_magic_index(arr: list):
  def magic_index(arr, left, right):
    if right < left:
      return -1
    mid = (right + left) // 2
    if arr[mid] == mid:
      return mid

    # search on left
    left_index = min(mid-1, arr[mid])
    l = magic_index(arr, left, mid-1)
    if l >= 0: return l
    right_index = max(mid + 1, arr[mid])
    return magic_index(arr, right, mid+1)

''' CTC 8.4
    create all subset of elements in list
    time complexity = O(2^N)
'''
def subset_of_all_string(input: list):
  N = len(input)
  subset = []
  for i in range(0, 2 ** N):
    val = []
    temp = i
    j = 0
    while temp:
      if temp & 1 >= 1:
        val.append(input[j])
      temp >>= 1
      j += 1
    subset.append(val)
  return subset

''' CTC 8.5
    permutation of string
    time complexity: O(N!)
'''
def permuation_of_string(input: list):
  def permutation(input: list, swap_idx: int, result: list):
    if swap_idx == len(input)-1:
      result.append(input[:])

    for i in range (swap_idx, len(input)):
      #swap Index
      input[swap_idx], input[i] = input[i], input[swap_idx]
      permutation(input, swap_idx + 1, result)
      # swap back
      input[swap_idx], input[i] = input[i], input[swap_idx]

  result = []
  permutation(input, 0, result)
  return result

''' CTC
Time Complexity : O(2 ^ N) as recursively going into two directions
'''
def generate_parenthesis(param_size: int):
  def _parenthesis(open, close, op_string, result):
    if open == 0 and close == 0:
      result.append(op_string)
      return

    if open > 0:
      op_string_new = op_string + "("
      _parenthesis(open-1, close, op_string_new, result)

    if close > open:
      op_string_new = op_string + ")"
      _parenthesis(open, close-1, op_string_new, result)

    pass

  result = []
  op_string = ""
  open = param_size
  close = param_size
  _parenthesis(open, close, op_string, result)
  return result

''' CTC 8.11 recursive
denoms = [25, 10, 5, 1]
'''
def make_change_recursive(amount: int):
  def _make_change_recursive(amount: int, denoms: list, idx: int):
    if idx >= len(denoms) -1 : return 1
    denom_amount = denoms[idx]
    ways = 0
    i = 0
    while (i * denom_amount) <= amount:
      ways += _make_change_recursive(amount - (i * denom_amount), denoms, idx + 1)
      i += 1

    return ways
  return _make_change_recursive(amount, [25, 10, 5, 1], 0)

if __name__ == '__main__':
  grid = [[0, 0, 1, 1], [1, 0, 1, 0], [1, 0, 0, 0], [1, 1, 1, 0]]
  print(get_path_in_grid_recursive(grid))
  print(subset_of_all_string(['A', 'B', 'C', 'D']))
  print(permuation_of_string(['A', 'B', 'C', 'D']))
  print(generate_parenthesis(3))
  print(make_change_recursive(100))

  pass