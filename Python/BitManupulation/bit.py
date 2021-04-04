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


if __name__== '__main__':
  print(update_bits(5, 7, 4, 7))
  print(bin(37))

  print(bin(-1))

  print(convert_real_number_binary(0.72))


