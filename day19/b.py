def prs(d):
    # Split the input into patterns and data strings
    p, ds = d.split("\n\n")
    p = [x.strip() for x in p.split(", ")]  # List of patterns
    ds = [x.strip() for x in ds.splitlines()]  # List of design strings
    return p, ds

def cnt(d, p, m=None):
    # Initialize memoization dictionary if not provided
    if m is None:
        m = {}

    # If the string is empty, it is a valid decomposition (base case)
    if not d:
        return 1

    # Return the cached result if it exists
    if d in m:
        return m[d]

    t = 0
    # Iterate through patterns and check if the string starts with the pattern
    for pat in p:
        if d.startswith(pat):
            # Count the ways to match the remainder of the string
            t += cnt(d[len(pat):], p, m)

    # Memoize the result
    m[d] = t
    return t

def slv2(d):
    # Solve for part 2: count all possible ways to match the designs
    p, ds = prs(d)
    total = 0
    
    # For each design string, calculate the number of ways it can be arranged
    for d in ds:
        total += cnt(d, p)  # Add the count of ways for this design
    
    return total

def read_input_from_file(file_path):
    # Function to read the input data from file
    with open(file_path, 'r') as file:
        return file.read()

if __name__ == "__main__":
    # Read input from 'input.txt' file
    inp = read_input_from_file('input.txt')

    # Part 2
    a2 = slv2(inp)
    print(f"Part 2: {a2}")
