def radix_sort(arr):
    t = [str(i) for i in arr]
    m = len(max(t, key=len))
    t = [str(i).zfill(m) for i in t]

    index = m - 1
    while index >= 0:
        t.sort(key=lambda t: t[index])
        print([int(i) for i in t]) # only for verbose output
        index -= 1

    for i in range(len(arr)):
        arr[i] = int(t[i])


arr = [45, 4, 313, 999, 1]
print('before:', arr)
radix_sort(arr)
print('after:', arr)
