import sys

'''
/* Time Complexity = O(N^2)
	 * Space Complexity = O(1) Constant
	 * Bubble sort do two pass algorithm, and compare its neighbor every time and swap
	 * if it is greater, hence with every pass the largest element is fixed at the end of the array.
	 * Performance enhancement , if at any point if the array is sorted
	 * we don't need to go further and can break out early.
	 */
'''
def bubble_sort(arr: list):
  for i in range (len(arr)):
    sorted = False
    for j in range(len(arr) - i - 1):
      if (arr[j] > arr[j + 1]):
        arr[j], arr[j + 1] = arr[j + 1], arr[j] # swap postion
        sorted = True

    # list is already sorted now
    if not sorted:
      return arr

  return arr

'''
Time Complexity = O(N2)
best case O(N) if sorted
Insertion sort takes maximum time to sort if elements are sorted in reverse order.
And it takes minimum time (Order of n) when elements are already sorted.
/*
	 * Simulate that you are sorting while inserting to array, we do insertion from back of array instead of front.
	 * Time Complexity: O(n^2) and best case it is O(N) if the array is already sorted.
	 * Space Complexity: O(1)
	 */
'''
def insertion_sort(arr: list):
  for i in range (1, len(arr)):
    key = arr[i]
    j = i-1
    while(j >=0 and key < arr[j]):
      arr[j+1] = arr[j]
      j -= 1

    # put key in right position
    a[j+1] = key

  return arr

'''
	/*
	 * Use Quick Select Partition algorithm
	 * Time Complexity = O(NlogN) it dividing the data in half makes it tree type structure ..
	 *  each level take n operation and height of tree is logN hence it is NlogN.
	 * Space Complexity = O(1)
	 */
'''
def quick_sort(arr: list, low, high):
  '''
   * Partition the data by pivot and fix the position of pivot element.
	 * Time Complexity: O(N) operation; O(high-low) to be precise.
  '''
  def partition(arr, low, high):
    pivot = arr[high]
    wall = low - 1

    for i in range(low, high):
      # If current element is smaller than or
      # equal to pivot
      if arr[i] <= pivot:
        #swap with wall
        wall += 1
        arr[wall], arr[i] = arr[i], arr[wall]

    arr[wall + 1], arr[high] = arr[high], arr[wall + 1]
    return wall + 1

  if len(arr) == 1:
    return arr
  if low < high:

    # pi is partitioning index, arr[p] is now
    # at right place
    pi = partition(arr, low, high)

    # Separately sort elements before
    # partition and after partition
    quick_sort(arr, low, pi-1)
    quick_sort(arr, pi+1, high)

def merge_sort(arr):
  if len(arr) > 1:
    # finding mid element
    mid = len(arr) // 2

    # Left array
    left_arr = arr[:mid]

    #right array
    right_arr = arr[mid:]

    # merge sort on left array
    merge_sort(left_arr)

    #merge sort on right array
    merge_sort(right_arr)

    left = right = cur = 0

    while left < len(left_arr) and right < len(right_arr):
      if left_arr[left] <= right_arr[right]:
        arr[cur] = left_arr[left]
        left += 1
      else:
        arr[cur] = right_arr[right]
        right += 1

      cur += 1

    while left < len(left_arr):
      arr[cur] = left_arr[left]
      cur += 1
      left += 1

    while right < len(right_arr):
      arr[cur] = right_arr[right]
      cur += 1
      right += 1

''' CTC 10.1
Time Complexity O(N)
'''
def merge_two_sorted_arrey(a:list, b: list):
  idx_a = len(a) - 1
  idx_b = len(b) - 1
  idx_merge = len(a) + len(b) - 1

  while idx_b:
    if idx_a and a[idx_a] > b[idx_b]:
      a[idx_merge] = a[idx_a]
      idx_a -= 1
    else:
      a[idx_merge] = b[idx_b]
      idx_b -= 1

    idx_merge -= 1

