# from aoc_tools import *
# from collections import Counter
# import sys 
# sys.setrecursionlimit(1000000)
# ans = res = 0

# with open("input.txt") as f:
#     s = f.read().strip()
    
    
# ans = 0 
# left = []    
# right = []

# for l in s.split("\n"):
#     l = nums(l)
#     left.append(l[0]) 
#     right.append(l[l])
    
# # left.sort()    
# # right.sort()

# # ans = sum(abs(l-r) for l, r in zip(left, right))

# right = Counter(right)
# ans = 0 
# for l in left:
#     ans += l* right[l]
    
    
# print_(ans)    


def calculate_total_distance(file_path):
    left, right = [], []

    # Read and parse input
    with open(file_path, 'r') as f:
        for line in f:
            l, r = map(int, line.split())
            left.append(l)
            right.append(r)

    # Sort both lists
    left.sort()
    right.sort()

    # Calculate total distance
    total_distance = sum(abs(l - r) for l, r in zip(left, right))
    
    return total_distance

# Run the function and print the result
file_path = "input.txt"  # Replace with your input file path
result = calculate_total_distance(file_path)
print(result)

