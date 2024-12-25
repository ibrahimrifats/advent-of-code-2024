def prs(data):
    """Parse input data to extract registers and program."""
    r = {'a': 0, 'b': 0, 'c': 0}
    p = []
    
    for line in data.splitlines():
        if "Register" in line:
            rg = line[9].lower()
            r[rg] = int(line.split(": ")[1])
        elif "Program:" in line:
            p = [int(x) for x in line.split(": ")[1].split(",")]
    
    return r['a'], r['b'], r['c'], p

def val(a, b, c, v):
    """Get the value of a register or a literal."""
    vs = {4: a, 5: b, 6: c}
    return vs.get(v, v) if v < 7 else None

def run(a, b, c, i, p):
    """Execute a single operation."""
    o, g = p[i], p[i+1]
    v = val(a, b, c, g)
    
    ops = {
        0: lambda: (None, a // (1 << v), b, c),
        1: lambda: (None, a, b ^ g, c),
        2: lambda: (None, a, v & 7, c),
        3: lambda: (None, a, b, c, g) if a else (None, a, b, c, i + 2),
        4: lambda: (None, a, b ^ c, c),
        5: lambda: (v & 7, a, b, c),
        6: lambda: (None, a, a // (1 << v), c),
        7: lambda: (None, a, b, a // (1 << v))
    }
    
    r = ops[o]()
    return r if len(r) == 5 else (*r, i + 2)

def sim(a, b, c, p):
    """Simulate the program."""
    i, output = 0, []
    while i < len(p) - 1:
        r, a, b, c, i = run(a, b, c, i, p)
        if r is not None:
            output.append(r)
    return output

def main():
    # Read the input file
    with open("input.txt", "r") as f:
        data = f.read()

    # Parse input
    a, b, c, p = prs(data)

    # Simulate the program
    output = sim(a, b, c, p)

    # Print the output sequence
    print("Output:", ",".join(map(str, output)))

if __name__ == "__main__":
    main()