''' CTC 10.2 group all the anagrams together
Time Complexity: O(NMlogM) m is avg length of string of word and N is lengths of list words
Space: O(NM) n is number of words and m in avg length of words
'''
def group_anagrams(words_list: list):
  sorted_list = [''.join(sorted(word)) for word in words_list]

  hashmap = {}
  result = []
  # construct a dictionary where the key is each sorted word,
  # and value is a list of elements
  for i, e in enumerate(sorted_list):
    hashmap.setdefault(e, []).append(sorted_list[i])

  # traverse the dictionary and read indices for each sorted key.
  # The anagrams are present in the actual list at those indices
  for index in hashmap.values():
    result += index

  return result

''' CTC 10.5 search a string in sorted array of word havig empty strings as well
if we find mid element empty then look for non-empty element and do normal binary search
Time Complexity: o(N) + O(logN)
'''
def search_sorted_array_with_empty_strings(words: list, target: str, left, right):
  if left > right : return -1

  mid = (left + right) // 2

  # check if string is empty
  if not words[mid]:
    l = mid - 1
    r = mid + 1

    while(True):
      if l < left and r > right: return -1
      elif not words[l]:
        mid = l
        break
      elif not words[r]:
        mid = r
        break

      l += 1
      r += 1

  # Do normal binary search now
  if words[mid] == target:
    return mid
  elif words[mid] > target:
    return search_sorted_array_with_empty_strings(words, target, left, mid - 1)
  else:
    return search_sorted_array_with_empty_strings(words, target, mid + 1, right)

''' CTC 10.11 Peaks and Valley
Time Complexity O(N)
take group of 3 elements and fix them up where middle element should be greater than adjecent..
'''
def sort_valley_peak(elements: list):
  def MaxIndex(elem: list, a, b, c):
    size = len(elem)
    a_val = elem[a] if a >= 0 and a < size else -sys.maxsize
    b_val = elem[b] if b >= 0 and b < size else -sys.maxsize
    c_val = elem[c] if c >= 0 and c < size else -sys.maxsize

    max_elem = max(a_val, max(b_val, c_val))
    return a if max_elem == a_val else b if max_elem == b_val else c

  for i in range(1, len(elements), 2):
    biggest_number_index = MaxIndex(elements, i, i-1 , i+1)
    if i != biggest_number_index:
      elements[i], elements[biggest_number_index] = elements[biggest_number_index], elements[i] # swap both index


''' 10.4 Search in sorterd array without given size of array
first find the size of array in O(log n) from low to high
then search using binary search
'''
def search_binary(lst: list, target: int):
  def binary_search(lst, target, low, high):
    while low <= high:
      mid = (low + high) // 2
      if lst[mid] > target or lst[mid] == -1:
        high = mid - 1
      elif lst[mid] < target:
        low = mid + 1
      else:
        return mid
    return -1

  idx = 1
  while list[idx] != -1 and lst[idx] < target:
    idx *= 2

  return binary_search(list, target, idx/2, idx)

''' 10.3 Search in sorted rotated array.
'''
def search_rotated_array(arr: list, left: int, right: int , target: int):
  mid = (left + right) // 2
  if arr[mid] == target:
    return mid

  if right < left :
    return -1

  ''' Either the left or right half must normally ordered. Find out which side is normally ordered.
      user normally order side to figure out which side to search to find target.
      Time Complexity = O(log N)
  '''
  if arr[left] < arr[mid]:  # left is normally ordered
    if arr[left] <= target and arr[mid] > target:
      return search_rotated_array(arr, left, mid-1, target)
    else:
      return search_rotated_array(arr, mid+1, right, target)
  elif arr[mid] < arr[left]: # right is normally ordered
    if arr[mid] <= target and arr[right] > target:
      return search_rotated_array(arr, mid+1, right, target) # search right
    else:
      return search_rotated_array(arr, left, mid-1, target) # search left
  elif arr[mid] == arr[left]: # left and right all are repeat
    if arr[mid] != arr[right]: # all right are different
      return search_rotated_array(arr, mid+1, right, target) # search on right side
    else:
      result = search_rotated_array(arr, left, mid-1, target)
      if result == -1:
        return search_rotated_array(arr, mid+1, right, target)
      return result
  return -1


if __name__ == '__main__':
  dict = {}
  words = ['cat', 'hello', 'oby', 'act', 'yob']

  print(group_anagrams(words))

