from collections import Counter

def calculate_similarity_score(file_path):
    left, right = [], []

    # Read and parse input
    with open(file_path, 'r') as f:
        for line in f:
            l, r = map(int, line.split())
            left.append(l)
            right.append(r)

    # Count occurrences in the right list
    right_count = Counter(right)

    # Calculate the similarity score
    similarity_score = sum(l * right_count[l] for l in left)
    
    return similarity_score

# Run the function and print the result
file_path = "part_2input.txt"  # Replace with your input file path
result = calculate_similarity_score(file_path)
print(result)
