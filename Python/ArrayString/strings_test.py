import unittest
from strings import *

class StringsTest(unittest.TestCase):
  def test_fn_find_string_is_unique(self):
    string_list = ['string', '', 'aacbd', 'cdeff', 'abcdef']
    expected_output = [True, True, False, False, True]

    count: int = 0
    for item in string_list:
      self.assertEqual(find_string_is_unique_hashmap(item), expected_output[count])
      count += 1

    count = 0
    for item in string_list:
      self.assertEqual(find_string_is_unique_bitvector(item), expected_output[count])
      count += 1
    pass

  def test_fn_find_string_is_permuatation(self):
    string1_list = ['string', '', 'aacbd', 'cdeff', 'abcdef']
    string2_list = ['gnirts', '', 'aabde', 'sads', 'fedcba']
    expected_output = [True, True, False, False, True]

    count: int = 0
    for item in string1_list:
      self.assertEqual(two_string_is_permuatation_sort(item, string2_list[count]), expected_output[count])
      count += 1

    count = 0
    for item in string1_list:
      self.assertEqual(two_string_is_permuatation_hashmap(item, string2_list[count]), expected_output[count])
      count += 1
    pass

  def test_fn_is_permutation_of_palindrome(self):
    string_list = ['aabbc', '', 'aabdd', 'accbad', 'cabd']
    expected_output = [True, True, True, False, False]

    count: int = 0
    for item in string_list:
      self.assertEqual(is_permutation_of_palindrome_bit_vector(item), expected_output[count])
      count += 1

    count = 0
    for item in string_list:
      self.assertEqual(is_permutation_of_palindrome_has_map(item), expected_output[count])
      count += 1
    pass

  def test_fn_check_if_string_one_edit_away(self):
    string_list = [('pale', 'ple'), ('pale', 'pales'), ('pale', 'pele'), ('pole', 'polys'), ('', ''), ('pale', "bae")]
    expected_output = [True, True, True, False, True, False]

    count: int = 0
    for item in string_list:
      self.assertEqual(check_if_string_one_edit_away(item[0], item[1]), expected_output[count])
      count += 1
      break
    pass

  def test_fn_string_compression(self):
    string_list = ["aaabbccaa", "abcde", "", "aaaa", "aabcd"]
    expected_output = ["a3b2c2a2", "abcde", "", "a4", "aabcd"]

    count: int = 0
    for item in string_list:
      self.assertEqual(string_compression(item), expected_output[count])
      count += 1
      break
    pass

  def test_flatten_n_list_2d_array(self):
    input_arr = [[1, 2, 3], [4, 5], [6], [7, 8, 9, 10], []]
    expected_output = [1, 4, 6, 7, 2, 5, 8, 3, 9, 10]

    self.assertEqual(flatten_n_list_2d_array(input_arr), expected_output)
    pass

if __name__ == '__main__':
  unittest.main()

