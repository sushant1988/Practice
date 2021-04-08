''' CTC 5.1
insert M into N from i to j.
'''
def update_bits(N, M, i, j):
  all_ones = ~0

  # create masking of 111100001111
  mask = (all_ones << (j + 1)) | ((1 << i) - 1)

  clear_bit = N & mask
  m_shifted = M << i

  return clear_bit | m_shifted

''' CTC 5.2
'''
def convert_real_number_binary(number: float):
  if number >= 1 or number <= 0:
    return "Error"

  result = "."
  frac: float = 0.5
  while number > 0:
    if len(result) >= 32:
      return "Error"

    if number >= frac:
      result += "1"
      number -= frac
    else:
      result += "0"
    frac /= 2

  return result

''' CTC 5.3 find longest sequence of 1s bit by updating one bit to 1s.
Time Complexity = O(b) b is number of bits untill last 1s
Space: O(1)
'''
def flip_bit(num: int):
  cur_len = 0
  prev_len = 0
  max_len = 1 # can always create 1 length sequence
  while num > 0:
    if num & 1 == 1:
      cur_len += 1
    else:
      prev_len = 0 if num & 2 == 0 else cur_len # if next bit is also 0 then you can't make consequetive 1's
      cur_len = 0

    max_len = max(max_len, cur_len + prev_len + 1)
    num >>= 1

  return max_len

''' CTC 5.4 Get Next bigger number having same number of bits set
flip right most 0 which has trailing 1s and then move all the ones after that postion to all the way right
'''
def get_next_number_bit_set(num: int):
  res = num
  b0 = 0  # number of trailing 0
  b1 = 0  # number of trailing 1
  temp = num

  # trailing 0s
  while temp & 1 == 0 and temp > 0:
    b0 += 1
    temp >>= 1

  # trailing 1s
  while temp & 1 == 1 and temp > 0:
    b1 += 1
    temp >>= 1

  if b0 + b1 > 31 or b0 + b1 == 0:
    return -1

  pos = b0 + b1

  res |= 1 << pos  # flip right most 0 to 1
  res &= ~((1 << pos) -1) # cleared all bits to right of pos
  res != (1 << (b1-1)) -1  # set all the ones to right most bit position

  return res

''' CTC 5.4 Get Prev Number having same number of bits set
flip right most non trailing one to zero
'''
def get_prev_number_bit_set(num: int):
  res = num
  b0 = 0  # number of trailing 0
  b1 = 0  # number of trailing 1
  temp = num

  # trailing 0s
  while temp & 1 == 1 and temp > 0:
    b1 += 1
    temp >>= 1

  # trailing 1s
  while temp & 1 == 0 and temp > 0:
    b1 += 1
    temp >>= 1

  pos = b0 + b1 # position of right most non-trailing one

  res &= ((~0) << (pos + 1)) # clear bits from pos onwards
  mask = (1 << (b1 + 1)) -1 # insert sequence of 1s

  res |= mask << (b0 - 1)   # insert sequence of (zeros - 1) since we have added one at pos

  return res

''' CTC 5.6: number of bits need to flip between one number to other
'''
def bit_swap_required(num1, num2):
  res = 0
  c = num1 ^ num2
  while c != 0:
    c &= (c-1)
    res += 1

  return res



if __name__== '__main__':
  print(update_bits(5, 7, 4, 7))
  print(bin(37))

  print(bin(-1))

  print(convert_real_number_binary(0.72))


