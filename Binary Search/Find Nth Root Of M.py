def NthRoot(n: int, m: int) -> int:
    # Write Your Code Here
    low = 1
    high = m
    while low <= high:
        mid = low + (high - low) // 2
        temp = mid ** n
        if temp == m:
            return mid
        elif temp > m:
            high = mid - 1
        else:
            low = mid + 1
    return -1

