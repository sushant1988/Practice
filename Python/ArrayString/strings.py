from functools import reduce

''' Find if string has unique elements CTC 1.1
Time complexity  O(N)
    Space Complexity O(N)
'''
def find_string_is_unique_hashmap(input: str) -> bool:
  hash_map = {}
  for char in input:
    if char in hash_map:
      return False
    hash_map[char] = 1

  return True

'''
'''
def find_string_is_unique_bitvector(input: str) -> bool:
  hash_map: int = 0
  for char in input:
    bit_index = ord(char) - ord("0")
    if (hash_map >> bit_index & 1) > 0:
      return False
    hash_map = hash_map | (1 << bit_index)

  return True

''' Find if two string are permutation each other CTC 1.2
    Sort: time O(NlogN) + O(NlogN) + O(N) for compare
    Space : Constant O(1)
'''
def two_string_is_permuatation_sort(input1: str, input2:str):
  res1 = ''.join(sorted(input1))  # sort string

  res2 = lambda z: reduce(lambda x, y: x + y, sorted(z)) if z != "" else ""

  if res1 != res2(input2):
    return False
  return True

''' Find if two string are permutation each other CTC 1.2
    using hash map extra Space O(N)
    time complexity = O(N)
'''
def two_string_is_permuatation_hashmap(input1: str, input2:str):
  hash_map = {}
  for char in input1:
    if char in hash_map:
      hash_map[char] += 1
    else:
      hash_map[char] = 1

  for char in input2:
    if char in hash_map:
      hash_map[char] -= 1
      if hash_map[char] < 0 : return False
    else:
       return False

  return True

''' CTC 1.4
Time Complexity = O(N)
Space complexity = O(1)
'''
def is_permutation_of_palindrome_bit_vector(input: str):
  def toggle(bit_vector: int, index: int):
    mask: int = 1 << index
    if(bit_vector & mask) > 0:
      bit_vector &= ~mask
    else:
      bit_vector |= mask
    return bit_vector

  bit_map: int = 0
  for char in input:
    if char != "":
      x = ord(char) - ord("0")
      bit_map = toggle(bit_map, x)

  return bit_map == 0 or (bit_map & (bit_map - 1)) == 0  #   if there is one single bit set if n & n-1 == 0

''' CTC 1.4
Time Complexity = O(N) CTC
space complexity = O(N)
'''
def is_permutation_of_palindrome_has_map(input: str):
  hash_map: dict(str, int) = {}
  count_odd = 0
  for char in input:
    if ord(char) != '':
      if char in hash_map:
        hash_map[char] += 1
      else:
        hash_map[char] = 1
      if hash_map[char] % 2 == 1:
        count_odd += 1
      else:
        count_odd -= 1

  return count_odd <= 1

''' CTC 1.5
    Time COmplexity = O(N)
'''
def check_if_string_one_edit_away(input: str, edit: str):
  def check_insert(input: str, edit: str):
    idx1 = 0
    idx2 = 0

    while(idx1 < len(input) and idx2 < len(edit)):
      if input[idx1] != edit[idx2]:
        if idx1 == idx2:
          idx1 += 1
        else:
          return False
      idx1 += 1
      idx2 += 1

    return True


  def check_replacement(input: str, edit: str):
    idx1 = 0
    idx2 = 0
    done_replacement: bool = False
    while(idx1 < len(input) and idx2 < len(edit)):
      if input[idx1] != edit[idx2]:
        if not done_replacement:
          done_replacement = True
        else:
          return False
      idx1 += 1
      idx2 += 1

    return True


  input_size = len(input)
  edit_size = len(edit)

  if input_size - edit_size == 1:
    return check_insert(input, edit)
  elif input_size == edit_size:
    return check_replacement(input, edit)
  elif edit_size - input_size == 1:
    return check_insert(edit, input)  # swap input values

  return False

''' String Compresion CTC 1.6

'''
def string_compression(input: str):
  res = ""
  idx = 1
  count = 1
  while idx < len(input):
    if input[idx] != input[idx-1]:
      res += input[idx-1] + str(count)
      count = 0

    count += 1
    idx += 1

  res += input[idx -1] + str(count)

  if len(res) >= len(input):
    return input

  return res

'''
permutation of string
Time Complexity: O(N!)
'''
def permutation_of_elements(input: str):
  results = []
  def permutation(input: list, l, r):
    if l == r:
      results.append(list(input))
      return

    for i in range(l, r):
      input[l], input[i] = input[i], input[l] # swap the position
      permutation(input, l+1, r)
      input[l], input[i] = input[i], input[l] # backtrack

  permutation(list(input), 0, len(input))
  return ["".join(p) for p in results]



if __name__ == '__main__':
  input1 = 'sadasd'
  input2 = "sadasdr"
  print(two_string_is_permuatation_hashmap(input1, input2))

  print(is_permutation_of_palindrome_bit_vector("abbc"))

  print(check_if_string_one_edit_away("pale", "pele"))

  print(string_compression("aaabbccaa"))

  print(permutation_of_elements('ABC'))

  pass