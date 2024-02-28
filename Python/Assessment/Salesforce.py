
# find the triplests from array with some condition
# A < B < C and A + B + C <= K

def combine(input: list, f: int, idx: int, result: list, sum_of_elem, results):
    if len(result) == 3:
        if sum_of_elem <= f:
            results.append(list(result))
        return

    for i in range(idx, len(input)):
        result.append(input[i])
        combine(input, f, i+1, result, sum_of_elem + input[i], results)
        result.pop()

def numberofTriplets(n: list, f: int):
    results = []
    idx = 0

    result = []
    combine(input, f, idx, result, 0, results)

    return results


def findFinalArray(input: list, k: int):
    n = len(input)

    for i in range(k):
        input[i % n] = input[i %n] ^ input[n - (i % n) -1]
        print(input[i])
    pass

input1 = [5, 6, 7, 8]
f = 8
# input1.sort()
# print(numberofTriplets(input1, f))

findFinalArray(input1, 4)

print(input1)
