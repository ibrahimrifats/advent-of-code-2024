def is_safe(v):
    # Check if the list is sorted in ascending or descending order
    f = sorted(v)
    r = sorted(v, reverse=True)

    if v != f and v != r:
        return False
    
    # Check the differences between adjacent elements
    for i in range(1, len(v)):
        if not (0 < abs(v[i] - v[i - 1]) <= 3):
            return False
    
    return True

def main():
    ans = 0
    with open("input1.txt") as file:
        for line in file:
            v = list(map(int, line.split()))
            if is_safe(v):
                ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()
