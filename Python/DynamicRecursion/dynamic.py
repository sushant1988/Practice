

''' CTC 8.1
time complexity = O(N)
Space Complexity = O(N)
'''
def count_ways(steps: int, memo: dict):
  if steps < 0 :
    return 0
  elif steps == 0:
    return 1
  elif steps in memo:
    return memo.get(steps)
  else:
    memo[steps] = count_ways(steps - 1, memo) + count_ways(steps - 2, memo) + count_ways(steps - 3, memo)
    return memo[steps]

  return 0

''' CTC 8.2
Time Complexity: O(NM)
'''
def get_path_in_grid(maze: list):
  def get_path(maze: list, row: int, col: int, path: list, visited: dict):
    if row < 0 or col < 0 or maze[row][col] == 1 or (row, col) in visited:
      return False

    is_origin: bool = True if row == 0 and col == 0 else False
    if is_origin or get_path(maze, row-1, col, path, visited) or get_path(maze, row, col-1, path, visited):
      path.append((row, col))
      return True

    visited[(row, col)] = 1
    print(visited)
    return False

  if len(maze) == 0 or len(maze[0]) == 0:
    return None
  path = []
  N = len(maze)
  M = len(maze[0])
  visited: dict = {}
  if get_path(maze, N-1, M-1, path, visited):
    return path


''' CTC 8.11 recursive
denoms = [25, 10, 5, 1]
'''
def make_change_dynamic(amount: int):
  def _make_change_dynamic(amount: int, denoms: list, idx: int, hash_map: dict):
    if hash_map[amount][idx] > 0:
      return hash_map[amount][idx]

    if idx >= len(denoms) -1 : return 1
    denom_amount = denoms[idx]
    ways = 0
    i = 0
    while (i * denom_amount) <= amount:
      ways += _make_change_dynamic(amount - (i * denom_amount), denoms, idx + 1, hash_map)
      i += 1

    hash_map[amount][idx] = ways
    return ways

  d = [25, 10, 5, 1]
  hm = [[0] * len(d) for i in range(amount + 1)]
  return _make_change_dynamic(amount, d, 0, hm)


if __name__ == '__main__':
  memo={}
  #print(count_ways(100, memo))
  grid = [[0, 1, 1, 1], [0, 0, 1, 1], [0, 0, 1, 1], [1, 0, 0, 0]]
  print(get_path_in_grid(grid))
  print(make_change_dynamic(100))
  pass